
#pragma once
class HashTable;
//Hash table specific node, this will be used to chain colliding nodes.
class HTNode{
protected:

	char key;
//array
	int* value;

	HTNode* next;

public:
	HTNode();
	HTNode(int*);
	HTNode(int*, char);
	~HTNode();
	
	void SetNext(HTNode*);
	int* GetValue() const;


	friend class HashTable;
};
//This is a personal implementation of a hash table
//It will specifically take in chars to hash, and 
class HashTable{
private:

	
	int maxsize;

	//This table will be storing pointers of HTNodes
	//
	HTNode** table;
	
	//hash function that returns a number from 0 - maxsize
	int hash_code(char);
	
	//A function so that chainning isn't too large
	//maybe somewhere around 4 links per bucket
	void grow_if_neccessary();
	
public:
	HashTable();
	~HashTable();
	

	
	void insert(char);
	void erase(char);
//returns a pointer to the node containing the key
	HTNode* find(char);
	
	int* operator[](char);
	
};
