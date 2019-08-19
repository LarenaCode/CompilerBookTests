#pragma once

#include <string>
#include <fstream>

class IOManager
{
public:
	/*****************************************************************************************
	Constructor de la clase IOManager.

	Si el path no existe entonces se sale del programa por error.
	******************************************************************************************/
	IOManager(std::string path);
	~IOManager();

	/***************************************************************************************
	Obtiene el caracter al que apunta el puntero actualmente.

	Devuelve el caracter, o bien NULL (0) si se llegó al final del archivo.
	Iguala los punteros.
	****************************************************************************************/
	long long int getPuntero();

	/****************************************************************************************
	Obtiene el siguiente caracter al que apunta el puntero que simula tener un buffer.

	Devuelve el caracter o bien NULL (0) si se ha llegado al final del archivo.
	****************************************************************************************/
	char getNext();

	/*********************************************************************************************
	Obtiene el siguiente símbolo del buffer.

	Devuelve NULL (#0) si se ha llegado al final del lexema o EoF.
	**********************************************************************************************/
	char seeNext();

	/****************************************************************************************
	Retorna el último char leido.
	****************************************************************************************/
	char getLastChar() { return _preanalisis; };
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
	char _preanalisis;
};

