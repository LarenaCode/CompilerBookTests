#pragma once

#include <string>
#include <fstream>

class IOManager
{
public:
	IOManager(std::string path);
	~IOManager();
	long long int getPuntero();
	char getNext();
	char seeNext();
private:
	std::string _path;
	std::string _file;
	long long int _size;
	long long int _puntero;
	long long int _punteroVistazo;
	void igualarPunteros();
	char getNextChar();
	char getNextInBuffer();
	bool setPuntero(long long int puntero);
	char getNextCharInBuffer();
};

