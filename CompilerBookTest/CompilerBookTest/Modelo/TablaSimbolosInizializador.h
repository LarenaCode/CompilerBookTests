#pragma once
#include <string>
#include "Lexico/Token.h"

class TablaSimbolosInizializador {
public:
	virtual int insertReservedWord(std::string nombre, Enumerados::Token token) = 0;
};