#include <string>
#include <ncurses.h>

#include "game.hpp"
#include "player.hpp"
#include "graphics.hpp"

using namespace std;


namespace Graphics {
    void background();
}


void Graphics::draw(Player& player) {
    // Limpa a tela
    clear();

    background();
    player.draw();

    // Atualiza a tela
    refresh();
}


void Graphics::background() {
    // Desenha o chão
    int width = getmaxx(stdscr);
    string ground(width - 1, '-');
    mvprintw(Game::GROUND, 0, ground.c_str());

    // Desenha o sol
    mvprintw(1, width - 30, "      ;   :   ;"      );
	mvprintw(2, width - 30, "   .   \\_,!,_/   ,"  );
	mvprintw(3, width - 30, "    `.,'     `.,'"    );
	mvprintw(4, width - 30, "     /         \\"    );
	mvprintw(5, width - 30, "~ -- |         | -- ~");
	mvprintw(6, width - 30, "     \\         /"    );
	mvprintw(7, width - 30, "    ,'`._   _.'`."    );
	mvprintw(8, width - 30, "   '   / `!` \\   `"  );
	mvprintw(9, width - 30, "      ;   :   ;"      );
}
