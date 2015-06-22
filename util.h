#ifndef  UTIL_H_
#define UTIL_H_ 
#define FREE(x) if(x != NULL){free(x); x = NULL}

typedef enum algoritmo{BS, BB}algoritmo;

int verifica_tipo(char* tipo);

int calcula_multa(Job sequenciaJobs[], int numeroJobs);

int calcula_todas_multa(Job sequenciaJobs[], int numeroJobs);

void sequencia_inicial(int vet[], int n);













#endif

