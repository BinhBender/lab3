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
	
	if(file.is_open()){
		file.close();
	}

	file.open(file_to_open);
	//Check for if there is no file
	if(!file.is_open()) return false;
	
	return true;
}
bool TextParser::isbinary(char input){
	if(input == '0' || input == '1'){
		return true;
	}
	return false;
}


void TextParser::ciphertableinit(){
	
	//This is so that we reset the file stream
	//Not a good way to do so

	//Also not neccessary since this is called before the tree but why not
	if(cipherfile.is_open()){
		cipherfile.close();
	}
	cipherfile.open("cipher.txt");

	//If we can't find the file, exit function
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

bool TextParser::encryption(std::string text_to_encrypt){
	std::string code;
	//iterate through the input
	for(unsigned int i = 0; i < text_to_encrypt.size(); i++){
		if(text_to_encrypt[i] == ' ') {
			code += ' ';
		}
		else{
			code += ciphertable.find(text_to_encrypt[i])->value + " ";
		}
	}
	resultingtext += code;
	return true;
}

//Scans through each character, if it is has a non-binary character, then it exits
bool TextParser::decryption(std::string text_to_decrypt){
	std::string path;
	
	//Iterate through the queue of "paths"
	
	//loop through the string
	for(unsigned int i = 0; i < text_to_decrypt.size(); i++){
		
		//End of a code string
		if(text_to_decrypt[i] == ' '){
			
			//Resets word for the next code.
			list_of_paths.push(path);
			
			//A double space would mean that its the end of the word
			if(text_to_decrypt[i + 1]== ' ')
			{
				list_of_paths.push(" ");
				i++;
			}
			
			//erases the entire word
			path = "";
		}
		else{
			path += text_to_decrypt[i];
		}
	}
	//Now we push all of the words in the queue to a string
	while(list_of_paths.GetSize() != 0){
		std::string path = list_of_paths.front();
		
		//if the paths have these chars, then it adds it to the 
		//output string which is resultingtext
		if(path == " " || path == "\n"){ //The queue will contain spaces which are not usable with the tree traversal

			resultingtext.append(path);
		}else{
			
			//Get the data from the tree
			BTNode* walker = ciphertree.Traverse(path);
			//std::cout << path << " " << walker->data << " " ;
			resultingtext += walker->data;
		}
		
		//Get the next item in the queue
		list_of_paths.pop();
	}
	
	
	return true;
}


void TextParser::add_to_table_and_tree(char value){
	std::cout << "created" << value <<std::endl;
	std::string path = ciphertree.find_next();
	//creates a new node where a new path was found
	ciphertree.append(value, path);
	ciphertable.insert(value)->value = path;
}
std::string TextParser::GetResult(){
	return resultingtext;
}
bool TextParser::init(){
	//Reset the output results of the text
	resultingtext = pretext = "";

	//Check for if the file is open or not
	if(!file.is_open()){
		std::cout <<"File Not open\n";
		return false;
	}
	
	std::string line_of_text;
	
	while(file){
		
		//
		std::getline(file, line_of_text);
		bool encrypting = false;
		
		
		std::cout << "Starting new line:\nChecking for alphabetical letters...\n";
		//Scan for if there is an alphabetical character or not
		for(int i = 0; i < line_of_text.size(); i++){
		//Decides whether or not we do encryption/decryption
			
			//If the string has alphabetical characters, 
			//then we assume its not an encrypted text
			if(!isbinary(line_of_text[i]) && line_of_text[i] != ' '){
				encrypting = true;
			}
			//If there is a new character, add it to the tree/table
			if(ciphertable.find(line_of_text[i]) == nullptr && line_of_text[i] != ' '){
					
				add_to_table_and_tree(line_of_text[i]);
			}
		}
		if(encrypting){
			std::cout << "Founded lexiconic letters, beginning encryption\n";
			pretext += line_of_text;
			encryption(line_of_text);
		}
		else{
			std::cout << "No letters founded, beginning decryption\n";
			pretext += line_of_text;
			decryption(line_of_text);
		}
	}
	file.close();
	return true;
}

std::string TextParser::GetPreText(){
	return pretext;
}
