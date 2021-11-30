#include <queue>
#include <mutex>
#include <cctype>
#include <ncurses.h>

#include "game.hpp"
#include "command.hpp"

using namespace std;


const int ESC = 27;

enum Arrow {
    START  = 91, // Preceding ASCII code for arrows
    UP     = 65,
    DOWN   = 66,
    RIGHT  = 67,
    LEFT   = 68
};


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

    // Remove comando da fila
    int command = commands.front();
    commands.pop();

    semaphore.unlock();
    return command;
}


void Command::listen() {
    while (Game::running()) {
        int key;
        while ((key = getch()) == ERR);

        // Pressed ESC
        if (key == ESC && getch() != Arrow::START) {
            Game::exit();
            break;
        }

        // Pressed an arrow
        else if (key == ESC) {
            switch (getch()) {
            case Arrow::UP:
                send(JUMP);
                break;
            
            case Arrow::DOWN:
                send(DUCK);
                break;
            }
        }
    }
}
