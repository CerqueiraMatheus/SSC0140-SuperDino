#include <thread>

#include "command.hpp"
#include "game.hpp"
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
