#include "pch.h"
#include "IOManager.h"
#include "ConstantesIO.h"
#include "ErrorMsg.cpp";
#include <string>
#include <fstream>

IOManager::IOManager(std::string path) : _file(path, std::ios::binary)
{
	if (_file.fail) {
		FatalError("Código origen perdido");
	}
}


IOManager::~IOManager()
{
}

/***************************************************************************************
*
****************************************************************************************/
char IOManager::getNextChar() {
	char oPut = NULL;
}


char* IOManager::getBuffer() {

}