#include <iostream>
#include <fstream>
#ifndef endl
#define endl "\n"
#endif

#define wav_echo(filin, fileout, echo_rate)\
char temp;\
char ch[echo_rate], ch2[echo_rate];\
int i, j;\
	for(i=0; i<echo_rate; i++)\
		ch2[i] = 0;\
\
while(!filin.eof())\
{\
	for(i=0; i<echo_rate && !filin.eof(); i++)\
	filin.read((char*)&ch[i], sizeof(char));\
	for(i=0; i<echo_rate; i++)\
	{\
		temp = ch[i];\
		ch[i] += ch2[i];\
		fileout.write((char*)&ch[i], sizeof(char));\
		ch2[i] = temp;\
	}\
}

using namespace std;

struct WAV_HEADER
{
	char chunkId[4];
	int chunkSize;
	char format[4];
	char subChunkFmt[4];
	int subChunkFmtSize;
	short int audioFormat;
	short int numChannels;

	int sampleRate;
	int byteRate;
	short int blockAlign;
	short int bitsPerSample;

	char chunkData[4];
	int subChunkDataSize;
};

int main()
{
	fstream filin("yes-8-bit-mono.wav", ios::in|ios::binary);
	fstream fileout("yes-8-bit-mono.wav", ios::out|ios::binary);

	WAV_HEADER wav;

	filin.read((char*)&wav, sizeof(wav));

	cout<<wav.byteRate
	    <<endl<<wav.chunkSize
	    <<endl<<wav.sampleRate
	    <<endl<<wav.subChunkDataSize
	    <<endl<<wav.subChunkFmtSize
	    <<endl<<wav.chunkData
	    <<endl<<wav.chunkId
	    <<endl<<wav.format
	    <<endl<<wav.subChunkFmt
	    <<endl<<wav.audioFormat
	    <<endl<<wav.audioFormat
	    <<endl<<wav.bitsPerSample
	    <<endl<<wav.blockAlign
	    <<endl<<wav.numChannels
	    <<endl<<endl<<sizeof(wav);

fileout.write((char*)&wav, sizeof(wav));
wav_echo(filin, fileout, 10000)
filin.close();
fileout.close();

return 0;
}
