#pragma once
#include "MapSimbolos.h"
#include <map>
#include <string>


MapSimbolos::MapSimbolos() : _count(0)
{
}


MapSimbolos::~MapSimbolos()
{
}

int MapSimbolos::insertSymbol(std::string symbol, int id) {
	if (_Simbolos.find(symbol) == _Simbolos.end) {
		return -1;
	}
	else {
		_Simbolos.insert(std::pair<std::string, int>(symbol, id));
		return 0;
	}
}

int MapSimbolos::getSymbolId(std::string symbol) {
	if (_Simbolos.find(symbol) != _Simbolos.end) {
		return _Simbolos.find(symbol)->second;
	}
	else {
		return -1;
	}
}

int MapSimbolos::insertSymbol(std::string symbol) {
	_count++;
	return insertSymbol(symbol, _count);
}