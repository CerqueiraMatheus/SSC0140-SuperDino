#include <mutex>
#include <thread>
#include <chrono>
#include <utility>

#include "game.hpp"
#include "player.hpp"
#include "command.hpp"
#include "graphics.hpp"
#include "obstacle.hpp"

using namespace std;
using namespace chrono;


namespace Game {
    bool update(Player& player, Obstacles& obstacles);
    void over();

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
    Obstacles obstacles;
    auto frame = system_clock::now();

    while (running()) {
        // Calcula o próximo frame
        frame += milliseconds(1000 / Graphics::FPS);

        // Termina o jogo se o player colidiu
        if (update(player, obstacles) == false) {
            over();

            // Reseta os valores
            player = Player();
            obstacles = Obstacles();
            frame = system_clock::now();

            continue;
        }

        Graphics::draw(player, obstacles);

        // Espera até o próximo frame
        this_thread::sleep_until(frame);
    }
}


bool Game::update(Player& player, Obstacles& obstacles) {
    // Executa o comando
    switch (Command::receive()) {
        case Command::JUMP:
            player.jump();
            break;

        case Command::DUCK:
            player.duck();
            break;
    }

    player.move();
    obstacles.update();

    // Termina o jogo se o player colidiu
    if (obstacles.hits(player)) {
        return false;
    }

    return true;
}

void Game::over() {
    Graphics::over();

    // Aguarda até receber um comando RESET
    while (running() && Command::receive() != Command::RESET);
}
