#pragma once

#include "TablaSimbolosInizializador.h"
#include <string>

/****************************************************************************************
Aministrador de los distindos an�lisis y procesos del compilador.

Se encarga de los llamados a las dem�s clases.
****************************************************************************************/
class AnalysisManager 
{
public:
	AnalysisManager();
	~AnalysisManager();
	/**********************************************************************************
	Agrega las palabras reservadas del lenguaje c++ a la tabla de s�mbolos.
	**********************************************************************************/
	void insertReservedWords(TablaSimbolosInizializador* t);
	void analizar(std::string file);
};