#include "graphics.hpp"

#include <ncurses.h>
#include <unistd.h>

void Graphics::draw_player(int x, int y, char c) {
    // Limpa
    clear();

    // Bordas 
    //box(stdscr, 20, 0);
    
    // Player
    mvprintw(y - 5, x, "          __"   );
    mvprintw(y - 4, x, "         /o-o"  );
    mvprintw(y - 3, x, "        / \\_/)");
    mvprintw(y - 2, x, ",___.--` /"     );
    mvprintw(y - 1, x, " '-.__ )/'"     );
    mvprintw(y    , x, "     / \\"      );
}