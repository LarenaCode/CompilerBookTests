#pragma once

#include "TablaSimbolosInizializador.h"
#include <string>

/****************************************************************************************
Aministrador de los distindos análisis y procesos del compilador.

Se encarga de los llamados a las demás clases.
****************************************************************************************/
class AnalysisManager 
{
public:
	AnalysisManager();
	~AnalysisManager();
	/**********************************************************************************
	Agrega las palabras reservadas del lenguaje c++ a la tabla de símbolos.
	**********************************************************************************/
	void insertReservedWords(TablaSimbolosInizializador* t);
	void analizar(std::string file);
};