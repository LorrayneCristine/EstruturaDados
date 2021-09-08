#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Manter como especificado
TipoPaises *alocaPaises(TipoPaises *pais, int n){
  pais = (TipoPaises*) malloc(n * sizeof(TipoPaises));

  if(pais == NULL){
    printf("Memoria insuficiente.\n");
    return 0;
  }

  return pais; 
}

//Manter como especificado
TipoPaises *desalocaPaises(TipoPaises *pais){
    free(pais);
    (pais) = NULL;
    return pais;
}

void lerPais(TipoPaises *pais, int n){
 
 for(int i = 0; i < n; i++){
   scanf("%s %d %d %d", pais[i].nome, &pais[i].medalhasOuro,  &pais[i].medalhasPrata, &pais[i].medalhasBronze);
 }
}

void ordenaOuro(TipoPaises *pais, int n){

  int max;

  for(int i = 0; i < n; i++){
    max = i;
    for(int j = i +1; j < n; j++)
    {
        if(pais[j].medalhasOuro == pais[max].medalhasOuro){
          if(pais[j].medalhasPrata > pais[max].medalhasPrata){
              max = j;
          }else if(pais[j].medalhasPrata == pais[max].medalhasPrata){
              if(pais[j].medalhasBronze > pais[max].medalhasBronze){
                  max = j;
              }else if(pais[j].medalhasBronze == pais[max].medalhasBronze){
                if(strcmp(pais[j].nome, pais[max].nome) < 0){
                  max = j;
                }
              }
          }
        }
        else if(pais[j].medalhasOuro > pais[max].medalhasOuro){
          max = j; 
        }
      
    }
    if( i != max ){
      atribui(pais, i, max, n);
    }
  } 
}

void atribui(TipoPaises *pais, int i, int max, int n){
    TipoPaises *aux;
    aux = (TipoPaises*) malloc(n * sizeof(TipoPaises));
    
    aux[i].medalhasOuro = pais[i].medalhasOuro;
    aux[i].medalhasPrata = pais[i].medalhasPrata;
    aux[i].medalhasBronze = pais[i].medalhasBronze;
    strcpy(aux[i].nome, pais[i].nome);

    pais[i].medalhasOuro = pais[max].medalhasOuro;
    pais[i].medalhasPrata = pais[max].medalhasPrata;
    pais[i].medalhasBronze = pais[max].medalhasBronze;
    strcpy(pais[i].nome, pais[max].nome);


    pais[max].medalhasOuro = aux[i].medalhasOuro;
    pais[max].medalhasPrata = aux[i].medalhasPrata;
    pais[max].medalhasBronze = aux[i].medalhasBronze;
    strcpy(pais[max].nome, aux[i].nome);

    free(aux);
    aux = NULL;
}

