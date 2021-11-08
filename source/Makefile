CC = g++
BIN = main
LIB = -lpthread -lncurses
FLAG = -Wall -Werror
SOURCE = main.cpp terminal.cpp keyboard.cpp message.cpp controller.cpp

all:
	@$(CC) $(SOURCE) -o $(BIN) $(LIB) $(FLAG)

run:
	@./$(BIN)
