#ifndef  UTIL_H_
#define UTIL_H_ 
#include "listaGen.h"

#define FREE(x) if(x != NULL){free(x); x == NULL;}

typedef enum {BS, BB}algoritmo;

algoritmo verificaTipo(char* tipo);

void adicionaPermutaOrdenada(listaGen* l, no n);

/*int calculaMulta(tJob sequenciaJobs[], int numeroJobs);

int calculaTodasMulta(tJob sequenciaJobs[], int numeroJobs);
*/
#endif

