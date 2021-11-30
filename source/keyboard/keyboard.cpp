#include <cctype>
#include <ncurses.h>

#include "game.hpp"
#include "command.hpp"
#include "keyboard.hpp"


const int ESC = 27;

enum Arrow {
    START  = 91, // Preceding ASCII code for arrows
    UP     = 65,
    DOWN   = 66,
    RIGHT  = 67,
    LEFT   = 68
};


void Keyboard::listen() {
    while (Game::running()) {
        int key;
        while ((key = getch()) == ERR);

        // Pressed ESC
        if (key == ESC && getch() != Arrow::START) {
            Game::exit();
            break;
        }

        // Pressed an arrow
        else if (key == ESC) {
            switch (getch()) {
            case Arrow::UP:
                Command::send("JUMP", 1);
                break;
            
            case Arrow::DOWN:
                Command::send("CROUCH", 1);
                break;
            }
        }

        // Pressed a normal key
        else {
            switch (toupper(key)) {
            case 'W':
                Command::send("JUMP", 0);
                break;
            
            case 'S':
                Command::send("CROUCH", 0);
                break;
            }
        }
    }
}
