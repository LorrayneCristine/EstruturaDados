# ifndef funcao_h
# define funcao_h

//COMPLETAR O NOME DA ESTRUTURA
typedef struct submissao TADsubmissao;

void lerQuantidade(int *qtd);

TADsubmissao *alocaSubmissao (TADsubmissao *S, int qtd);

TADsubmissao *desalocaSubmissao (TADsubmissao *S);

void lerSubmissao(TADsubmissao *S, int qtd); 

int calculaTempo(TADsubmissao *S, int qtd, int *cont);

void printSubmissao(int cont, int soma);

int calculaRepetido(int a, TADsubmissao *S, int qtd);

# endif
