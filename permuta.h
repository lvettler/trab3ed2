#ifndef  PERMUTA_H_
#define PERMUTA_H_ 
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include "job.h"

typedef struct permuta{
	tJob *pos; //vetor posicionado
	tJob *npos; //vetor nao posicionado
	int lb; //limite inferior
	int ub; //limite superior
	int tempoDecorrido;
	int ip;
	int in;
}*tPermuta;

tPermuta criaPermuta(int tamanho);

void adicionaNpos(tPermuta p, tJob j);

void adicionaPos(tPermuta p, tJob j);

tPermuta lerPermuta(int tamanho);

tPermuta copiaPermuta(tPermuta p);

int getLowerBound(tPermuta p);

int getUpperBound(tPermuta p);

int isTerminado(tPermuta p);

tJob* getPos(tPermuta p);

tJob* getNPos(tPermuta p);

int getTamPos(tPermuta p);

int getTamNPos(tPermuta p);

int getTamPermuta(tPermuta p);

void processa(tPermuta p, tJob pos[], int tamPos, tJob npos[], int tamNPos, int index);

void imprimePermuta(void* p);

void liberaPermuta(void* p);

#endif