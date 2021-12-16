#include <mutex>
#include <thread>
#include <chrono>

#include "game.hpp"
#include "player.hpp"
#include "command.hpp"
#include "graphics.hpp"

using namespace std;
using namespace chrono;


namespace Game {
    const int FPS = 60;
    void update(Player& player);

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
    auto frame = system_clock::now();

    while (running()) {
        // Calcula o próximo frame
        frame += milliseconds(1000 / FPS);

        update(player);
        Graphics::draw(player);

        // Espera até o próximo frame
        this_thread::sleep_until(frame);
    }
}

void Game::update(Player& player) {
    // Executa o comando
    switch (Command::receive()) {
        case Command::JUMP:
            player.jump();
            break;

        case Command::DUCK:
            player.duck();
            break;

        case Command::RESET:
            break;
    }

    player.move();
}
