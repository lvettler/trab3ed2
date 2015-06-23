#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "permuta.h"
#include "util.h"
#include "job.h"

tPermuta criaPermuta(int tamanho){
	tPermuta p = (tPermuta)malloc(sizeof(struct permuta));
	p->pos = (tJob*)malloc(sizeof(tJob)*tamanho);
	p->npos = (tJob*)malloc(sizeof(tJob)*tamanho);
	p->lb = 0;
	p->ub = 0;
	p->tempoDecorrido = 0;
	p->ip = 0;
	p->in = 0;
	return p;	
}

void adicionaNpos(tPermuta p, tJob j){
	p->npos[p->in++] = j;
	p->ub += getMulta(j);
}

void adicionaPos(tPermuta p, tJob j){
	p->pos[p->ip++] = j;
	p->tempoDecorrido += getTempo(j);
	if (p->tempoDecorrido > getDeadline(j)){
		p->lb += getMulta(j);
	}
}

tPermuta lerPermuta(int tamanho){
	tPermuta p = criaPermuta(tamanho);
	int i;
	for(i = 0; i < tamanho; i++){
		adicionaNpos(p, lerJob(i));
	}
}

tPermuta copiaPermuta(tPermuta p){
	tPermuta c;
	memcpy(c, p, sizeof(tPermuta));
	return c;
}

int getDuracao(tPermuta p){
	return p->tempoDecorrido;
}

int getLowerBound(tPermuta p){
	return p->lb;
}

int getUpperBound(tPermuta p){
	return p->ub;
}

int isTerminado(tPermuta p){
	return p->in == 0;
}

tJob* getPos(tPermuta p){
	tJob *j;
	memcpy(j, p->pos, sizeof(tJob)*p->ip);
	return j;
}

tJob* getNPos(tPermuta p){
	tJob *j;
	memcpy(j, p->npos, sizeof(tJob)*p->in);
	return j;
}

int getTamPos(tPermuta p){
	return p->ip;
}

int getTamNPos(tPermuta p){
	return p->in;
}

/*void posiciona(tPermuta p, int pos){
	adicionaPos(p, p->npos[pos]);
	int i;
	p->in--;
	for(i = pos; i < p->in; i++){
		p->npos[i] = p->npos[i+1];
	}
}*/

void processa(tPermuta p, int lowerBound, tJob pos[], int tamPos, tJob npos[], int tamNPos, int index){
	tJob novo;
	memcpy(novo, npos[index], sizeof(tJob));
	
	memcpy(p->pos, pos, sizeof(tJob)*tamPos);
	p->pos[tamPos++] = novo;
	p->ip = tamPos;
	
	memcpy(p->npos, npos, sizeof(tJob)*index);
	memcpy(p->npos+index, npos+index+1, sizeof(tJob)*(tamNPos - index - 1));
	p->in--;
	
	p->lb = lowerBound;
	p->ub -= getMulta(npos[index]);
	p->tempoDecorrido += getTempo(npos[index]);
}

void imprimePermuta(tPermuta p){
	int i;
	printf("%d: ", p->lb);
	for(i = 0; i < p->ip; i++)
		printf("%d ", getId(p->pos[i]));
	printf("\n");
}

void liberaPermuta(void *p){
	int i;
	for(i = 0; i < ((tPermuta)p)->ip; i++){
		liberaJob(((tPermuta)p)->pos[i]);
	}
	FREE(((tPermuta)p)->pos);
	for(i = 0; i < ((tPermuta)p)->in; i++){
		liberaJob(((tPermuta)p)->npos[i]);
	}
	FREE(((tPermuta)p)->npos);
	FREE(p);
}