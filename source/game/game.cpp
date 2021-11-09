#include <mutex>

#include "game.hpp"
#include "player.hpp"
#include "command.hpp"

using namespace std;


namespace Game {
    mutex semaphore;
    int current = 0;
}


void Game::run() {
    // Set id
    semaphore.lock();
    int id = current++;
    semaphore.unlock();
    
    Player player;

    while (true) {
        string command = Command::receive(id);

        if (command == "EXIT") {
            break;
        }
        else if (command == "JUMP") {
            player.jump();
        }
        else if (command == "CROUCH") {
            player.crouch();
        }
        
        player.move();
    }
}


