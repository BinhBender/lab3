#include "source/Hashtable.h"
//#include "source/textparser.h"
#include <iostream>

int main(){


	HashTable ht;
	
	*ht['h'] = "10";
	
	ht.insert('a');
	ht.find('a')->value = "balls";
	std::cout << *(ht['h']) << std::endl;
	
	std::cout << ht.find('a')->value;
	
	std::cout << ht.insert('a');
	
	
	return 0;
}
