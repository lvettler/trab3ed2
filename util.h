#ifndef  UTIL_H_
#define UTIL_H_ 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listaGen.h"
#include "permuta.h"

#define FREE(x) if(x != NULL){ free(x); x = NULL; }

typedef enum {BS, BB, ERRO}algoritmo;

algoritmo verificaTipo(char* tipo);

void adicionaPermutaOrdenada(listaGen* l, no n);

#endif