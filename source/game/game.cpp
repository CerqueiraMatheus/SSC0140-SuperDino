#include <mutex>
#include <thread>
#include <chrono>

#include "game.hpp"
#include "player.hpp"
#include "command.hpp"

using namespace std;
using namespace chrono;


const int FPS = 60;


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


void update(Player& player) {
    switch (Command::receive()) {
    case Command::JUMP:
        player.jump();
        break;
    
    case Command::DUCK:
        player.crouch();
        break;
    
    case Command::RESET:
        break;
    }

    player.move();
}

void Game::loop() {
    Player player;
    auto frame = system_clock::now();

    while (running()) {
        // Calcula o próximo frame
        frame += milliseconds(1000 / FPS);

        update(player);
        // display()

        // Espera até o próximo frame
        this_thread::sleep_until(frame);
    }
}
