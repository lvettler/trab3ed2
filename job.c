#include "job.h"
#include "util.h"

tJob criaJob(int id){
	tJob j = (tJob)malloc(sizeof(struct job));
	j->tempo = 0;
	j->deadline = 0;
	j->multa = 0;
	j->id = id;
	return j;
}

tJob lerJob(int id){
	tJob j = criaJob(id);
	scanf("%d %d %d", &j->tempo, &j->deadline, &j->multa);
	return j;
}

tJob copiaJob(tJob j){
	tJob c = criaJob(j->id);
	c->tempo = j->tempo;
	c->deadline = j->deadline;
	c->multa = j->multa;
	c->id = j->id;
	return c;
}

int getTempo(tJob j){
	return j->tempo;
}

int getDeadline(tJob j){
	return j->deadline;
}

int getMulta(tJob j){
	return j->multa;
}

int getId(tJob j){
	return j->id;
}

void liberaJob(void* j){
	FREE(j);
}