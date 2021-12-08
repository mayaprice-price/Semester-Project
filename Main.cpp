//Main.cpp was created by Gregory Jordan//
#include <iostream>
#include <fstream>
#include "AudioFile.h"
#include <string>

int main() {

    //Class for AudioFile
    AudioFile<double> audioFile;

    //Welcome UI and file loader
    std::string fileName;
    std::cout << "Welcome to the Gregs Audio File Loader \n Type the name of the file you want to load" << std::endl; 
    std::cin >> fileName;

    //File Checker
    bool isWav;
    if (!fileName.find (".wav"))
        {
            std::cerr << "Please input a .wav file\n";
        }

    //Loading the file
    audioFile.load (fileName);

    //Metadata Extraction
    int sampleRate = audioFile.getSampleRate();
    bool isStereo = audioFile.isStereo();
    bool isMono = audioFile.isMono();
    int bitsPerSample = audioFile.getBitDepth();

    //Metadata Display
    std::cout << "The filename is " << fileName << std::endl;
    std::cout << "Here is the file Metadata" << std::endl;
    std::cout << "The Sample Rate is " << sampleRate << std::endl;
    if (isMono == true)
        {
            std::cout << "The audio file is Mono" << std::endl;
        }
    if (isStereo == true)
        {
            std::cout << "The audio file is Stereo" << std::endl;
        }

    std::cout << "The bits per sample are " << bitsPerSample << std::endl;


}











