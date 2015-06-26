#include "permuta.h"

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
	if(p->tempoDecorrido + getTempo(j) > getDeadline(j))
		p->lb += getMulta(j);
}

void adicionaPos(tPermuta p, tJob j){
	p->pos[p->ip++] = j;
	p->tempoDecorrido += getTempo(j);
	if (p->tempoDecorrido > getDeadline(j)){
		p->lb += getMulta(j);
		p->ub += getMulta(j);
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
	for(int i = 0; i < p->ip; ++i){
		tJob aux = copiaJob(p->pos[i]);
		adicionaPos(c, aux);
	}
	for (int i = 0; i < p->in; ++i){
		tJob aux = copiaJob(p->npos[i]);
		adicionaNpos(c, aux);
	}
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
	int tam = getTamPos(p);
	tJob *j = (tJob*)malloc(sizeof(tJob)*(tam));
	for (int i = 0; i < tam; ++i)
		j[i] = copiaJob(p->pos[i]);
	return j;
}

tJob* getNPos(tPermuta p){
	int tam = getTamNPos(p);
	tJob *j = (tJob*)malloc(sizeof(tJob)*(tam));
	for (int i = 0; i < tam; ++i)
		j[i] = copiaJob(p->npos[i]);
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

void processa(tPermuta p, tJob pos[], int tamPos, tJob npos[], int tamNPos, int index){
	tJob novo = copiaJob(npos[index]);

	for (int i = 0; i < tamPos; ++i)
		adicionaPos(p, copiaJob(pos[i]));
	adicionaPos(p,novo);
	
	for (int i = 0; i < index; ++i)
		adicionaNpos(p, copiaJob(npos[i]));

	for (int i = index + 1; i < tamNPos; ++i)
		adicionaNpos(p, copiaJob(npos[i]));
}

void imprimePermuta(void* ptr){
	int i;
	tPermuta p = (tPermuta)ptr;
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
