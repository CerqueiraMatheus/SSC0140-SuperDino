#include <mutex>

#include "game.hpp"
#include "player.hpp"
#include "command.hpp"

using namespace std;


namespace Game {
    // Região crítica
    mutex semaphore;
    bool run = true;
}


bool Game::running() {
    // Checa pela execução do jogo
    semaphore.lock();
    bool temporary = run;
    semaphore.unlock();

    return temporary;
}

void Game::exit() {
    // Finaliza a execução do jogo
    semaphore.lock();
    run = false;
    semaphore.unlock();
}

void Game::loop() {
    Player player;

    while (running()) {
        string command = Command::receive(0);

        if (command == "JUMP") {
            player.jump();
        }
        else if (command == "CROUCH") {
            player.crouch();
        }
        
        player.move();
    }
}
