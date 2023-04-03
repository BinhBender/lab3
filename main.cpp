#include <iostream>
#include "source/Hashtable.h"
int main(){
	
	HashTable ht;
	
	ht.insert('a');
	
	ht.find('a')->value = 0;
	
	ht.print();
	return 0;
}
