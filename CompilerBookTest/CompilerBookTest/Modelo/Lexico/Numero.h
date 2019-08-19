#pragma once

#include "Token.h"

class Numero : public Token
{
public:
	Numero(int value, Enumerados::Token token) : Token(token), _value(value)
	{
	};
	~Numero() {

	};

	int getValue() { return _value; };

private:
	int _value;
};