#ifndef  JOB_H_
#define JOB_H_ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct job{
	int tempo;
	int deadline;
	int multa;
	int id;
}*tJob;

tJob criaJob(int id);

tJob lerJob(int id);

tJob copiaJob(tJob j);

int getTempo(tJob j);

int getDeadline(tJob j);

int getMulta(tJob j);

int getId(tJob j);

void liberaJob(void* j);

#endif