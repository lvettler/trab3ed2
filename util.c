#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include "job.h"
#include "listaGen.h"
#include "permuta.h"

algoritmo verificaTipo(char* tipo){
	
	if(strcmp(tipo, "bs") == 0)
		return BS;
	
	else if(strcmp(tipo, "bb") == 0)
		return BB;
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
		for(aux = (*l)->ini; aux != NULL && getLowerBound((tPermuta)getItem(aux)); ant = aux, aux = aux->prox);
		ant->prox = n;
		n->prox = aux;
		(*l)->tam++;
	}
}

/*int calculaMulta(tJob sequenciaJobs[], int numeroJobs){
	int tempo = 0, multa = 0, i;

	for (i = 0; i < numeroJobs; i++){
		tempo = tempo + getTempo(sequenciaJobs[i]);

		if(tempo > sequenciaJobs[i]->deadline)
			multa = multa + getMulta(sequenciaJobs[i]);
		
	}
	return multa;
}

int calculaTodasMulta(tJob sequenciaJobs[], int numeroJobs){
	int multa = 0, i;
	for(i=0; i < numeroJobs; i++){
		multa = multa + getMulta(sequenciaJobs[i]);
	}
}*/