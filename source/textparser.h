#include <fstream>
#include <string>
#include <cctype>
#pragma once

class TextParser{
private:
	
	std::ifstream file; 
	std::string file_to_open;
	bool isbinary(char);
	
public:

	void setfile(std::string);
	bool init();
	
	TextParser();
	~TextParser();
};
