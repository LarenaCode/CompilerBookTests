#pragma once

#include "Token.h"
#include <string>

class Palabra : public Token
{
public:
	Palabra(std::string value, Enumerados::Token token) : Token(token), _value(value), _id(-1)
	{
	};
	~Palabra() {

	};

	std::string getValue() { return _value; };
	void setId(int id) { _id = id; };
	int getId() { return _id; };

private:
	std::string _value;
	int _id;
};