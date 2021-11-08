#include <thread>

#include "terminal.hpp"
#include "keyboard.hpp"

using namespace std;


int main() {
    // Terminal configuration
    Terminal terminal = Terminal();

    thread listener(Keyboard::listen);
    listener.join();
    
    return 0;
}
