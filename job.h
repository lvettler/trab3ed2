#ifndef  JOB_H_
#define JOB_H_ 

typedef struct job{
	int tempo;
	int deadline;
	int multa;
	int id;
}*tJob;

tJob criaJob();

tJob lerJob(int id);

int getTempo(tJob j);

int getDeadline(tJob j);

int getMulta(tJob j);

void liberaJob(void* j);

#endif