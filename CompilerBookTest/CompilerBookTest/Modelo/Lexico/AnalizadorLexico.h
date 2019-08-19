#pragma once
#include "Token.h"
#include "../TablaSimbolosInizializador.h"
#include <string>
#include "../../IOManager.h"

class AnalizadorLexico {
public:
	AnalizadorLexico(std::string file);
	~AnalizadorLexico();
	Token getNextToken();

private:
	IOManager _iManager;
	char _vistazo;
	char vistazo() {
		_vistazo = _iManager.seeNext();
		return _vistazo;
	}
};
