CC=gcc
FLAGS=-Wall -g
FILENAME=program-1
#FILENAME=program-2
#FILENAME=program-3
#FILENAME=program-4

all: build run

build:
	$(CC) $(FLAGS) $(FILENAME).c -o $(FILENAME).out

run:
	$(FILENAME).out

clean:
	rm -fr $(FILENAME).out $(FILENAME).out.dSYM
