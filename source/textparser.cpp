#include "textparser.h"
TextParser::TextParser(){
	file_to_open = "";
	cipherinit();
	
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
		
		ciphers.insert(character);
		ciphers.find(character)->value = path;

	}
	
}

void TextParser::ciphertreeinit(){
	cipherfile.open("cipher.txt");
	if(!cipherfile.is_open()) return;
	unsigned int toggle = 1;
	//we know that the text in the cipher file alternates between
	//data and code so we could just flip between there.
	
	while(cipherfile){
		std::string path;
		std::string character;
		
		
		cipherfile >> character;
		cipherfile >> path;
		
		
		ciphers.append(*character.begin(), path);

	}
}


bool TextParser::encrypting(std::string s){
	std::string code;
	for(unsigned int i = 0; i < s.size(); i++){
		if(s[i] == ' ') {
			code += " ";
		}
		else {
			if(ciphers.find(s[i]) == nullptr) return false;
			
			code = ciphers.find(s[i])->value + " ";
		}
	}
	encodedtext = code;
	
	return true;
}

//Scans through each character, if it is has a non-binary character, then it exits
bool TextParser::decrypting(std::string s){
	std::string word;
	for(unsigned int i = 0; i < s.size(); i++){
		
		if(isbinary(s[i])) return false;
		if(s[i] == ' '){
			
			if(s[i + 1]== ' ')
			{
				list_of_words.push(word);
			}
			//Resets word for the next code.
			word.erase(word.begin(), word.end());
		}else{
			word += s[i];
		}
		
	}
	
	return true;
}
bool TextParser::init(){
	if(!file.is_open()){
		return false;
	}
	
	std::string s;
	while(file){
		getline(file, s);
		std::string word;

	}
	
	
	return true;
}

