CFLAGS = -g -ggdb -Wall -Wextra -pedantic
CC = gcc

PROGRAMS = main

.PHONY:	all clean

.SUFFIX:

all: $(PROGRAMS)

main: main.o biblioH.o entreeSortieH.o
	$(CC) -o $@ $(CFLAGS) $^

main.o: main.c biblioH.h entreeSortieH.h
	gcc -c $(CFLAGS) main.c

biblioH.o : biblioH.c biblioH.h
	gcc -c $(CFLAGS) biblioH.c

entreeSortieH.o : entreeSortieH.c biblioH.h entreeSortieH.h
	gcc -c $(CFLAGS) entreeSortieH.c

clean:
	rm -f *.o *~ $(PROGRAMS)
