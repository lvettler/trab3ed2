#include <stdlib.h>
#include <stdio.h>
#include "listaGen.h"
#include "util.h"

no criaNo(void* item){
	no novo = (no)malloc(sizeof(struct no));
	novo->item = item;
	novo->prox = NULL;
	return novo;
}

void liberaNo(no n, void f(void*)){
	if(n != NULL)
		f(n->item);
	FREE(n);
}

void* getItem(no n){
	return n->item;
}

listaGen criaListaGen(){
	listaGen lista = (listaGen)malloc(sizeof(struct lista));
	lista->ini = lista->fim = NULL;
	lista->tam = 0;
	return lista;
}

void liberaListaGen(listaGen l, void f(void*)){
	if(l != NULL){
		no aux, prox;
		for(aux = l->ini; aux != NULL; aux = prox){
			prox = aux->prox;
			liberaNo(aux, f);
		}
	}
	FREE(l);
}

void pushFront(listaGen l, no n){
	if(l->tam == 0)
		l->fim = n;
	else
		n->prox = l->ini;
	l->ini = n;
	l->tam++;
}

void pushBack(listaGen l, no n){
	if(l->ini == NULL) l->ini = n;
	else l->fim->prox = n;
	l->fim = n;
	l->tam++;
}

no popFront(listaGen l){
	no r = l->ini;
	if(l->ini != NULL)
		l->ini = l->ini->prox;
	if(l->ini == NULL)
		l->fim = NULL;
	r->prox = NULL;
	l->tam--;
	return r;
}

no popBack(listaGen l){
	no aux, ant;
	if(l->ini == NULL) return NULL;
	for(aux = l->ini; aux->prox != NULL; aux = aux->prox) ant = aux;
	ant->prox = NULL;
	l->fim = ant;
	l->tam--;
	return aux;
}

int getTam(listaGen l){
	return l->tam;
}

no getFim(listaGen l){
	if(l->fim != NULL){
		return l->fim;
	}
	return NULL;
}

no getIni(listaGen l){
	if(l->ini != NULL){
		return l->ini;
	}
	return NULL;
}

void percorreListaGen(listaGen l, void cb(void*)){
	if(l != NULL){
		no n;
		for(n = l->ini; n != NULL; n = n->prox) cb(n->item);
	}
}