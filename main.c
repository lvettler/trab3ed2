#include <stdio.h>
#include "util.h"
#include "job.h"
#include "permuta.h"

int main(int argc, char **argv)
{
	int numeroJobs, custoMinimo;
	numeroJobs = atoi(argv[1]);
	algoritmo tipo = verifica_tipo(argv[2]);
	Job sequenciaJobs = ler_jobs(numeroJobs);
	custoMinimo = calcula_multa(sequenciaJobs, numeroJobs);
	
	if(tipo == BS)
	{

	}
	
	else if(tipo == BB)
	{

	}
	
	return 0;
}