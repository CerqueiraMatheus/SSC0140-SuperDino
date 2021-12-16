#include <mutex>
#include <queue>
#include <ncurses.h>

#include "game.hpp"
#include "command.hpp"

using namespace std;


namespace Command {
    const int ESC = 27;
    void send(int command);

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
        // Detecta teclas pressionadas
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
