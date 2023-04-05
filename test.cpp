#include "source/Hashtable.h"
//#include "source/textparser.h"
#include <iostream>
#include <fstream>

int main(){


	std::ifstream file("cipher.txt");
	
	while(file){
		std::string a;
		std::string b;
		
		file >> a;
		file >> b;
		std::cout << a << " " << b << std::endl;
		
	}
	
	
	return 0;
}
