#include "textparser.h"
TextParser::TextParser(){
	file_to_open = "";
	cipherinit();
	
}

TextParser::~TextParser(){
	file.close();
}


void TextParser::setfile(std::string input){
	file_to_open = input;
	
	
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
	unsigned int toggle = 1;
	//we know that the text in the cipher file alternates between
	//data and code so we could just flip between there.
	
	std::string holder;
	while(cipherfile){
		std::string s;
		
		cipherfile >> s;
		
		if(toggle % 2 == 1){
			ciphers.insert(*s.begin());
			holder = s;
		}
		else{
			ciphers.find(*holder.begin())->value == s;
		}
	}
	
}

void TextParser::ciphertreeinit(){
	
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

bool TextParser::decrypting(std::string s){
	std::string word;
	for(unsigned int i = 0; i < s.size(); i++){
		
		if(isalpha(s[i])) return false;
		if(s[i] == ' '){
			word = 
			if(s[i + 1]== ' ')
			{
				list_of_words.push(word);
			}
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

