#pragma once

#include "Token.h"
#include <string>

class Operador : public Token
{
public:
	Operador(std::string value, Enumerados::Token token) : Token(token), _value(value)
	{
	};
	~Operador() {

	};

	std::string getValue() { return _value; };

private:
	std::string _value;
};