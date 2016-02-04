#compiler options
CC=g++ -std=c++11
CFLAGS=-g -Wall -Werror
#SFMLFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
VPATH=src incld
#file
EXE=tictactoe

all: main.o game.o 
	$(CC) $(CFLAGS) $^ -o $(EXE)

main.o: main.cpp game.cpp header.h
	$(CC) $(CFLAGS) -c $^

game.o: game.cpp header.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(EXE)
