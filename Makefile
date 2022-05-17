CC=gcc
CFLAGS=-O2 -Wall

all: main

main: main.c drinks.o money.o processing.o administration.o
	$(CC) $(CFLAGS) -o main $^

%o: %c %h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o main