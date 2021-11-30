#include <queue>
#include <mutex>
#include <cctype>
#include <ncurses.h>

#include "game.hpp"
#include "command.hpp"

using namespace std;


const int ESC = 27;


namespace Command {
    // Região crítica
    mutex semaphore;
    queue<int> commands;
}


void Command::send(int command) {
    // Adiciona o comando à fila
    semaphore.lock();
    commands.push(command);
    semaphore.unlock();
}

int Command::receive() {    
    semaphore.lock();

    // Checa pela existência de comandos
    if (commands.empty()) {
        semaphore.unlock();
        return NONE;
    }

    // Remove o comando da fila
    int command = commands.front();
    commands.pop();

    semaphore.unlock();
    return command;
}


void Command::listen() {
    while (Game::running()) {
        switch (getch()) {
        case ESC:
            Game::exit();
            break;
        
        case KEY_UP:
            send(JUMP);
            break;
        
        case KEY_DOWN:
            send(DUCK);
            break;
        
        case ' ':
            send(RESET);
            break;
        }
    }
}
