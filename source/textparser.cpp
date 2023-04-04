#include "textparser.h"
TextParser::TextParser(){
	file_to_open = "";
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
bool TextParser::init(){
	if(!file.is_open()){
		return;
	}
	
	std::string s;
	
	while(file){
		
		getline(file, s);
		std::string word;
		//scanning through the line
		for(int i = 0; i < s.size(); i++){
			
			
			switch(s[i]){
				case ' ':
				//end string 
					
				break;
				default:
					word += s[i];
					
					
			}
		}
		
	}
	
	
	
}

