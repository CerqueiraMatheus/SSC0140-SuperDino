#include <ncurses.h>

#include "terminal.hpp"


Terminal::Terminal() {
    // Inicialização da ncurses
    initscr();
    noecho();
    curs_set(false);
    keypad(stdscr, true);
}

Terminal::~Terminal() {
    // Finalização da ncurses
    endwin();
}
