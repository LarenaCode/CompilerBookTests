#pragma once
#include "Token.h"
#include "../TablaSimbolosInizializador.h"

class AnalizadorLexico {
public:
	AnalizadorLexico();
	~AnalizadorLexico();
	void insertReserverdWords(TablaSimbolosInizializador* t);
	Enumerados::Token getNextToken();

};
