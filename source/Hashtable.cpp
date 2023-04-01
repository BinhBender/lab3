#include "Hashtable.h"


HashTable::HashTable(){
	//This is an arbitrary number,
	//Making it larger will have less chainning but more memory space
	//Smaller will involve more chaining but more space filled up
	maxsize = 32;
	table = new HTNode*[maxsize];
		
	table = {nullptr};



}


HashTable::~HashTable(){
	//deallocate table
	delete table;
}	

int HashTable::hash_code(char input){
	
	int hash = int(input);

	//compression
	hash = hash % maxsize;
	
	//Takes away negative numbers
	if(hash < 0) (hash = -hash);
	
	
	return hash;
}
void HashTable::insert(char input){
	//find index based on input
	int h = hash_code(input);
	
	//make a traverser pointer
	HTNode* trav = table[h];
	
	//new node to hold data
	HTNode* newnode = new HTNode();
	
	
	newnode->key = input;
	
	//if the table index is empty
	if(trav == nullptr) 
	{
		table[h] = newnode;
		return;
	}
	
/************************************/

	//if there is a collision
	//start finding the end list and append there
	//This simply just moves to the next one
	while(trav->next != nullptr){
		trav = trav->next;
	}

	trav->next = newnode;
	
	
}

//returns the address to the temp value

	//this function is a bit slow because im using find() twice
int* HashTable::operator[](char input){
	
	HTNode* temp = find(input);
	
	//if it doesn't exist, add the key
	//then find it again
	if(temp == nullptr){
		insert(input);
		temp = find(input);
	}
	
	
	
	return temp->value;
}
void HashTable::erase(char input){
	int h = hash_code(input);
	HTNode* trav = table[h];
	
	//checks for if the table at h is empty
	if(trav == nullptr) return;
	//checks if the first block in the chain is empty or not
	if(trav->key == input) {
		table[h] = trav->next;
	}
	
	
	while(trav->next != nullptr){
		if(trav->key == input){
			HTNode *holder = trav->next->next;
			
			trav->next = holder;
			//we don't need to delete the node
			//since it already deletes itself.
		}
		
	}
	
}
HTNode* HashTable::find(char input){
	
	int hash = hash_code(input);
	HTNode* trav = table[hash];
	while(trav != nullptr){
		if(trav->key == input){
			//if it finds the value before it reaches the end
			//early return the address
			return trav;
		}else{
			//If it hasn't found the value, go to the next node
			trav = trav->next;
		}
	}
	//if it had been exhausted, then trav is nullptr
	
	trav = nullptr;
	return trav;
}
