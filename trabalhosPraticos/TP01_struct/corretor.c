#include "funcao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct submissao {

  char  id;
  int  tempo; 
  char  acertou[10];

};

void lerQuantidade(int *qtd){
  scanf("%d", qtd);
}

TADsubmissao *alocaSubmissao (TADsubmissao *S, int qtd){
   S = malloc(qtd * sizeof(TADsubmissao));
    
  if(S == NULL){
    printf("Memoria insuficiente.\n");
    return 0;
  }

   return S;
}


TADsubmissao *desalocaSubmissao (TADsubmissao *S){
  free(S);
  (S) = NULL;
  return S;
}

void lerSubmissao(TADsubmissao *S, int qtd){

  for(int i = 0; i < qtd; i ++){
    scanf(" %c", &S[i].id);
    scanf(" %d", &S[i].tempo);
    scanf(" %s", S[i].acertou);

  }

}

int calculaTempo(TADsubmissao *S, int qtd, int *cont){
  int aux = 0;
  for(int i = 0; i < qtd; i ++){
    if(strcmp(S[i].acertou, "correto") == 0){
        aux += S[i].tempo;
        aux += calculaRepetido(i, S,  qtd);
        *cont = *cont + 1;
    }
  }

  return aux;
}

//Manter como especificado
void printSubmissao(int cont, int soma){

  printf("%d %d\n", cont, soma);
  
}


int calculaRepetido(int a, TADsubmissao *S, int qtd){
  int aux = 0;
  for(int i = 0; i < qtd; i++){
      if(strcmp(S[i].acertou, "incompleto") == 0 && S[a].id == S[i].id){
        aux += 20;
      }   
  }

  return aux;
}