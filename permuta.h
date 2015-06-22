#ifndef  PERMUTA_H_
#define PERMUTA_H_ 
#include "job.h"

struct permuta{
	Job pos; //vetor posicionado
	Job npos; //vetor nao posicionado
	int lb; //limite inferior
	int ub; //limite superior
	int ip;
	int in;
};

typedef struct permuta *Permuta;

void libera_permuta(Permuta p);

Permuta inicializa_permuta(int *sequenciaInicial, int limiteInferior, int limiteSuperior);














#endif