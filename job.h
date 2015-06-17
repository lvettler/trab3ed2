#ifndef  Job_H_
#define Job_H_ 

struct job{
	int tempo;
	int deadline;
	int multa;
};

typedef struct job *Job;

Job ler_jobs(int n);

#endif