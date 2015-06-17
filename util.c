#include "util.h"
#include <stdlib.h>
#include <stdio.h>

int verifica_tipo(char* tipo){
	
	if(strcmp(tipo, "bs") == 0)
		return BS;
	
	else if(strcmp(tipo, "bb") == 0)
		return BB;
}

Job ler_jobs(int n){
	int i;
	Job vet = (Job*)malloc(n*sizeof(Job));

	for(i = 0; i < n; i++)
		scanf("%d %d %d", &vet[i].tempo, &vet[i].deadline, &vet[i].multa);

	return vet;
}

int calcula_multa(Job* sequenciaJobs, int numeroJobs){
	int tempo = 0, multa = 0, i;

	for (i = 0; i < numeroJobs; i++){
		tempo = tempo + sequenciaJobs[i].tempo;

		if(tempo > sequenciaJobs[i].deadline)
			multa = multa + sequenciaJobs[i].multa;
		
	}
	return multa;
}
