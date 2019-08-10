#pragma once

#include <string>
#include <fstream>

class IOManager
{
public:
	IOManager(std::string path);
	~IOManager();
	char getNextChar();
	char* getBuffer();

private:
	std::string _path;
	std::ifstream _file;
};

