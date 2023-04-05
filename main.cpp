#include <iostream>
#include <iomanip>
#include <string>

#include "source/Hashtable.h"
#include "source/Tree.h"
#include "source/textparser.h"

bool yesnoloop(char positive, char negative);
void choosefile();
void stringinput();

int main(){
	
	std::cout << "Hey user!\nThis program encrypts text into binary code and could see the frequency of each word.\n";
	
	bool keeprunning = true;
	
	
	while(keeprunning){
		
		if(!yesnoloop('y','n')) break;
		
		char choice;
		
		do{
			std::cout << "1 - Choose a file to encode/decode\n2 - Type a message to encode/decode\n";
			std::cin>>choice;
			switch(choice){
				
				case 1:
					choosefile();
				break;
				case 2:
					stringinput();
				break;
				default:
				
				break;
			}
		}while(choice != '1' && choice != '2');
	}
	
	
	
	
	std::cout << "Goodbye\n";
	return 0;
}


bool yesnoloop(char positive, char negative){
	
	char output;
	do{
		
		std::cin >> output;
	}while(output != positive || output != negative);
	
	if(output == positive) return true;
	else return false;
	
}

void choosefile(){
	std::string filename;
	
	TextParser tp;
	
	std::cout << "Enter file name";
	std::cin >> filename;
	
	if(!tp.setfile(filename)){
		std::cout<< "Error, file not found, exiting function\n";
		return;
	}
	
	tp.init();
	
	std::cout << tp.GetResult();
	
	
	
}

void stringinput(){
	std::string phrase;
	TextParser tp;
	std::cout << "Enter the phrase you want to encrypt/decrypt,\nmake sure you use the cipher properly, wrong \ncodes will eject the function\n";
	
	std::cin >> phrase;
	
	if(tp.encryption(phrase)){
		
	}
}
