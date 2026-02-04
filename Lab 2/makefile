CC=g++
CFLAGS=-c -Wall

all: prog

prog: main.o isEven.o isEven.h.gch isOdd.o isOdd.h.gch
	$(CC) main.o isEven.o isOdd.o -o prog

main.o: main.c
	$(CC) $(CFLAGS) main.c

isEven.o: isEven.c
	$(CC) $(CFLAGS) isEven.c

isEven.h.gch: isEven.h
	$(CC) $(CFLAGS) isEven.h

isOdd.o: isOdd.c
	$(CC) $(CFLAGS) isOdd.c

isOdd.h.gch: isOdd.h
	$(CC) $(CFLAGS) isOdd.h

clean:
	rm -rf *.o *.gch
