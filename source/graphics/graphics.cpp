#include "graphics.hpp"

#include <ncurses.h>
#include <unistd.h>
#include <string.h>

void Graphics::draw_player(int x, int y, char c) {
    // Limpa
    clear();

    int h, w;
    getmaxyx(stdscr, h, w);
    w += h;
    w -= h;
    char floor[w];
    memset(floor, '-', w);
    mvprintw(21, 0, floor);

    mvprintw(y - 5, x, "          __"   );
    mvprintw(y - 4, x, "         /@-@"  );
    mvprintw(y - 3, x, "        / \\_/)");
    mvprintw(y - 2, x, ",___.--` /"     );
    mvprintw(y - 1, x, " '-.__ )/'"     );
    mvprintw(y    , x, "     / \\"      );

    refresh();
}