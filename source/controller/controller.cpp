#include <cctype>
#include <ncurses.h> // Temporary

#include "message.hpp"
#include "keyboard.hpp"
#include "controller.hpp"


void Controller::control() {
    while (true) {
        int key = Message::receive();

        // Program ending
        if (key == Message::EXIT) {
            break;
        }

        // Message received
        else if (key != Message::NONE) {
            switch (toupper(key)) {
            case 'W':
                printw("Player 1 UP\n");
                break;
            
            case 'S':
                printw("Player 1 DOWN\n");
                break;
            
            case Keyboard::Arrow::UP:
                printw("Player 2 UP\n");
                break;
            
            case Keyboard::Arrow::DOWN:
                printw("Player 2 DOWN\n");
                break;
            }
        }
    }
}
