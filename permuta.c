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
	return p;
}

tPermuta copiaPermuta(tPermuta p){
	tPermuta c = criaPermuta(p->ip + p->in);
	memset(c, 0, sizeof(struct permuta));
	memcpy(c, p, sizeof(struct permuta));
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
	int tam = getTamPermuta(p);
	tJob *j = (tJob*)malloc(sizeof(tJob)*(tam));
	memset(j, 0, sizeof(tJob)*tam);
	memcpy(j, p->pos, sizeof(tJob)*(tam));
	return j;
}

tJob* getNPos(tPermuta p){
	int tam = getTamPermuta(p);
	tJob *j = (tJob*)malloc(sizeof(tJob)*(tam));
	memset(j, 0, sizeof(tJob)*tam);
	memcpy(j, p->npos, sizeof(tJob)*(tam));
	return j;
}

int getTamPos(tPermuta p){
	return p->ip;
}

int getTamNPos(tPermuta p){
	return p->in;
}

int getTamPermuta(tPermuta p){
	return getTamPos(p) + getTamNPos(p);
}

void processa(tPermuta p, int lowerBound, tJob pos[], int tamPos, tJob npos[], int tamNPos, int index){

	int tam = tamPos + tamNPos;
	printf("XOTA: %d = %d + %d\n", tam, tamPos, tamNPos);
	tJob novo = criaJob(tam);
	printf("CU\n");
	
	memset(novo, 0 , sizeof(struct job));
	memcpy(novo, npos[index], sizeof(struct job));

	memset(p->pos, 0, sizeof(struct job)*tam);
	memcpy(p->pos, pos, sizeof(struct job)*tam);
	p->pos[tamPos++] = novo;
	p->ip = tam;
	
	memcpy(p->npos, npos, sizeof(struct job)*index);
	memcpy(p->npos+index, npos+index+1, sizeof(struct job)*(tam - index - 1));
	p->in--;
	
	p->lb = lowerBound;
	p->ub -= getMulta(novo);
	p->tempoDecorrido += getTempo(novo);
}

void imprimePermuta(void* ptr){
	int i;
	tPermuta p = (tPermuta)ptr;
	printf("%d: ", p->lb);
	for(i = 0; i < p->ip; i++){
		printf("%d ", getId(p->pos[i]));
	}
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