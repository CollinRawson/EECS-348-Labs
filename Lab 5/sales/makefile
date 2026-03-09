CC=gcc
CFLAGS=-c -Wall

all: prog

prog: sales.o 
	$(CC) sales.o -o prog

sales.o: sales.c
	$(CC) $(CFLAGS) sales.c

clean:
	rm -rf *.o *.gch *.exe