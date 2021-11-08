#include <cctype>
#include <ncurses.h>

#include "message.hpp"
#include "keyboard.hpp"


const int ESC = 27;


void Keyboard::listen() {
    while (true) {
        int key = getch();

        // Pressed ESC
        if (key == ESC && getch() != Arrow::START) {
            Message::send(Message::EXIT);
            break;
        }

        // Pressed an arrow
        else if (key == ESC) {
            Message::send(getch() - Arrow::OFFSET);
        }

        // Pressed a normal key
        else if (key != ERR) {
            Message::send(toupper(key));
        }
    }
}
