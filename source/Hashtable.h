#include <iostream>
#include <string>
#pragma once
class HashTable;
//Hash table specific node, this will be used to chain colliding nodes.
struct HTNode{
	char key = 0;

	std::string value = "";

	HTNode* next = nullptr;

};
//This is a personal implementation of a hash table
//It will specifically take in chars to hash, and 
class HashTable{
private:

	//This is the size of the table
	int maxsize;

	//This table will be storing pointers of HTNodes
	HTNode** table;
	

	//hash function that returns a number from 0 - maxsize
	int hash_code(char);
	
	//A function so that chainning isn't too large
	//maybe somewhere around 4 links per bucket 
	void grow_if_neccessary();
	
public:
	HashTable();
	~HashTable();
	

	
	HTNode* insert(char);
	void erase(char);
//returns a pointer to the node containing the key
	HTNode* find(char);
	
	std::string* operator[](char);
	void print();
	
};
