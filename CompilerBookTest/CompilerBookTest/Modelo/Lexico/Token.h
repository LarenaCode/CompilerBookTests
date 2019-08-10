#include "TablaEstados.h"
#include <string>

class Token
{
public:
	
	static Token createToken(std::string nombre);
	static void inicialize();
	~Token();
	std::string getNombre();
	int getCodigo();
	bool agregarValor(std::string valor, TablaEstados tablaEstados);

private:
	Token(std::string nombre, int codigo);
	std::string _nombre;
	int _codigo;
	static int _count;
};
