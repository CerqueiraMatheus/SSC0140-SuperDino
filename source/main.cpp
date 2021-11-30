#include <thread>

#include "game.hpp"
#include "terminal.hpp"
#include "keyboard.hpp"

using namespace std;


int main() {
    // Configuração do terminal
    Terminal terminal;

    thread keyboard(Keyboard::listen);
    thread game(Game::loop);

    keyboard.join();
    game.join();
    
    return 0;
}
