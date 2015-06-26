

all: listaGen.o permuta.o algoritmos.o job.o util.o
	gcc -Wall -g -pedantic -std=c99 *.o main.c -o trab4
	#pdflatex trab4.tex


listaGen.o: listaGen.h listaGen.c
	gcc -Wall -g -pedantic -std=c99 -c listaGen.c 


permuta.o: permuta.h permuta.c
	gcc -Wall -g -pedantic -std=c99 -c permuta.c 


algoritmos.o: algoritmos.h algoritmos.c
	gcc -Wall -g -pedantic -std=c99 -c algoritmos.c 


job.o: job.h job.c
	gcc -Wall -g -pedantic -std=c99 -c job.c 


util.o: util.h util.c
	gcc -Wall -g -pedantic -std=c99 -c util.c 

run:
	./trab4 4 bs < entrada.txt

clean:
	rm *.o trab4

easy:
	gcc -c util.c
	gcc -c listaGen.c
	gcc -c job.c
	gcc -c permuta.c
	gcc -c algoritmos.c
	gcc -c main.c
	gcc util.o listaGen.o job.o permuta.o algoritmos.o main.o -o trab4
	#pdflatex trab4.tex