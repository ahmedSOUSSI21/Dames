all: main 
piece.o: piece.c piece.h
	gcc -c piece.c
	
case.o: case.c case.h
	gcc -c case.c

damier.o: damier.c damier.h
	gcc -c damier.c

main.o: main.c damier.h 
	gcc -c main.c
	
main: main.o piece.o case.o damier.o
	gcc -o main piece.o case.o damier.o main.o 	
