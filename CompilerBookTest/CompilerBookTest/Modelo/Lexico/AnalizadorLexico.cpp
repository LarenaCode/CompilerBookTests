#pragma once
#include "AnalizadorLexico.h"
#include "Token.h"
#include "../TablaSimbolosInizializador.h"
#include <string>
#include "../../IOManager.h"
#include "Numero.h"
#include "Operador.h"
#include "Palabra.h"


bool isLetDigUnG(char c) {
	return ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')) || (c == '_') || ((c >= '0') && (c <= '9'));
}

bool isNum(char c) {
	return (c >= '0') && (c <= '9');
}

AnalizadorLexico::AnalizadorLexico(std::string file) : _iManager(file)
{
}


AnalizadorLexico::~AnalizadorLexico()
{
}
/*******************************************************************************************
Falta la implementación del operador de acceso al miembro a.*.
Falta la implementación del operador de acceso al miembro &a.
********************************************************************************************/
Token AnalizadorLexico::getNextToken() {
	char cActual = _iManager.getLastChar();
	int estado = 0;
	while (cActual != 0) {
		switch (estado) {
		/*
			Estado incial.
		*/
		case 0:
			switch (cActual) {
			case '=':
				estado = 1;
				break;
			case '+':
				estado = 3;
				break;
			case '-':
				estado = 6;
				break;
			case '*':
				estado = 11;
				break;
			case '/':
				estado = 13;
				break;
			case '%':
				estado = 15;
				break;
			case '&':
				estado = 17;
				break;
			case '|':
				estado = 20;
				break;
			case '^':
				estado = 23;
				break;
			case '<':
				estado = 25;
				break;
			case '>':
				estado = 29;
				break;
			case '!':
				estado = 34;
				break;
			case '.':
				estado = 36;
				break;
			default:
				if (((cActual >= 'a') && (cActual <= 'z')) || ((cActual >= 'A') && (cActual <= 'Z')) || (cActual == '_')) {
					estado = 38;
				}
				else {
					if ((cActual >= '0')&(cActual <= '9')) {
						estado = 39;
					}
					else
						estado = 255;
				}
					break;
			}
			break;
		/*
			Operadores: signo =.
		*/
		case 1:
			vistazo();
			if (_vistazo != '=')
				return Operador("=", Enumerados::Token::OP_ASIGN);
			else {
				estado = 2;
				break;
			}
		case 2:
			return Operador("==", Enumerados::Token::OP_LOGICO);

		/*
			Operadores signo +.
		*/
		case 3:
			vistazo();
			switch (_vistazo) {
			case '=':
				estado = 4;
				break;
			case '+':
				estado = 5;
			default:
				return Operador("+", Enumerados::Token::OP_MAT);
			}
		case 4:
			return Operador("+=", Enumerados::Token::OP_ASIGN);
		case 5:
			return Operador("++", Enumerados::Token::OP_ASIGN);
		/*
		Operadores signo -.
		*/
		case 6:
			vistazo();
			switch (_vistazo)
			{
			case '=':
				estado = 7;
				break;
			case '-':
				estado = 8;
				break;
			case '>':
				estado = 9;
				break;
			default:
				return Operador("-", Enumerados::Token::OP_MAT);
			}
		case 7:
			return Operador("-=", Enumerados::Token::OP_ASIGN);
		case 8:
			return Operador("--", Enumerados::Token::OP_ASIGN);
		case 9:
			vistazo();
			if (_vistazo != '*')
				return Operador("->", Enumerados::Token::OP_MEM_ACCESS);
			else {
				estado = 10;
				break;
			}
		case 10:
			return Operador("->*", Enumerados::Token::OP_MEM_ACCESS);
		/*
			Operadores signo *.
		*/
		case 11:
			vistazo();
			switch (_vistazo) {
			case '=':
				estado = 12;
				break;
			default:
				return Operador("*", Enumerados::Token::OP_MAT);
			}
		case 12:
			return Operador("*=", Enumerados::Token::OP_ASIGN);
		case 13:
			vistazo();
			if (_vistazo != '=')
				return Operador("/", Enumerados::Token::OP_MAT);
			else {
				estado = 14;
				break;
			}
		case 14:
			return Operador("/=", Enumerados::Token::OP_ASIGN);
		/*
			Operadores signo %.
		*/
		case 15:
			vistazo();
			if (_vistazo != '=')
				return Operador("%", Enumerados::Token::OP_MAT);
			else {
				estado = 16;
				break;
			}
		case 16:
			return Operador("%=", Enumerados::Token::OP_ASIGN);
		/*
			Operadores signo &.
		*/
		case 17:
			vistazo();
			switch (_vistazo) {
			case '=':
				estado = 18;
				break;
			case '&':
				estado = 19;
				break;
			default:
				return  Operador("&", Enumerados::Token::OP_MAT);
			}
		case 18:
			return Operador("&=", Enumerados::Token::OP_ASIGN);
		case 19:
			return Operador("&&", Enumerados::Token::OP_LOGICO);
		/*
			Operadores signo |.
		*/
		case 20:
			switch (vistazo()) {
			case '=':
				estado = 21;
				break;
			case '|':
				estado = 22;
				break;
			default:
				return  Operador("|", Enumerados::Token::OP_MAT);
			}
		case 21:
			return Operador("|=", Enumerados::Token::OP_ASIGN);
		case 22:
			return Operador("||", Enumerados::Token::OP_LOGICO);
		/*
			Operadores signo ^.
		*/
		case 23:
			if (vistazo() != '=')
				return Operador("^", Enumerados::Token::OP_MAT);
			else {
				estado = 24;
				break;
			}
		case 24:
			return Operador("^=", Enumerados::Token::OP_ASIGN);
		/*
			Operadores signo <.
		*/
		case 25:
			switch (vistazo()) {
			case '=':
				estado = 26;
				break;
			case '<':
				estado = 27;
				break;
			default:
				return Operador("<", Enumerados::Token::OP_LOGICO);
			}
		case 26:
			if (vistazo() != '>')
				return Operador("<=", Enumerados::Token::OP_LOGICO);
			else {
				estado = 33;
				break;
			}
		case 33:
			return Operador("<=>", Enumerados::Token::OP_LOGICO);
		case 27:
			if (vistazo() != '=')
				return Operador("<<", Enumerados::Token::OP_MAT);
			else {
				estado = 28;
				break;
			}
		case 28:
			return Operador("<<=", Enumerados::Token::OP_ASIGN);
		/*
					Operadores signo >.
		*/
		case 29:
			switch (vistazo()) {
			case '=':
				estado = 30;
				break;
			case '>':
				estado = 31;
				break;
			default:
				return Operador(">", Enumerados::Token::OP_LOGICO);
			}
		case 30:
			return Operador(">=", Enumerados::Token::OP_LOGICO);
		case 31:
			if (vistazo() != '=')
				return Operador(">>", Enumerados::Token::OP_MAT);
			else {
				estado = 32;
				break;
			}
		case 32:
			return Operador(">>=", Enumerados::Token::OP_ASIGN);
		/*
			Operadores signo !.
		*/
		case 34:
			if (vistazo() != '=')
				return Operador("!", Enumerados::Token::OP_LOGICO);
			else {
				estado = 35;
				break;
			}
		case 35:
			return Operador("!=", Enumerados::Token::OP_LOGICO);
		/*
			Operadores signo '.' .
		*/
		case 36:
			if (vistazo() != '*')
				return Operador(".", Enumerados::Token::OP_MEM_ACCESS);
			else {
				estado = 37;
				break;
			}
		case 37:
			return Operador(".*", Enumerados::Token::OP_MEM_ACCESS);
		/*
			Reconocimiento de cadenas.
		*/
		case 38:
			{std::string cadena = "" + cActual;
			cActual = _iManager.getNext();
			while (isLetDigUnG(cActual)) {
				cadena += cActual;
				cActual = _iManager.getNext();
			}
			return Palabra(cadena, Enumerados::Token::ID);}
		/*
			Reconocimiento de integer.
		*/
		case 39:
			{int num = int(cActual);
			cActual = _iManager.getNext();
			while (isNum(cActual)) {
				num *= 10;
				cActual = _iManager.getNext();
				num += int(cActual);
			}
			return Numero(num, Enumerados::Token::INT);}

		default:
			break;
		}//Fin switch
	

		cActual = _iManager.getNext();
	}//Fin while
}

