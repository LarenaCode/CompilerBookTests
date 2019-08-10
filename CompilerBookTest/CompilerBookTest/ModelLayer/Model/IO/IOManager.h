#pragma once

#include <string>
#include <fstream>

class IOManager
{
public:
	IOManager(std::string path);
	~IOManager();
	char getNextChar();
	char getNextInBuffer();
	long long int getPuntero();
	bool setPuntero(long long int puntero);
	char getNextCharInBuffer();
private:
	std::string _path;
	std::string _file;
	long long int _size;
	long long int _puntero;
	long long int _punteroVistazo;
	void igualarPunteros();
};

