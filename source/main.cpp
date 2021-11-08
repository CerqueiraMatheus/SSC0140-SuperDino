#include <thread>

#include "terminal.hpp"
#include "keyboard.hpp"
#include "controller.hpp"

using namespace std;


int main() {
    // Terminal configuration
    Terminal terminal;

    thread listener(Keyboard::listen);
    thread controller(Controller::control);

    listener.join();
    controller.join();
    
    return 0;
}
