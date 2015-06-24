#ifndef ALGORITMOS_H_
#define ALGORITMOS_H_

#include <string.h>
#include <stdlib.h>
#include "listaGen.h"
#include "permuta.h"
#include "util.h"

tPermuta branchBound(listaGen l);

tPermuta beamSearch(listaGen l, int w);

#endif