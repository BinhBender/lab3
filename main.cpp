#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>

#include "source/Hashtable.h"
#include "source/Tree.h"
#include "source/textparser.h"

bool yesnoloop(char positive, char negative);
void userstringinput();
void choosefile();
std::ofstream Make_New_File();

std::string linebreaker = "\n======= ======= ======= =======\n\n";

int main(){
	
	std::cout << "Hey user!\nThis program encrypts text into binary code and could see the frequency of each word.\n";
	std::cout << "Enter y to continue or n to quit: ";
	bool keeprunning = true;
	
	
	while(keeprunning){
		
		if(!yesnoloop('y','n')) break;
		
		char choice;
		
		do{
			std::cout << "1 - Choose a file to encode/decode\n2 - Type a message to encode/decode\n";
			std::cin >> choice;
			switch(choice){
				
				case '1':
					choosefile();
				break;
				case '2':
					userstringinput();
				break;
				default:
				std::cout << "Invalid input, please use the available options\n";
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
	}while(output != positive && output != negative);
	
	if(output == positive) return true;
	else return false;
	
}
bool runagain(){
	
	std::cout << "Would you like to save it? (y/n)\n";
	return yesnoloop('y', 'n')
	
}
void choosefile(){
	std::string filename;
	
	TextParser tp;
	
	std::cout << "Enter file name that exists in the samplefiles folder \"____.txt\"";
	std::cin >> filename;
	
	if(!tp.setfile("samplefiles/" + filename)){
		std::cout<< "Error, file not found, exiting function\n";
		return;
	}
	std::cout << linebreaker;
	std::cout << "Starting Process\n";
	tp.init();
	std::cout << "Process Ended\n" << linebreaker << linebreaker;
	
	
	std::string output = tp.GetResult();
	
	std::cout << "This is your processed message\n" ;
	std::cout << linebreaker << output << linebreaker;
	

	std::cout << "Would you like to save it?\n";
	if(yesnoloop('y', 'n')){
		std::ofstream newfile = Make_New_File();
		
		newfile << output;
	}
	
	
	
}

std::ofstream Make_New_File(){
	std::ofstream newfile;
	std::cout << "Enter in the name of your new file \"____.txt\"\n";
	std::string newfilename;
	std::cin >> newfilename;
	
	newfile.open(newfilename, std::ofstream::out | std::ofstream::trunc);
	
	
	return newfile;
}



void userstringinput(){
	std::string phrase;
	TextParser tp;
	std::ofstream newfile = Make_New_File();
	
	std::cout<< "Enter the phrase you want to encrypt/decrypt,\nmake sure you use the cipher properly, wrong \ncodes will eject the function\n";
	std::cin.ignore();
	std::getline(std::cin, phrase);
	
	HashTable* table = tp.GetCipherTable();
	BinaryTree* bTree = tp.GetCipherTree();
	bool encrypting = false;
	
	//Checks for a new character not in tree
	for(char c : phrase){
		if(table->find(c) == nullptr && c != ' '){
			
			
			std::string newpath = bTree->find_next();
			//creates a new node where a new path was found
			bTree->append(c, newpath);
			
			table->insert(c)->value = newpath;
			
			
		}
		if(!tp.isbinary(c) || c == ' '){
			encrypting = true;
			break;
		}
		
	}
	
	if(encrypting){
		tp.encryption(phrase);
	}else{
		tp.decryption(phrase);
	}
	
	//Cosmetic
	std::string output = tp.GetResult();
	
		std::cout << "This is your processed message\n" ;
	std::cout << linebreaker << output << linebreaker;
	

	std::cout << "Would you like to save it?\n";
	if(yesnoloop('y', 'n')){
		std::ofstream newfile = Make_New_File();
		
		newfile << output;
	}
	
}
