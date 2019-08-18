#pragma once
#include <string>

struct CeldaNodo {
	/****************************************************************************************
	Un nodo concat o nodo O son los nodos interiores en un árbol de estados.
	*****************************************************************************************/
	bool nodoO;
	int codigoToken;
	//Arista* aristas;
	int _cAristas;
};

struct Arista {
	CeldaNodo* Destino;
	char* Valores;
	/************************************************************************************
	Contador de la cantidad de valores validos asosiados a la arista.
	************************************************************************************/
	int cValores;
};

class TablaEstados
{
public:
	TablaEstados();
	~TablaEstados();
	bool insertarToken(std::string palabra);
	void reset();
	int recorrer(char valor);

private:
	void insertarArista(int NodoOrigen, int NodoDestino, char costo);
	CeldaNodo* getNodo(int valor);
	bool isInEstados(int valor);
	int agregarEstado( int codToken );
	CeldaNodo* _vertices;
	Arista* _aristas;
	int _countEstados;

};
