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
	
	//Check for if there is no file
	if(!file.is_open()) return false;
	
	//check for if there was a previously opened file
	if(file.is_open()){
		file.close();
	}
	
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

	}
	
}

void TextParser::ciphertreeinit(){
	cipherfile.open("cipher.txt");
	if(!cipherfile.is_open()) return;
	//we know that the text in the cipher file alternates between
	//data and code so we could just flip between there.
	
	while(!cipherfile.eof()){
		std::string path;
		std::string character;
		
		
		cipherfile >> character;
		cipherfile >> path;
		
		
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
			code += " ";
		}
		else {

			code = ciphertable.find(s[i])->value + " ";
		}
	}
	encodedtext = code;
	
	return true;
}

//Scans through each character, if it is has a non-binary character, then it exits
bool TextParser::decryption(std::string s){
	std::string word;
	for(unsigned int i = 0; i < s.size(); i++){
		
		if(s[i] == ' '){
			
			if(s[i + 1]== ' ')
			{
				list_of_words.push(word);
				i++;
			}
			
			//Resets word for the next code.
			word.erase(word.begin(), word.end());
		}else if(isbinary(s[i])){
			word += s[i];
		}else{
			//This means that there is an alphabet char in the string
			
			list_of_words.clear();
			
			return false;
		}
		
	}
	
	while(list_of_words.GetSize() != 0){
		decodedtext += list_of_words.front();
		list_of_words.pop();
	}
	
	
	return true;
}
bool TextParser::init(){
	if(!file.is_open()){
		return false;
	}
	bool encrypting = false;
	std::string s;
	while(file){
		getline(file, s);
		std::string word;
		
		if(!encrypting){
			
			//if the encryption fines
			if(!decryption(s)){
				encrypting = true;
					//reopen the file to restart the process
				file.close();
				file.open(file_to_open);
			}
			
		}
		else{
			encryption(s);
		}
		
	}
	
	
	return true;
}

