# ifndef ordenacao_h
# define ordenacao_h

typedef struct{
	char nome[35]; 
	int medalhasOuro;
	int medalhasPrata;
	int medalhasBronze;
} TipoPaises;


TipoPaises *alocaPaises(TipoPaises *pais, int n);
void lerPais(TipoPaises *pais, int n);
void ordenaOuro(TipoPaises *pais, int n);
void atribui(TipoPaises *pais, int i, int max, int n);

TipoPaises *desalocaPaises(TipoPaises *pais);
# endif
