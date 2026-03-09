CC=gcc
CFLAGS=-c -Wall

all: prog

prog: matrix.o 
	$(CC) matrix.o -o prog

matrix.o: matrix.c
	$(CC) $(CFLAGS) matrix.c

clean:
	rm -rf *.o *.gch *.exe