
class Token
{
public:
	Token(char *valor, int codigo);
	~Token();
	char* getValor();
	int getCodigo();

private:
	char *_valor;
	int _codigo;
};
