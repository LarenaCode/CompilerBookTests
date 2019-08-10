#include "pch.h"
#include <fstream>
#include <string>

/*************************************************************************************
Función cuyo objetivo es salir del programa por error y registrar el mismo.

Guarda el registro del error en un fichero con nombre "fatalError.log".

@param error Indica el error encontrado, debe contener el motivo del error.
@param codigo Indica un codigo de error, este valor retornará el programa al finalizar.
**************************************************************************************/
void FatalError(std::string error, int codigo) {
	std::ofstream f("fatalError.log", std::ios::binary);
	if (f.fail()) {
		exit(256);
	} else {
		f.seekp(0, std::ios::end);
		f.write(error.c_str(), sizeof(error));
		exit(codigo);
	}	
}