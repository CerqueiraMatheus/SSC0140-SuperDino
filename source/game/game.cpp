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
        switch (Command::receive()) {
            case Command::JUMP:
                player.jump();
                break;
        
            case Command::DUCK:
                player.crouch();
                break;
        }
        
        player.move();
    }
}
