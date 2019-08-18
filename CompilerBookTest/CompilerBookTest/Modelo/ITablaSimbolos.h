#pragma once
#include <string>
#include "Lexico/Token.h"

class ITablaSimbolos {
public:
	virtual int insertSymbol(std::string nombre) = 0;
	virtual int getID(std::string simbolo, Enumerados::Token token) = 0;
	virtual int pushNewBlock() = 0;
	virtual int deleteLastBlock() = 0;
};