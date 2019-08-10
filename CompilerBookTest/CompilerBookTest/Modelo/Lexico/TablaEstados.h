struct CeldaNodo {
	char valor;
};


class TablaEstados
{
public:
	TablaEstados();
	~TablaEstados();
	int agregarNodo(char valor);
	void insertarArista(int NodoOrigen, int NodoDestino);
	int getNodo(char valor);

private:
	int agregarEstado();
	bool isInEstados(char valor);
	CeldaNodo* _vertices;
	/****************************************************************************
	Aristas: se navegar�n desde el vertice del primer �ndice al del segundo.
	****************************************************************************/
	bool** _aristas;
	int _countEstados;
};
