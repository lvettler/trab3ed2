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