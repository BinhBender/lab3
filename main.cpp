#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>

#include "source/Hashtable.h"
#include "source/Tree.h"
#include "source/textparser.h"

bool yesnoloop(char positive, char negative);
void userstringinput(TextParser& tp);
void choosefile(TextParser& tp);
std::ofstream Make_New_File();

std::string linebreaker = "\n======= ======= ======= =======\n\n";

int main(){
	
	std::cout << "Hey user!\nThis program encrypts text into binary code and could see the frequency of each word.\n";
	std::cout << "Enter y to continue or n to quit: ";
	bool keeprunning = true;
	
	TextParser tp;
	while(keeprunning){
		
		if(!yesnoloop('y','n')) break;
		
		char choice;
		do{
			std::cout << "\n1 - Choose a file to encode/decode\n\n2 - Type a message in the console to encode/decode\n";
			std::cin >> choice;
			switch(choice){
				case '1':
					choosefile(tp);
				break;
				
				case '2':
					userstringinput(tp);
				break;
				default:
				std::cout << "Invalid input, please use the available options\n";
				break;
			}
		}while(choice != '1' && choice != '2');
		
		std::cout << "\nDo you want to continue? (y/n): ";
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
	
	std::cout << "Would you like to run it? (y/n)\n";
	return yesnoloop('y', 'n');
	
}
void choosefile(TextParser& tp){
	std::string filename;

	
	std::cout << "\nEnter file name that exists in the samplefiles folder \"____\"\n";
	std::cin >> filename;
	
	if(!tp.setfile("samplefiles/" + filename + ".txt")){
		std::cout<< "Error, file not found, exiting function\n";
		return;
	}
	std::cout << linebreaker;
	std::cout << "Starting Process\n";
	tp.init();
	std::cout << "Process Ended\n" << linebreaker;
	
	
	std::string output = tp.GetResult();
	std::string pretext = tp.GetPreText();
	std::cout << "This is your processed message\n" ;
	std::cout << linebreaker << output << linebreaker;
	

	std::cout << "Would you like to save it? (y/n)\n";
	if(yesnoloop('y', 'n')){
		std::ofstream newfile = Make_New_File();
		
		newfile << pretext;
		newfile << "\n\n\n" + output;
	}
	
	
	
}

std::ofstream Make_New_File(){
	std::ofstream newfile;
	std::cout << "Enter in the name of your new file \"____\"\n";
	std::string newfilename;
	std::cin >> newfilename;
	
	newfile.open("samplefiles/" + newfilename + ".txt", std::ofstream::out | std::ofstream::trunc);
	
	
	return newfile;
}



void userstringinput(TextParser& tp){

	std::string phrase;

	
	std::cout<< "\nEnter the phrase you want to encrypt/decrypt\n>>";
	std::cin.ignore();
	std::getline(std::cin, phrase);
	
	HashTable* table = tp.GetCipherTable();
	BinaryTree* bTree = tp.GetCipherTree();
	bool encrypting = false;
	
	//Checks for a new character not in table
	for(char c : phrase){
		if(table->find(c) == nullptr && c != ' '){
			//If there is not a new character, input it.
			tp.add_to_table_and_tree(c);
		}
		if(!tp.isbinary(c) || c != ' '){
			encrypting = true;
		}
		
	}
	
	if(encrypting){
		tp.encryption(phrase);
	}else{
		tp.decryption(phrase);
	}
	//Cosmetic
	std::string output = tp.GetResult();
	std::string pretext = tp.GetPreText();
	
		std::cout << "This is your processed message\n" ;
	std::cout << linebreaker << output << linebreaker;
	

	std::cout << "Would you like to save it? (y/n)\n";
	if(yesnoloop('y', 'n')){
		std::ofstream newfile = Make_New_File();
		
		newfile << pretext;
		newfile << "\n\n\n" + output;
	}
}
