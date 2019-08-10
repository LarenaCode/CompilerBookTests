#include "Token.h"



Token::Token(char *valor, int codigo) : _valor(valor), _codigo(codigo)
{
}


Token::~Token()
{
}


char* Token::getValor() {
	return _valor;
}

int Token::getCodigo() {
	return _codigo;
}