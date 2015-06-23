#ifndef ALGORITMOS_H_
#define ALGORITMOS_H_

#include "listaGen.h"
#include "permuta.h"

tPermuta branchBound(listaGen l);

tPermuta beamSearch(listaGen l, int w);

#endif