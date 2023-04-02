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
	
	//if there is already an key inside.
	//if(find(input) == nullptr) return;
	
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
	
	
	
	return &(temp->value);
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
	
	return nullptr;
}
std::string HashTable::Number_to_binaryString(int input){
	
	const int bitsize = sizeof(input) * 8;
	
	std::string outputstring = "";
	
	
	for(int i = 0; i < bitsize; i++){
		if((input & 1) == true){
			outputstring += "1";
		}else{
			outputstring += "0";
		}
		
		//(input & 1) ? outputstring.append(1) : outputstring.append(0);
		input = input >> 1;
	}
	
	return outputstring;
}


//marked for fixing
//memory leak
void HashTable::print(){
	for(int i = 0; i < maxsize; i++){
		HTNode* trav = table[i];
		while(trav != nullptr){
			
			std::cout << trav->key << " " << Number_to_binaryString(trav->value) << " ";
			
			
			trav = trav->next;
		}
		
		
		std::cout << std::endl;
	}
}
