#include <ncurses.h>

#include "terminal.hpp"


Terminal::Terminal() {
    // Ncurses setup
    initscr();
    cbreak();
    noecho();
    scrollok(stdscr, true);
    nodelay(stdscr, true);
}

Terminal::~Terminal() {
    // Ncurses teardown
    endwin();
}
