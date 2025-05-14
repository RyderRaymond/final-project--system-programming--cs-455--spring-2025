CC=gcc
FLAGS=-Wall -g
FILENAME=program-1.c
#FILENAME=program-2.c
#FILENAME=program-3.c
#FILENAME=program-4.c

all: build run

build:
	$(CC) $(FLAGS) $(FILENAME).c -o $(FILENAME).out

run:
	$(FILENAME).out

clean:
	rm -fr $(FILENAME).out $(FILENAME).out.dSYM
