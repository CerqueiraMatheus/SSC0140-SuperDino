CC = g++
BIN = main
LIB = -lpthread -lncurses
DIR = -I terminal -I command -I player -I game
FLAG = -Wall -Werror
SOURCE = main.cpp terminal/*.cpp command/*.cpp player/*.cpp game/*.cpp

all:
	@$(CC) $(SOURCE) -o $(BIN) $(LIB) $(DIR) $(FLAG)

run:
	@./$(BIN)
