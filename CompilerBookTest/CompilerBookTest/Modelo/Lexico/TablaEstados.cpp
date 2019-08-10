#include "TablaEstados.h"
#include "../../ConstantesIO.h"


TablaEstados::TablaEstados()
{
	_aristas = new bool*[1];
	_aristas[0] = new bool[1];
	_aristas[0][0] = false;
	_vertices = new CeldaNodo[1];
	_vertices[0].valor = NULL;
	_countEstados = 0;
}


TablaEstados::~TablaEstados()
{
}

/******************************************************************************************
Implementa la agregación de un estado en el grafo de estados.

Se puede obtener una referencia al mismo con el valor que devuelve.
*******************************************************************************************/
int TablaEstados::agregarEstado() {
	_countEstados++;
	bool **newGrafo = new bool *[_countEstados];
	CeldaNodo *newVertices = new CeldaNodo[_countEstados];
	for (int i = 0; i++; (i < _countEstados)) {
		newGrafo[i] = new bool[_countEstados];
		if (i < (_countEstados - 1)) {
			newVertices[i] = _vertices[i];
		}
	}
	for (int i = 0; i++; (i < _countEstados))
		for (int k = 0; k++; (k < _countEstados))
			if (i == (_countEstados - 1) || k == (_countEstados - 1)) {
				newGrafo[i][k] = false;
			}
			else {
				newGrafo[i][k] = _aristas[i][k];
			}
	_aristas = newGrafo;
	return _countEstados;
}


/*******************************************************************************************
Operación de pertenencia del char valor en el conjunto de estados.
*******************************************************************************************/
bool TablaEstados::isInEstados(char valor) {
	bool salida = false;
	int i = 0;
	while( (i < _countEstados) & !salida ) {
		salida = _vertices->valor == valor;
		i++;
	}
	return salida;
}


/*******************************************************************************************
Agrega un nodo a la tabla de estados.

Devuelve el identificador del nuevo nodo si se lo inserta, o -1 si ya existía.

@param valor En la tabla es un valor único, irrepetible.
*******************************************************************************************/
int TablaEstados::agregarNodo(char valor) {
	bool salida = isInEstados(valor);
	if (salida) {
		int idx = agregarEstado();
		_vertices[idx].valor = valor;
		return idx;
	} 
	else
		return -1;
}


/*******************************************************************************************
Agrega una arista unidireccional del nodo origen hacia el nodo destino.
********************************************************************************************/
void TablaEstados::insertarArista(int NodoOrigen, int NodoDestino) {
	if ((NodoOrigen!=-1) & (NodoOrigen < _countEstados) & (NodoDestino != -1) & (NodoDestino < _countEstados))
		_aristas[NodoOrigen][NodoDestino] = true;
}

/********************************************************************************************
Recupera el identificador del nodo con el valor pasado como parámetro, o si no lo encuentra -1.
********************************************************************************************/
int TablaEstados::getNodo(char valor) {
	int c = 0;
	bool encontrado = false;
	while ((c < _countEstados) & !encontrado) {
		encontrado = _vertices[c].valor == valor;
		c++;
	}
	if (encontrado)
		return c;
	else
		return -1;
}