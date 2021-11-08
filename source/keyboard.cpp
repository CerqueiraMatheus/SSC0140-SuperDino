#include <cctype>
#include <ncurses.h>

#include "keyboard.hpp"


const int ESC = 27;

enum Arrow {
    START = 91,
    UP    = 65,
    DOWN  = 66,
    RIGHT = 67,
    LEFT  = 68,
};


void Keyboard::listen() {
    while (true) {
        int key = getch();

        // Pressed ESC
        if (key == ESC && getch() != Arrow::START) {
            break;
        }

        // Pressed an arrow
        else if (key == ESC) {
            switch (getch()) {
            case Arrow::UP:
                printw("UP\n");
                break;
                
            case Arrow::DOWN:
                printw("DOWN\n");
                break;
            }
        }

        // Pressed a normal key
        else {
            switch (toupper(key)) {
            case 'W':
                printw("UP\n");
                break;
            
            case 'S':
                printw("DOWN\n");
                break;
            }
        }
    }
}
