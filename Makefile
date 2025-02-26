CC = gcc
CFLAGS = -Wall -g -I./include
SRC = src/tabuleiro.c src/navios.c src/jogada.c
OBJ = $(SRC:.c=.o)

all: main

main: lib
	$(CC) $(CFLAGS) src\batalhaNaval.c -o batalhaNaval -L. -lnaval 

lib: $(OBJ)
	ar rcs libnaval.a $(OBJ)

clean:
	del /f src\*.o *.a batalhaNaval.exe

