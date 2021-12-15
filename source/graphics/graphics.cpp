#include "graphics.hpp"

#include <ncurses.h>
#include <unistd.h>

void Graphics::draw_player(int x, int y, char c) {
    // Limpa
    clear();

    // Bordas 
    //box(stdscr, 20, 0);
    
    // Player
    /*
    typedef struct {
        uint_fast16_t x;
        uint_fast16_t y;
    } vec2i;

    typedef struct {
        vec2i offset;
        vec2i bounds;
    
        uint_fast16_t top() { return offset.y; }
        uint_fast16_t bot() { return offset.y + bounds.y; }
        uint_fast16_t left() { return offset.x; }
        uint_fast16_t right() { return offset.x + bounds.x; }
    
        uint_fast16_t width() { return bounds.x; }
        uint_fast16_t height() { return bounds.y; }
    
        bool contains(vec2i a) { return (a.x >= offset.x && a.x < right()) && 
                                        (a.y >= offset.y && a.y < bot()); }
    } rect;

    rect game_area = { { 0, 0 }, { screen_area.width() - 2, screen_area.height() - infopanel_height - 4 } };

    wmove(stdscr, game_area.bot() + 3, 1);
    whline(stdscr, '-', screen_area.width() - 2);
    */
    //mvprintw(21, 0, "\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'");
    int h, w;
    getmaxyx(stdscr, h, w);
    char floor[w] = {'\''}; 
    mvprintw(21, 0, floor);

    mvprintw(y - 5, x, "          __"   );
    mvprintw(y - 4, x, "         /@-@"  );
    mvprintw(y - 3, x, "        / \\_/)");
    mvprintw(y - 2, x, ",___.--` /"     );
    mvprintw(y - 1, x, " '-.__ )/'"     );
    mvprintw(y    , x, "     / \\"      );
}