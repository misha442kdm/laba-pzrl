CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJ = main.o calc.o

all: calc

calc: $(OBJ)
	$(CC) $(CFLAGS) -o calc $(OBJ)

main.o: main.c calc.h
	$(CC) $(CFLAGS) -c main.c

calc.o: calc.c calc.h
	$(CC) $(CFLAGS) -c calc.c

clean:
	rm -f *.o calc

run: calc
	./calc
