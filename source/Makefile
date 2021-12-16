CC   = g++
BIN  = main.out
LIB  = -lpthread -lncurses
DIR  = -I command  -I game -I player -I terminal -I graphics -I obstacle
FLAG = -Wall -Werror
SRC  = main.cpp command/*.cpp game/*.cpp player/*.cpp terminal/*.cpp graphics/*.cpp obstacle/*.cpp

all:
	@$(CC) $(SRC) -o $(BIN) $(LIB) $(DIR) $(FLAG)

run:
	@./$(BIN)
