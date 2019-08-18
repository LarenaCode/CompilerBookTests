/*
#include "Token.h"
#include <string>*/

/*******************************************************************************************
Constructor privado de la clase.

@param nombre Es el nombre del token, no confundir con el valor.
@param codigo Valor del token.
********************************************************************************************/
/*Token::Token(std::string nombre, int codigo) : _nombre(nombre), _codigo(codigo)
{
}


Token::~Token()
{
}*/

/*******************************************************************************************
Inicializa la clase, concretamente, el contador.
********************************************************************************************/
/*void Token::inicialize() {
	_count = 0;
}

std::string Token::getNombre() {
	return _nombre;
}

int Token::getCodigo() {
	return _codigo;
}
*/
/********************************************************************************************
Método de clase que implementa el patrón factory.

El motivo es evitar la repetición de codigos.
*********************************************************************************************/
/*Token Token::createToken(std::string nombre) {
	Token salida(nombre, ++_count);
	return salida;
}*/

/*********************************************************************************************
Agrega un valor a una tabla de estados

Devuelve true si pudo completarse la operación, de lo contrario devuelve false.

@param valor String que se utilizará para generar nuevos estados.
@param tablaEstados Tabla donde se almacenarán los estados.
*********************************************************************************************/
/*bool Token::agregarValor(std::string valor, TablaEstados tablaEstados) {

	return true;
}*/