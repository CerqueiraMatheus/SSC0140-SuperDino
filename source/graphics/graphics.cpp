#include "graphics.hpp"

#include <ncurses.h>
#include <unistd.h>

void Graphics::draw_player(int x, int y, char c) {
    // Limpa
    clear();

    // Bordas 
    box(stdscr, 20, 0);
    
    // Player
    mvaddch(y, x, c);
}