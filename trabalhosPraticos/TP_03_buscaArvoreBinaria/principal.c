#include "ordenacao.h"
#include <stdio.h>

int main ()
{

	long *vetor, soma;
	double corte;
	int n, area;
	while(scanf("%d %d", &n, &area), n != 0 || area != 0)
	{	
		vetor = alocaVetor(vetor, n);
		soma = 0;
		for(int i = 0; i < n; i++){
        	scanf("%ld", &vetor[i]);
			soma += vetor[i];
    	}	

		//preencher o vetor
		if(soma == area)
			printf(":D\n");

		else if(soma < area)
			printf("-.-\n");

		else{
			ordenacao(vetor, n);
			binario(vetor, n, area, &corte);
			printf("%.4lf\n", corte);
		}

	

		vetor = desalocaVetor(vetor);
		//desalocar o vetor
	}



	return 0;
}
