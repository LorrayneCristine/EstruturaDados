#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

//Manter como especificado
long *alocaVetor(long *vetor, int n){
        vetor = NULL;
        vetor = (long*) malloc(n * sizeof(long));
        return vetor;
}

//Manter como especificado
long *desalocaVetor(long *vetor){
    free(vetor);
    return vetor;
}

void ordenacao(long *vetor, int n){
    mergeSort_ordena(vetor, 0, n-1);

}

void mergeSort_ordena(long *vetor, int esq, int dir) {  
    if  (esq == dir) 
        return; 
     
    int meio = (esq + dir) / 2; 
    mergeSort_ordena(vetor, esq, meio); 
    mergeSort_ordena(vetor, meio+1, dir); 
    mergeSort_intercala(vetor, esq, meio, dir); 

}

void mergeSort_intercala(long *v, int esq, int meio, int dir) {  
    int i, j, k; 
    int a_tam = meio-esq+1; 
    int b_tam = dir-meio;     
    int *a = (int*) malloc(sizeof(int) * a_tam); 
    int *b = (int*) malloc(sizeof(int) * b_tam); 
 
    for (i = 0; i < a_tam; i++) 
        a[i] = v[i+esq];     

    for (i = 0; i < b_tam; i++) 
        b[i] = v[i+meio+1]; 
     
    for (i = 0, j = 0, k = esq; k <= dir; k++) {         
        if (i == a_tam) 
            v[k] = b[j++]; 

        else if (j == b_tam) 
            v[k] = a[i++]; 

        else if (a[i] > b[j]) 
            v[k] = a[i++]; 

        else {
            v[k] = b[j++]; 
        }
         


    } 
    free(a); free(b); 
}

void areaMaior(long *v, int n, double media, double *area2){

    *area2 = 0;
    for(int i = 0; i < n; i++){
        if(v[i] > media){
            *area2 =  *area2 + (v[i] - media);
        }else 
            break;
    }
}

void binario(long *v, int n, int area, double *corte){
    double meio, area2;
    double esq = v[n-1];
    double dir = v[0];
    
    do
    {  
        meio = (esq+dir)/2;
        areaMaior(v, n, meio, &area2);

        if(area2 > area){
            esq = meio + 0.000001;
        }

        else if(area2 < area){
            dir = meio - 0.000001;
        }
    }while (esq <= dir && area2 != area);
    *corte = meio;
}

