#include "IOManager.h"
#include "ConstantesIO.h"

#include <string>
#include <fstream>

/*****************************************************************************************
Constructor de la clase IOManager.

Si el path no existe entonces se sale del programa por error.
******************************************************************************************/
IOManager::IOManager(std::string path) : _path(path)
{
	std::ifstream file(_path, std::ios::binary);
	if (file.fail()) {
		//FatalError("Código origen perdido",CODIGO_ERROR_ARCHIVO_INEXISTENTE);
		exit(256);
	}
	file.seekg(0, std::ios::end);
	_size = file.tellg();
	_file = new char[_size];
	file.seekg(0, std::ios::beg);
	file.read(&_file[0], _size);
	_puntero = 0;
	igualarPunteros();
}


IOManager::~IOManager()
{
}

/***************************************************************************************
Obtiene el caracter al que apunta el puntero actualmente.

Devuelve el caracter, o bien NULL (0) si se llegó al final del archivo.
Iguala los punteros.
****************************************************************************************/
char IOManager::getNextChar() {
	if (_puntero > _size)
		return NULL;
	char salida = _file[_puntero];
	_puntero++;
	igualarPunteros();
	return salida;
}

/****************************************************************************************
Obtiene el siguiente caracter al que apunta el puntero que simula tener un buffer.

Devuelve el caracter o bien NULL (0) si se ha llegado al final del archivo.
****************************************************************************************/
char IOManager::getNextInBuffer() {
	if (++_punteroVistazo > _size)
		return NULL;
	return _file[_punteroVistazo];
}

/****************************************************************************************
Obtiene el valor actual del puntero
*****************************************************************************************/
long long int IOManager::getPuntero() {
	return _puntero;
}

/*****************************************************************************************
Setter del puntero principal.

Devuelve true si la operación fue exitosa, o bien, false si no lo fué.
******************************************************************************************/
bool IOManager::setPuntero(long long int puntero) {
	if (puntero > _size)
		return false;
	_puntero = puntero;
	igualarPunteros();
	return true;
}



/******************************************************************************************
Iguala los punteros, se agrega esta función ya que el proceso se repite varias veces.
******************************************************************************************/
void IOManager::igualarPunteros() {
	_punteroVistazo = _puntero;
}


/******************************************************************************************
Obtiene el siguiente caracter del que apunta el puntero del buffer en este momento.
*******************************************************************************************/
char IOManager::getNextCharInBuffer() {
	if (++_punteroVistazo > _size)
		return NULL;
	setPuntero(_punteroVistazo);
	return getNextChar();
}

/*******************************************************************************************
Obtiene el siguiente símbolo válido del código origen.

Devuelve NULL (#0) si se llegó al EoF.
********************************************************************************************/
char IOManager::getNext() {
	char salida;
	do {
		salida = getNextChar();
	} while (salida == ' ' || salida == '\t');
	return salida;
}

/*********************************************************************************************
Obtiene el siguiente símbolo del buffer.

Devuelve NULL (#0) si se ha llegado al final del lexema o EoF.
**********************************************************************************************/
char IOManager::seeNext() {
	char salida = getNextInBuffer();
	if (salida == ' ' || salida == '\t')
		return NULL;
	return salida;
}