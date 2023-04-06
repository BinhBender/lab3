#include "Hashtable.h"


HashTable::HashTable(){
	//This is an arbitrary number,
	//Making it larger will have less chainning but more memory space
	//Smaller will involve more chaining but more space filled up
	maxsize = 32;
	table = new HTNode*[maxsize]();


}


HashTable::~HashTable(){
	//deletes every node in the table
	//Goes through each index
		//then goes through the chaining of each index
	//then deletes the table itself
	for(int i = 0; i < maxsize; i++){
		HTNode* deleter = table[i];
		while(deleter != nullptr){
			HTNode* holder = deleter;
			
			//moves to the next node before it is destroyed
			deleter = deleter->next;
			
			delete holder;
		}
		
		table[i] = nullptr;
	}
	
	delete[] table;
	table = nullptr;
}	

int HashTable::hash_code(char input){
	
	//uses the ascii table
	int hash = int(input);

	//compression
	hash = hash % maxsize;
	
	//Takes away negative numbers
	if(hash < 0) (hash = -hash);
	
	
	return hash;
}

HTNode* HashTable::insert(char input){
	//find index based on input
	int h = hash_code(input);
	
	//make a traverser pointer
	HTNode* trav = table[h];
	
	//new node to hold data
	HTNode* newnode = new HTNode;
	
	newnode->key = input;
	
	//if the table index is empty
	if(trav == nullptr) 
	{
		table[h] = newnode;
		return newnode;
	}
	//if it is the first one
	if(trav->key == input) {
		delete newnode;
		return trav;
	}
	//if there is a collision
	//start finding the end list and append there
	while(trav->next != nullptr){
		
		//if it already exists, return early
		if(trav->key == input) return trav;
		
		trav = trav->next;
	}
	
	//loop ends when next no longer points to a node
	
	trav->next = newnode;
	
	return newnode;
}

//returns the address to the temp value
//this function is a bit slow because im using find() twice

//does not work yet
std::string* HashTable::operator[](char input){
	
	HTNode* temp = insert(input);
	
	
	return &(temp->value);
}
void HashTable::erase(char input){
	
	int h = hash_code(input);
	HTNode* trav = table[h];
	
	//checks for if the table at h is empty
	if(trav == nullptr) return;
	
	//checks if the first block in the chain is the input or not
	if(trav->key == input) {
		
		//moves the pointer to the next node
		table[h] = trav->next;
		
		//delete old node
		delete trav;
		return;
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
	
	return nullptr;
}



//marked for fixinG
void HashTable::print(){
	for(int i = 0; i < maxsize; i++){
		HTNode* trav = table[i];
		while(trav != nullptr){
			
			std::cout << trav->key << " " << trav->value << " ";
			
			
			trav = trav->next;
		}
		
		
		std::cout << std::endl;
	}
}
