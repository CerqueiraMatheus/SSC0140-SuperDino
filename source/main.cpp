#include <thread>

#include "game.hpp"
#include "terminal.hpp"
#include "keyboard.hpp"

using namespace std;


int main() {
    // Terminal configuration
    Terminal terminal;

    thread keyboard(Keyboard::listen);

    thread games[Game::NUMBER];
    games[0] = thread(Game::run);
    games[1] = thread(Game::run);

    keyboard.join();
    games[0].join();
    games[1].join();
    
    return 0;
}
