CC = gcc
CFLAGS = -Wall -g

all: program

program: main.o storage.o
    $(CC) $(CFLAGS) -o program main.o storage.o

main.o: main.c
    $(CC) $(CFLAGS) -c main.c

storage.o: storage.c storage.h
    $(CC) $(CFLAGS) -c storage.c

clean:
    rm -f *.o program
