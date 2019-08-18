#pragma once
#include <map>
#include <string>
#include "TablaSimbolosInizializador.h"
#include "Lexico/Token.h"
#include "ITablaSimbolos.h"
#include "../MapSimbolos.h"

struct stackTablas  {
		MapSimbolos _NodoSimbolos;
		stackTablas* nxtNode;
};

/*****************************************************************************************
Clase que otroga la totalidad de las funcionalidades de la tabla de símbolos.

Funcionalidades:

a- Agregar una palabra reservada a la tabla.
b- Agregar un símbolo a la tabla.
c- Recuperar el identificador único de un símbolo pasado por parámetro.
*****************************************************************************************/
class TablaSimbolos : public TablaSimbolosInizializador, public ITablaSimbolos
{
public:
	TablaSimbolos();
	~TablaSimbolos();
	
	/*************************************************************************************************
	Método que agrega una palabra reservada en la tabla de símbolos y lo asocia a un token pasado como
	parámetro.
	
	Devuelve:
	a- 0 si la operación tuvo éxito.
	b- (-1) si la palabra reservada ya existía.
	*************************************************************************************************/
	int insertReservedWord(std::string nombre, Enumerados::Token);

	/*************************************************************************************************
	Agrega un símbolo a la tabla.
	
	Devuelve:
	a- Un número positivo correspondiente al identificador del simbolo insertado.
	b- (-1) si el símbolo ya existía en el bloque.
	c- (-2) si el símbolo buscado es una palabra reservada, en este caso devuelte el enumerado
		al token correspondiente.
	*************************************************************************************************/
	int insertSymbol(std::string nombre);
	
	/*************************************************************************************************
	Busca un símbolo pasado por parámetro como string.
	
	El token pasado como parámetro será modificado, al finalizar indicará el token correspondiente al
	símbolo buscado. Esto porque pueden agregarse las palabras reservadas a la tabla de símbolos.
	De esta forma se reducirían los estados del analizador léxico.
	
	Devuelve:
	a- Un número positivo correspondiente al identificador del simbolo hallado.
	b- (-1) si el símbolo no se halló en la tabla de símbolos.
	*************************************************************************************************/
	int getID(std::string simbolo, Enumerados::Token token);
	
	/*************************************************************************************************
	Crea una nueva sección en la tabla de símbolos.
	
	Los nuevos símbolos que no sean palabras reservadas que se agreguen y coincidan con otros iguales
	agregados en bloques anteriores tendrán prioridad a la hora de ser recuperados.
	
	Devuelve:
	a- 0 si se agregó un bloque exitosamente.
	b- (-1) si no se pudo agregar un nuevo bloque.
	*************************************************************************************************/
	int pushNewBlock();
	
	/*************************************************************************************************
	Borra el último bloque de la tabla de símbolos.
	
	Devuelve:
	a- 0 si se borró exitosamente.
	b- (-1) si sólo queda un bloque ya que, según el diseño, éste no se puedrá borrar.
	*************************************************************************************************/
	int deleteLastBlock();
	
private:
	MapSimbolos _PalabrasReservadas;
	stackTablas* _tablasIdentificadores;
};

