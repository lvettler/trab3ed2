#ifndef LISTAGEN_H_
#define LISTAGEN_H_

typedef struct no{
	void *item;
	struct no* prox;
}*no;

no criaNo(void* item);

void liberaNo(no n, void f(void*));

typedef struct lista{
	no ini;
	no fim;
	int tam;
}*listaGen;

listaGen criaListaGen();

void liberaListaGen(listaGen l, void f(void*));

void pushFront(listaGen l, no n);

void pushBack(listaGen l, no conteudo);

no popFront(listaGen l);

no popBack(listaGen l);

void* getItem(no n);

int getTam(listaGen l);

no getIni(listaGen l);

no getFim(listaGen l);

void percorreListaGen(listaGen l, void cb(void*));

#endif
