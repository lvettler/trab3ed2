#ifndef  Job_H_
#define Job_H_ 

struct job{
	int tempo;
	int deadline;
	int multa;
};

typedef struct job *Job;

Job ler_jobs(int n);

int get_tempo(Job j);

int get_deadline(Job j);

int get_multa(Job j);

void libera_job(Job j);

#endif