#include <fstream>
#include <string>
#pragma once

class TextParser{
private:
	
	std::ifstream file; 
	
	
public:

	void setfile(std::string);
	void init();
};
