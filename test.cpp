#include "source/Hashtable.h"
#include "source/textparser.h"
#include "source/Tree.h"
#include <iostream>
#include <fstream>

int main(){

	BinaryTree bt;
	
	bt.append('a', "0");
	bt.append('b', "1");
	
	bt.append('c', "00");
	
	bt.append('c', "01");
	
	std::cout << bt.find_next();
	
	return 0;
}
