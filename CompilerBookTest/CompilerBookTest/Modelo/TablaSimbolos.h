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
Clase que otroga la totalidad de las funcionalidades de la tabla de s�mbolos.

Funcionalidades:

a- Agregar una palabra reservada a la tabla.
b- Agregar un s�mbolo a la tabla.
c- Recuperar el identificador �nico de un s�mbolo pasado por par�metro.
*****************************************************************************************/
class TablaSimbolos : public TablaSimbolosInizializador, public ITablaSimbolos
{
public:
	TablaSimbolos();
	~TablaSimbolos();
	
	/*************************************************************************************************
	M�todo que agrega una palabra reservada en la tabla de s�mbolos y lo asocia a un token pasado como
	par�metro.
	
	Devuelve:
	a- 0 si la operaci�n tuvo �xito.
	b- (-1) si la palabra reservada ya exist�a.
	*************************************************************************************************/
	int insertReservedWord(std::string nombre, Enumerados::Token);

	/*************************************************************************************************
	Agrega un s�mbolo a la tabla.
	
	Devuelve:
	a- Un n�mero positivo correspondiente al identificador del simbolo insertado.
	b- (-1) si el s�mbolo ya exist�a en el bloque.
	c- (-2) si el s�mbolo buscado es una palabra reservada, en este caso devuelte el enumerado
		al token correspondiente.
	*************************************************************************************************/
	int insertSymbol(std::string nombre);
	
	/*************************************************************************************************
	Busca un s�mbolo pasado por par�metro como string.
	
	El token pasado como par�metro ser� modificado, al finalizar indicar� el token correspondiente al
	s�mbolo buscado. Esto porque pueden agregarse las palabras reservadas a la tabla de s�mbolos.
	De esta forma se reducir�an los estados del analizador l�xico.
	
	Devuelve:
	a- Un n�mero positivo correspondiente al identificador del simbolo hallado.
	b- (-1) si el s�mbolo no se hall� en la tabla de s�mbolos.
	*************************************************************************************************/
	int getID(std::string simbolo, Enumerados::Token token);
	
	/*************************************************************************************************
	Crea una nueva secci�n en la tabla de s�mbolos.
	
	Los nuevos s�mbolos que no sean palabras reservadas que se agreguen y coincidan con otros iguales
	agregados en bloques anteriores tendr�n prioridad a la hora de ser recuperados.
	
	Devuelve:
	a- 0 si se agreg� un bloque exitosamente.
	b- (-1) si no se pudo agregar un nuevo bloque.
	*************************************************************************************************/
	int pushNewBlock();
	
	/*************************************************************************************************
	Borra el �ltimo bloque de la tabla de s�mbolos.
	
	Devuelve:
	a- 0 si se borr� exitosamente.
	b- (-1) si s�lo queda un bloque ya que, seg�n el dise�o, �ste no se puedr� borrar.
	*************************************************************************************************/
	int deleteLastBlock();
	
private:
	MapSimbolos _PalabrasReservadas;
	stackTablas* _tablasIdentificadores;
};

