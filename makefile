CC=gcc
CFLAGS=-I.

list: main.o node.o
	$(CC) -o list main.c node.c -g -I.

run:
	./list

clean:
	rm list main.o node.o