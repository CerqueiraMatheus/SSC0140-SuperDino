#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
using namespace std;

namespace Command {
    void send(string command, int target);
    string receive(int receiver);
}

#endif // COMMAND_HPP
