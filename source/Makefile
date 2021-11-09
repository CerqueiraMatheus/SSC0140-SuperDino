CC = g++
BIN = main
LIB = -lpthread -lncurses
DIR = -I terminal -I keyboard -I message -I controller
FLAG = -Wall -Werror
SOURCE = main.cpp terminal/*.cpp keyboard/*.cpp message/*.cpp controller/*.cpp

all:
	@$(CC) $(SOURCE) -o $(BIN) $(LIB) $(DIR) $(FLAG)

run:
	@./$(BIN)
