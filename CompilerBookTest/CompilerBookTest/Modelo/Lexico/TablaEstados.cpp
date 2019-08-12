#pragma once
#include "TablaEstados.h"
#include "../../ConstantesIO.h"
#include <string>

TablaEstados::TablaEstados()
{
	_vertices = new CeldaNodo[1];
	_vertices[0].nodoO = false;
	_vertices[0].codigoToken = NULL;
	_vertices[0]._cAristas = 0;
	_countEstados = 0;
}


TablaEstados::~TablaEstados()
{

	for (int i = 0; i < _countEstados; i++) {
		if (_vertices[i].aristas != nullptr)
			delete[] _vertices[i].aristas;
		else
			continue;
	}
	delete[] _vertices;
}

CeldaNodo crearEstado(int codToken, bool nodoO ) {
	CeldaNodo x;
	x.aristas = nullptr;
	x._cAristas = 0;
	x.codigoToken = codToken;
	x.nodoO = nodoO;
}

/******************************************************************************************
Implementa la agregación de un estado en el grafo de estados.

Se puede obtener una referencia al mismo con el valor que devuelve.

TODO: delete[] revisar.
*******************************************************************************************/
int TablaEstados::agregarEstado( int codToken ) {
	_countEstados++;
	CeldaNodo *newVertices = new CeldaNodo[_countEstados];
	for (int i = 0; i++; (i < _countEstados)) {
		if (i < (_countEstados - 1)) {
			newVertices[i] = _vertices[i];
		}
		else {
			_vertices[i] = crearEstado( codToken , true);
		}
	}
	//delete[] _vertices;
	_vertices = newVertices;
	return _countEstados;
}


/*******************************************************************************************
Operación de pertenencia del char valor en el conjunto de estados.
*******************************************************************************************/
bool TablaEstados::isInEstados(int valor) {
	bool salida = false;
	int i = 0;
	while( (i < _countEstados) & !salida ) {
		//salida = _vertices->nombre == valor;
		i++;
	}
	return salida;
}

/*******************************************************************************************
Agrega una arista unidireccional del nodo origen hacia el nodo destino.

TODO: Revisar comportamiento delete.
********************************************************************************************/
void TablaEstados::insertarArista(int NodoOrigen, int NodoDestino, char costo) {
	if ((NodoOrigen != -1) & (NodoOrigen < _countEstados) & (NodoDestino != -1) & (NodoDestino < _countEstados)) {
		CeldaNodo* x = getNodo(NodoOrigen);
		int i = 0;
		while ((x->aristas[i].Destino != getNodo(NodoDestino)) & (i<x->_cAristas))
			i++;
		if (i < x->_cAristas) {
			agregarValor(_aristas[i], costo);
		}
		else {
			x->_cAristas++;
			Arista* newAristas = new Arista[x->_cAristas];
			for (int i = 0; i < (x->_cAristas-1); i++)
				newAristas[i] = _aristas[i];
			Arista y;
			y.Destino = getNodo(NodoDestino);
			y.cValores = 0;
			agregarValor(y, costo);
			newAristas[x->_cAristas] = y;
			//delete[] x->aristas;
			x->aristas = newAristas;
		}
	}
}

/********************************************************************************************
Recupera el identificador del nodo con el valor pasado como parámetro, o si no lo encuentra -1.
********************************************************************************************/
CeldaNodo* TablaEstados::getNodo(int valor) {
	if ((valor>0) & (valor<_countEstados))
		return &_vertices[valor];
	else
		return nullptr;
}

void agregarValor(Arista a, char valor) {
	int c = ++a.cValores;
	char* newValores = new char[c];
	for (int k = 0; k < (c - 1); k++)
		newValores[k] = a.Valores[k];
	char x = valor;
	newValores[c - 1] = x;
}

bool TablaEstados::insertarToken(std::string palabra) {

}

void TablaEstados::reset() {

}

int TablaEstados::recorrer(char valor) {

}
