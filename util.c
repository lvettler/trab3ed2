#include "util.h"


algoritmo verificaTipo(char* tipo){
	
	if(strcmp(tipo, "bs") == 0)
		return BS;
	else if(strcmp(tipo, "bb") == 0)
		return BB;
	return ERRO;
}

void adicionaPermutaOrdenada(listaGen* l, no n){
	tPermuta p = getItem(n);
	int lowerBound = getLowerBound(p);
	no aux, ant;
	if(getTam(*l) == 0)
		pushBack(*l, n);
	else if(getLowerBound((tPermuta)getItem(getFim(*l))) <= lowerBound)
		pushBack(*l, n);
	else if(getLowerBound((tPermuta)getItem(getIni(*l))) >= lowerBound)
		pushFront(*l, n);
	else{
		for(aux = (*l)->ini; getLowerBound((tPermuta)getItem(aux)) < lowerBound; ant = aux, aux = aux->prox);
		ant->prox = n;
		n->prox = aux;
		(*l)->tam++;
	}
}