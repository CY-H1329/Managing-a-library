CFLAGS = -g -ggdb -Wall -Wextra -pedantic
CC = gcc

PROGRAMS = main

.PHONY:	all clean

.SUFFIX:

all: $(PROGRAMS)

main: main.o vitesse.o biblioLC.o entreeSortieLC.o biblioH.o entreeSortieH.o
	$(CC) -o $@ $(CFLAGS) $^

main.o: main.c vitesse.h biblioLC.h entreeSortieLC.h biblioH.h entreeSortieH.h
	gcc -c $(CFLAGS) main.c

vitesse.o: vitesse.c vitesse.h biblioLC.h entreeSortieLC.h biblioH.h entreeSortieH.h
	gcc -c $(CFLAGS) vitesse.c

biblioH.o : biblioH.c biblioH.h
	gcc -c $(CFLAGS) biblioH.c

entreeSortieH.o : entreeSortieH.c biblioH.h entreeSortieH.h
	gcc -c $(CFLAGS) entreeSortieH.c

biblioLC.o : biblioLC.c biblioLC.h
	gcc -c $(CFLAGS) biblioLC.c

entreeSortieLC.o : entreeSortieLC.c biblioLC.h entreeSortieLC.h
	gcc -c $(CFLAGS) entreeSortieLC.c

clean:
	rm -f *.o *~ $(PROGRAMS)
