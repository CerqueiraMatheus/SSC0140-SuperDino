#include "graphics.hpp"

#include <ncurses.h>
#include <unistd.h>

void Graphics::draw_player(int x, int y, char c) {
    // Limpa
    clear();

    // Bordas 
    //box(stdscr, 20, 0);
    
    // Player
    //mvaddch(y, x, c);
    mvprintw(y-4, x, "          e-e  ");
	mvprintw(y-3, x, "        /(\\_/)");
	mvprintw(y-2, x, ",___.--` /'-` ");
	mvprintw(y-1, x, " '-._, )/'");
	mvprintw(y, x,   "      /\\");
    /*
"                                                         ."
"                                                   .'  <0>'-.._"
"                                                  /  /.--.__\")\""
"                                                 |   \\   .-'~"
"                                                 |  :  -'/"
"                                                /:.  :.-'"
"__                                     | : '. |"
"'--.  '--------.__       .----.-----./      :/"
"        '--.            `'----/       '-.       :/"
"              '-.__           :           \\   .'  )/"
"                    '---.           .-'   ] /  /"
"                         '-.      /     / / /"
"                             _ .-'__.-'< |  _"
"                               <__.\\    __---.7"
"                              |   /'=r.-'     \\ =/"
"                          .--'   /            ./'>"
"                        .'   .-'"
"   snd                 / .--'"
"                      /,/"
"                      |/`)"
*/
}