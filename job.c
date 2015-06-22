#include "job.h"
#include <stdio.h>
#include <stdlib.h>

Job ler_jobs(int n){
	int i;
	Job vet = (Job)malloc(n*sizeof(Job));

	for(i = 0; i < n; i++)
		scanf("%d %d %d", &vet[i].tempo, &vet[i].deadline, &vet[i].multa);

	return vet;
}

int get_tempo(Job j){
	return j->tempo;
}

int get_deadline(Job j){
	return j->deadline;
}

int get_multa(Job j){
	return j->multa;
}

void libera_job(Job j){
	FREE(j);
}