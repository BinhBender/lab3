#include "textparser.h"
TextParser::TextParser(){
	file_to_open = "";
	ciphertableinit();
	ciphertreeinit();

}

TextParser::~TextParser(){
	file.close();
}


bool TextParser::setfile(std::string input){
	file_to_open = input;
	/*
	//Check for if there is no file
	if(!file.is_open()) return false;
	
	//check for if there was a previously opened file
	if(file.is_open()){
		file.close();
	}
	*/
	file.open(file_to_open);
	
	
	return true;
}
bool TextParser::isbinary(char input){
	if(input == '0' || input == '1'){
		return true;
	}
	return false;
}


void TextParser::ciphertableinit(){
	if(cipherfile.is_open()){
		cipherfile.close();
	}
	cipherfile.open("cipher.txt");
	if(!cipherfile.is_open()) return;
	
	
	//we know that the text in the cipher file alternates between
	//data and code so we could just flip between there.
	
	std::string holder;
	while(cipherfile){
		
		std::string character;
		std::string path;
		cipherfile >> character;
		cipherfile >> path;
		
		
		ciphertable.insert(character.front());
		ciphertable.find(character.front())->value = path;
		
		
		//HTNode* a = ciphertable.find(character.front());
		//std::cout << a->key << " " << a->value << std::endl;

	}
	
}

void TextParser::ciphertreeinit(){
	if(cipherfile.is_open()){
		cipherfile.close();
	}
	cipherfile.open("cipher.txt");
	if(!cipherfile.is_open()) return;
	//we know that the text in the cipher file alternates between
	//data and code so we could just flip between there.
	
	while(!cipherfile.eof()){
		std::string path;
		std::string character;
		
		
		cipherfile >> character;
		cipherfile >> path;
		
		
		//std::cout << character << " " << path << std::endl;
		ciphertree.append(character.front(), path);

	}
}
HashTable* TextParser::GetCipherTable(){
		return &ciphertable;
}
BinaryTree* TextParser::GetCipherTree(){
		return &ciphertree;
}
bool TextParser::encryption(std::string s){
	std::string code;
	
	//iterate through the input
	for(unsigned int i = 0; i < s.size(); i++){
		if(s[i] == ' ') {
			code += ' ';
		}
		else {

			code += ciphertable.find(s[i])->value + " ";
		}
	}
	resultingtext = code;
	
	return true;
}
std::string TextParser::GetResult(){
		return resultingtext;
}
//Scans through each character, if it is has a non-binary character, then it exits
bool TextParser::decryption(std::string s){
	std::string path;
	
	//loop through the string
	for(unsigned int i = 0; i < s.size(); i++){
		
		//this condition checks for if the end of the char
		if(s[i] == ' '){
			
			//Resets word for the next code.
			list_of_paths.push(path);
			
			//This means that the word is finished
			if(s[i + 1]== ' ')
			{
				list_of_paths.push(" ");
				i++;
			}
			
			
			path.erase(path.begin(), path.end());
		}else if(s[i] == '\n')
		{
			list_of_paths.push("\n");
		}
		else{
			path += s[i];
		}
		
		
	}
	
	//Iterate through the queue of "paths"
	while(list_of_paths.GetSize() != 0){
		std::string path = list_of_paths.front();
		
		//if the paths have these chars, then it adds it to the 
		//output string which is resultingtext
		if(path == " " || path == "\n"){
			resultingtext.append(path);
		}else{
			
			//Get the data from the tree
			BTNode* walker = ciphertree.Traverse(path);
			//std::cout << walker->data << " " ;
			resultingtext += walker->data;
		}
		
		list_of_paths.pop();
	}
	
	
	return true;
}
bool TextParser::init(){
	if(!file.is_open()){
		std::cout <<"File Not open\n";
		return false;
	}
	//bool encrypting = false;
	std::string s;
	while(file){
		getline(file, s);
		std::string word;
		
		
		bool encrypting = false;
		std::cout << "Starting new line:\nChecking for alphabetical letters...\n";
		
		//Detects whether or not we do encryption
		for(char c : s){
			if(!isbinary(c) || c == ' '){
				encrypting = true;
				break;
			}
		}
		
		if(encrypting){
			std::cout << "Founded lexiconic letters, beginning encryption\n";
			encryption(s);
		}
		else{
			std::cout << "No letters founded, beginning decryption\n";
			
			decryption(s);
		}
	}
	
	file.close();
	return true;
}

