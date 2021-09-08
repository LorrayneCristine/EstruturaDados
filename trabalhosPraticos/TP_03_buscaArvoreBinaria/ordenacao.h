# ifndef ordenacao_h
# define ordenacao_h

void ordenacao(long *vetor, int n);
//Manter como especificado
long *alocaVetor(long *vetor, int n);
//Manter como especificado
long *desalocaVetor(long *vetor);

void mergeSort_ordena(long *v, int esq, int dir);
void mergeSort_intercala(long *v, int esq, int meio, int dir); 
void area(long *v, int n, double media, double *area2);
void binario(long *v, int n, int area, double *corte);

# endif
