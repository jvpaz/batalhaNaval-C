CC = gcc
CFLAGS = -Wall -g -I./include
SRC = src/tabuleiro.c src/navios.c src/jogada.c
OBJ = $(SRC:.c=.o)

all: main

main: lib
	$(CC) $(CFLAGS) src\main.c -o main -L. -lnaval 

lib: $(OBJ)
	ar rcs libnaval.a $(OBJ)

clean:
	del /f src\*.o *.a main.exe

