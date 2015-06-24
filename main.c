#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "job.h"
#include "permuta.h"
#include "listaGen.h"
#include "algoritmos.h"

int main(int argc, char **argv)
{

	int numeroJobs;
	numeroJobs = atoi(argv[1]);
	algoritmo tipo = verificaTipo(argv[2]);
	tPermuta p = lerPermuta(numeroJobs);
	no n = criaNo(p);
	listaGen l = criaListaGen();
	pushBack(l, n);
	tPermuta result;

	if(tipo == BS)
	{
		result = beamSearch(l, 5); //TODO: testar esse numero aqui (beamWidth)
	}
	
	else if(tipo == BB)
	{
		result = branchBound(l);
	}

	imprimePermuta(result);
	
	return 0;
}