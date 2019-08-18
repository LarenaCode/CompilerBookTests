#pragma once

#include "TablaSimbolos.h"
#include "../MapSimbolos.h"



TablaSimbolos::TablaSimbolos()
{
	stackTablas* a = new stackTablas();
	a->nxtNode = nullptr;
	MapSimbolos b;
	a->_NodoSimbolos = b;
}


TablaSimbolos::~TablaSimbolos()
{
}


int TablaSimbolos::insertReservedWord(std::string nombre, Enumerados::Token token){
	return _PalabrasReservadas.insertSymbol(nombre, static_cast<int>(token));
}

int TablaSimbolos::insertSymbol(std::string nombre){
	return _tablasIdentificadores->_NodoSimbolos.insertSymbol(nombre);
}

int TablaSimbolos::getID(std::string simbolo, Enumerados::Token token){
	int a = _PalabrasReservadas.getSymbolId(simbolo);
	if ( a > 0 ) {
		token = static_cast<Enumerados::Token>(a);
		return -2;
	}
	else {
		stackTablas* t = _tablasIdentificadores;
		while ((t != nullptr) | ((a = t->_NodoSimbolos.getSymbolId(simbolo)) > 0))
			t = t->nxtNode;
		if (t == nullptr)
			return -1;
		else
			return a;
	}
}


int TablaSimbolos::pushNewBlock(){
	stackTablas* a = new stackTablas();
	stackTablas* b = _tablasIdentificadores;
	a->nxtNode = b;
	_tablasIdentificadores = a;
	if (_tablasIdentificadores != nullptr) {
		return 0;
	}
	else {
		return -1;
	}
}
	

int TablaSimbolos::deleteLastBlock(){
	if (_tablasIdentificadores->nxtNode == nullptr) {
		return -1;
	}
	else {
		stackTablas* a = _tablasIdentificadores->nxtNode;
		delete _tablasIdentificadores;
		_tablasIdentificadores = a;
		return 0;
	}
}