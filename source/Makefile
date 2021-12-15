CC   = g++
BIN  = main
LIB  = -lpthread -lncurses
DIR  = -I command  -I game -I player -I terminal -I graphics
FLAG = -Wall -Werror
SRC  = main.cpp command/*.cpp game/*.cpp player/*.cpp terminal/*.cpp graphics/*.cpp

all:
	@$(CC) $(SRC) -o $(BIN) $(LIB) $(DIR) $(FLAG)

run:
	@./$(BIN)
