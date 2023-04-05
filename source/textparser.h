#include <fstream>
#include <string>
#include <cctype>
#include "Tree.h"
#include "Hashtable.h"
#pragma once

class TextParser{
private:
	
	std::ifstream file; 
	std::string file_to_open;
	
	std::ifstream cipherfile;
	

	std::string decodedtext;
	std::string encodedtext;
	
	HashTable ciphers;
	Queue<std::string> list_of_words;
	BinaryTree ciphertree;

	bool isbinary(char);

	void ciphertableinit();
	void ciphertreeinit();
	bool encrypting(std::string);
	bool decrypting(std::string);
	
public:

	void setfile(std::string);
	bool init();
	
	TextParser();
	~TextParser();
};
