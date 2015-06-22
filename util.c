#include "util.h"
#include "job.h"
#include <stdlib.h>
#include <stdio.h>

int verifica_tipo(char* tipo){
	
	if(strcmp(tipo, "bs") == 0)
		return BS;
	
	else if(strcmp(tipo, "bb") == 0)
		return BB;
}

int calcula_multa(Job sequenciaJobs[], int numeroJobs){
	int tempo = 0, multa = 0, i;

	for (i = 0; i < numeroJobs; i++){
		tempo = tempo + get_tempo(sequenciaJobs[i]);

		if(tempo > sequenciaJobs[i]->deadline)
			multa = multa + get_multa(sequenciaJobs[i]);
		
	}
	return multa;
}

int calcula_todas_multa(Job sequenciaJobs[], int numeroJobs){
	int multa = 0, i;
	for(i=0; i < numeroJobs; i++){
		multa = multa + get_multa(sequenciaJobs[i]);
	}
}


void sequencia_inicial(int vet[], int n){
	int i;
	for(i = 0; i < n; i++){
		vet[i] = i;
	}
}