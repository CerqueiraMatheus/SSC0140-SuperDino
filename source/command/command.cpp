#include <queue>
#include <mutex>

#include "game.hpp"
#include "command.hpp"

using namespace std;


namespace Command {
    mutex semaphore;
    queue<string> commands[Game::NUMBER];
}


void Command::send(string command, int target) {
    semaphore.lock();
    commands[target].push(command);
    semaphore.unlock();
}

string Command::receive(int receiver) {    
    semaphore.lock();

    // Check commands availability
    if (commands[receiver].empty()) {
        semaphore.unlock();
        return "NONE";
    }

    string command = commands[receiver].front();
    commands[receiver].pop();

    semaphore.unlock();
    return command;
}
