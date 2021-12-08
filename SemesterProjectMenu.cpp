#include <fstream>
#include <iostream>
#include <vector>

const int FILE_SIZE = 10000;

int main(int argv, char argc[]){
    int basic = 0;
    int data;
    int file;
    int processor = 0;

    std::cout<<"Wav Audio File Menu: Quit = 0, Use a file = 1"<<std::endl;
    
    switch(basic){
        case 0:{
            std::cout<<"Quit"<<std::endl;
            break;
        }
        case 1:{
            std::cout<<"What is the file name? "<<std::endl;
            int file[FILE_SIZE];
            for(int i =0; i < FILE_SIZE; i++)
                file[i] = i;
            break;
        }
        default:
            std::cout<<"File does not exist or is not a wav file."<<std::endl;
            return 0;
    }
    auto metadata = std::data::get_metadata::metadata();
        std::cout<<"Metadata: "<<metadata()<<std::endl;
        std::cout<<"Would you like to use the processors? No = 0, Yes = 1"<<std::endl;
        
        switch(processor){
            case 0:{
                std::cout<<"No"<<std::endl;
                break;
            }
            case 1:{
                std::cout<<"Yes"<<std::endl;
                if(argv != FILE_SIZE + 1){
                   std::cout<<"Error saving file, please try again."<<std::endl;
                   return 0;
                }
                else(){
                    std::cout<<"New filename: "<<std::endl;
                    int file[FILE_SIZE];
                    for(int =0; i < FILE_SIZE; i++)
                        file[i] = i;
                    return 0;
                }
                break;
            }
            default:
                std::cout<<"Error, Please choose again."<<std::endl;
                return 0;
        }
    return 0;
    }
