
class TablaSimbolos
{
public:
	TablaSimbolos();
	~TablaSimbolos();
private:
	Tabla* _tabla;
};

class Tabla
{
public:
	Tabla();
	~Tabla();
private:
	Tabla* NextTabla;
};