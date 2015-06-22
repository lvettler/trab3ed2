#include "permuta.h"
#include "util.h"

void libera_permuta(Permuta p){
	FREE(p.pos);
	FREE(p.npos);
	FREE(p);
}

Permuta inicializa_permuta(int tamanho){
	Permuta p = (Permuta)malloc(sizeof(Permuta));
	p->pos = (int*)malloc(sizeof(int)*tamanho);
	p->npos = (int*)malloc(sizeof(int)*tamanho);
	sequenciaInicial(p->npos, tamanho)
	p->lb = 0;
	p->ub = calculaMul;
	p->ip = 0;
	p->in = 0;
	return p;	
}


