#pragma once
#include <map>
#include <string>
/*******************************************************************************************
Clase con finalidad de modularizar la tabla de símbolos.

Corresponde a una tabla de símbolo individual, la cual podría usarse en un stack de éstas.
De hecho, la intención de crear esta clase es esa.

Se diseñó para otorgar funcionalidad de:
1- agregar un símbolo a una tabla de símbolos: int insertSymbol(std::string).
2- Consultar la existencia de un símbolo en la tabla, 
3- y recuperar el id de un símbolo dado: int getSymbolId(std::string).
*******************************************************************************************/
class MapSimbolos
{
public:
	MapSimbolos();
	~MapSimbolos();

	/****************************************************************************************
	Inserta un símbolo en la tabla, en ésta se almacenará su nombre y un identificador único.

	Devuelve:
	a- Identificador correspondiente al símbolo insertado si tuvo éxito la operación.
	b- (-1) si la operación no tuvo éxito ya que el símbolo ya existía.
	****************************************************************************************/
	int insertSymbol(std::string symbol, int id);

	int insertSymbol(std::string symbol);

	/****************************************************************************************
	Recupera el identicador único de un símbolo pasado como parámetro.

	Devuelve:
	a- Identificador del símbolo si se halló en la tabla.
	b- (-1) si el símbolo no se halló en la tabla.
	****************************************************************************************/
	int getSymbolId(std::string symbol);

private:
	std::map <std::string, int> _Simbolos;
	int _count;
};

