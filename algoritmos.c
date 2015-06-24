#include <string.h>
#include <stdlib.h>


#include "job.h"
#include <stdio.h>


#include "listaGen.h"
#include "permuta.h"
#include "util.h"

tPermuta branchBound(listaGen l){
	
	tPermuta limite = copiaPermuta((tPermuta)getItem(getIni(l)));
	int upperBoundLimite = getUpperBound(limite);
	
	while (!isTerminado((tPermuta)getItem(getIni(l)))){
		
		no front = popFront(l);
		tPermuta atual = (tPermuta)getItem(front);
		
		if(getUpperBound(atual) < upperBoundLimite){
		
			upperBoundLimite = getUpperBound(atual);
			liberaPermuta(limite);
			limite = copiaPermuta(atual);
			
		}
		
		int tamPos = getTamPos(atual);
		int tamNPos = getTamNPos(atual);
		int lowerBound = getLowerBound(atual);
		int duracao = getDuracao(atual);
		
		tJob* pos = getPos(atual);
		tJob* npos = getNPos(atual);
		
		liberaNo(front, liberaPermuta);
		
		int i;
		for(i = 0; i < tamNPos; i++){
			
			tJob aux = npos[i];
			int auxDuracao = duracao + getTempo(aux);
			int auxLowerBound = (auxDuracao > getDeadline(aux) ? getMulta(aux) + lowerBound: lowerBound);
			
			if(auxLowerBound <= upperBoundLimite){
		
				tPermuta nova = criaPermuta(tamNPos+tamPos);
				processa(nova, auxLowerBound, pos, tamPos, npos, tamNPos, i);
				no novo = criaNo(nova);
				adicionaPermutaOrdenada(&l, novo);

			}
			
		}
		
		FREE(pos);
		FREE(npos);
		
	}
	
	no r = popFront(l);
	tPermuta retorno = copiaPermuta((tPermuta)getItem(r));
	liberaNo(r, liberaPermuta);
	
	return retorno;
}

tPermuta beamSearch(listaGen l, int w){
	int indice = 0;
	
	while (!isTerminado((tPermuta)getItem(getIni(l)))){
	
		no front = popFront(l);
		tPermuta atual = (tPermuta)getItem(front);
		
		int tamPos = getTamPos(atual);
		int tamNPos = getTamNPos(atual);
		int lowerBound = getLowerBound(atual);
		int duracao = getDuracao(atual);
		
		tJob* pos = getPos(atual);
		tJob* npos = getNPos(atual);
		
		liberaNo(front, liberaPermuta);
		
		int i;
		for(i = 0; i < tamNPos; i++){
		
			tJob aux = npos[i];
			int auxDuracao = duracao + getTempo(aux);
			int auxLowerBound = (auxDuracao > getDeadline(aux) ? getMulta(aux) + lowerBound: lowerBound);
			
			if(indice < w || (auxLowerBound < getLowerBound((tPermuta)getItem(getFim(l))))){
			
				tPermuta nova = criaPermuta(tamNPos+tamPos);
				processa(nova, auxLowerBound, pos, tamPos, npos, tamNPos, i);
				no novo = criaNo(nova);
				adicionaPermutaOrdenada(&l, novo);
				indice++;
				
			}
		}
		
		FREE(pos);
		FREE(npos);

	}
	
	no r = popFront(l);
	tPermuta retorno = copiaPermuta((tPermuta)getItem(r));
	liberaNo(r, liberaPermuta);
	
	return retorno;
}