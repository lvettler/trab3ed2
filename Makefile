all:
	gcc -c util.c
	gcc -c listaGen.c
	gcc -c job.h
	gcc -c permuta.c
	gcc -c algoritmos.c
	gcc -c main.c
	gcc util.o listaGen.o job.o permuta.o algoritmos.o main.o -o trab4
	#pdflatex trab4.tex