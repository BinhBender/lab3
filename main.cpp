#include <iostream>
#include <iomanip>
#include <string>

#include "source/Hashtable.h"
#include "source/Tree.h"
#include "source/textparser.h"


int main(){
	
	std::cout << "Hey user!\nThis program encrypts text into binary code and could see the frequency of each word.\n";
	
	bool keeprunning = true;
	
	
	while(keeprunning){
		
		if(!yesnoloop()) break;
		
		char choice;
		
		std::cout << "1 - Choose a file to encode/decode\n2 - Type a message to encode/decode\n";
		std::cin>>choice
		switch(choice){
			
			case 1:
				
			break;
			case 2:
			
			break;
	}
	
	
	
	
	std::cout << "Goodbye\n";
	return 0;
}


bool yesnoloop(){
	
	char output;
	do{
		
		std::cin >> output;
	}while(output != 'y' || output != 'n')
	
	if(output == 'y') return true;
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
	
	
	
}
