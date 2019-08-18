#pragma once
#include <map>
#include <string>
/*******************************************************************************************
Clase con finalidad de modularizar la tabla de s�mbolos.

Corresponde a una tabla de s�mbolo individual, la cual podr�a usarse en un stack de �stas.
De hecho, la intenci�n de crear esta clase es esa.

Se dise�� para otorgar funcionalidad de:
1- agregar un s�mbolo a una tabla de s�mbolos: int insertSymbol(std::string).
2- Consultar la existencia de un s�mbolo en la tabla, 
3- y recuperar el id de un s�mbolo dado: int getSymbolId(std::string).
*******************************************************************************************/
class MapSimbolos
{
public:
	MapSimbolos();
	~MapSimbolos();

	/****************************************************************************************
	Inserta un s�mbolo en la tabla, en �sta se almacenar� su nombre y un identificador �nico.

	Devuelve:
	a- Identificador correspondiente al s�mbolo insertado si tuvo �xito la operaci�n.
	b- (-1) si la operaci�n no tuvo �xito ya que el s�mbolo ya exist�a.
	****************************************************************************************/
	int insertSymbol(std::string symbol, int id);

	int insertSymbol(std::string symbol);

	/****************************************************************************************
	Recupera el identicador �nico de un s�mbolo pasado como par�metro.

	Devuelve:
	a- Identificador del s�mbolo si se hall� en la tabla.
	b- (-1) si el s�mbolo no se hall� en la tabla.
	****************************************************************************************/
	int getSymbolId(std::string symbol);

private:
	std::map <std::string, int> _Simbolos;
	int _count;
};

