#include <thread>

#include "game.hpp"
#include "command.hpp"
#include "terminal.hpp"

using namespace std;


int main() {
    // Configuração do terminal
    Terminal terminal;

    thread command(Command::listen);
    thread game(Game::loop);

    command.join();
    game.join();
    
    return 0;
}
