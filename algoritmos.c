#include "algoritmos.h"

#include <stdio.h>

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
		
		tJob* pos = getPos(atual);
		tJob* npos = getNPos(atual);
		
		liberaNo(front, liberaPermuta);
		
		int i;
		for(i = 0; i < tamNPos; i++){

			tPermuta nova = criaPermuta(tamNPos+tamPos);
			processa(nova, pos, tamPos, npos, tamNPos, i);
			int auxLowerBound = getLowerBound(nova);

			if(auxLowerBound <= upperBoundLimite || getTam(l) == 0){
		
				no novo = criaNo(nova);
				adicionaPermutaOrdenada(&l, novo);

			}else{
				liberaPermuta(nova);
			}
			
		}

		for (i = 0; i < tamPos; ++i)
			liberaJob(pos[i]);
		FREE(pos);
		for (i = 0; i < tamNPos; ++i)
			liberaJob(npos[i]);
		FREE(npos);
		
	}

	no r = popFront(l);
	tPermuta retorno = copiaPermuta((tPermuta)getItem(r));
	liberaNo(r, liberaPermuta);
	liberaPermuta(limite);

	return retorno;
}

tPermuta beamSearch(listaGen l, int w){
	while (!isTerminado((tPermuta)getItem(getIni(l)))){
	
		no front = popFront(l);
		tPermuta atual = (tPermuta)getItem(front);
		
		int tamPos = getTamPos(atual);
		int tamNPos = getTamNPos(atual);
		
		tJob* pos = getPos(atual);
		tJob* npos = getNPos(atual);
		
		liberaNo(front, liberaPermuta);
		
		int i;
		for(i = 0; i < tamNPos; i++){
		
			tPermuta nova = criaPermuta(tamNPos+tamPos);
			processa(nova, pos, tamPos, npos, tamNPos, i);
			int auxLowerBound = getLowerBound(nova);
			
			if(getTam(l) < w || (auxLowerBound < getLowerBound((tPermuta)getItem(getFim(l))))){
			
				no novo = criaNo(nova);
				adicionaPermutaOrdenada(&l, novo);
				
			}else{
				liberaPermuta(nova);
			}
		}
		
		for (i = 0; i < tamPos; ++i)
			liberaJob(pos[i]);
		FREE(pos);
		for (i = 0; i < tamNPos; ++i)
			liberaJob(npos[i]);
		FREE(npos);

	}
	
	no r = popFront(l);
	tPermuta retorno = copiaPermuta((tPermuta)getItem(r));
	liberaNo(r, liberaPermuta);
	
	return retorno;
}