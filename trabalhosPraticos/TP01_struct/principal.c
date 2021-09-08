#include "funcao.h"
#include<stdio.h>

int main()
{
    int qtd, cont = 0, soma;
    
    TADsubmissao *S;
    S = NULL;
    lerQuantidade(&qtd);
    S = alocaSubmissao(S, qtd);
    lerSubmissao(S, qtd);
    soma = calculaTempo(S, qtd, &cont);

    printSubmissao(cont, soma);
    S = desalocaSubmissao(S);

    return 0;
}
