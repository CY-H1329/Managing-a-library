CFLAGS = -g -ggdb -Wall -Wextra -pedantic
CC = gcc

PROGRAMS = main

.PHONY:	all clean

.SUFFIX:

all: $(PROGRAMS)

main: main.o biblioLC.o entreeSortieLC.o
	$(CC) -o $@ $(CFLAGS) $^

main.o: main.c biblioLC.h entreeSortieLC.h
	gcc -c $(CFLAGS) main.c

biblioLC.o : biblioLC.c biblioLC.h
	gcc -c $(CFLAGS) biblioLC.c

entreeSortieLC.o : entreeSortieLC.c biblioLC.h entreeSortieLC.h
	gcc -c $(CFLAGS) entreeSortieLC.c

clean:
	rm -f *.o *~ $(PROGRAMS)
