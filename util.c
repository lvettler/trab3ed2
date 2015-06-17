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

int calcula_multa(Job sequenciaJobs, int numeroJobs){
	int tempo = 0, multa = 0, i;

	for (i = 0; i < numeroJobs; i++){
		tempo = tempo + sequenciaJobs[i].tempo;

		if(tempo > sequenciaJobs[i].deadline)
			multa = multa + sequenciaJobs[i].multa;
		
	}
	return multa;
}
