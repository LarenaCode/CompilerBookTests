#include "../../pch.h"
#include "AnalizadorLexico.h"



AnalizadorLexico::AnalizadorLexico()
{
}


AnalizadorLexico::~AnalizadorLexico()
{
}


Token AnalizadorLexico::getNextToken() {
	char c = 'p';
	Token a(&(c),1);
	return a;
}