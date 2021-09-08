#include "ordenacao.h"
#include <stdio.h>

int main ()
{

	int n;
  	TipoPaises *pais;

	pais = NULL; 
	
	scanf("%d", &n);

	pais = alocaPaises(pais,n); 
	lerPais(pais, n);
 	ordenaOuro(pais, n);
	

	for(int i = 0; i < n; i++){
    	printf("%s %d %d %d\n", pais[i].nome, pais[i].medalhasOuro, pais[i].medalhasPrata, pais[i].medalhasBronze );
	}
	pais = desalocaPaises(pais);
  return 0;
}
