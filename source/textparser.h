#include <fstream>
#include <string>
#include <cctype>
#include <iostream>
#include "Tree.h"
#include "Hashtable.h"
#pragma once

class TextParser{
private:
	
	std::ifstream file; 
	std::string file_to_open;
	
	std::ifstream cipherfile;
	

	std::string pretext;
	std::string resultingtext;
	
	HashTable ciphertable;
	Queue<std::string> list_of_paths;
	BinaryTree ciphertree;

	
	void ciphertableinit();
	void ciphertreeinit();

	
public:

	bool setfile(std::string);
	bool init();
	
	bool isbinary(char);
	bool encryption(std::string);
	bool decryption(std::string);

	std::string GetResult();
	std::string GetPreText();

	HashTable* GetCipherTable();
	BinaryTree* GetCipherTree();
	
	TextParser();
	~TextParser();
};
