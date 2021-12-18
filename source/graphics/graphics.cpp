#include <string>
#include <ncurses.h>

#include "game.hpp"
#include "player.hpp"
#include "graphics.hpp"
#include "obstacle.hpp"

using namespace std;


namespace Graphics {
    void background();
}


void Graphics::draw(Player& player, Obstacles& obstacles) {
    // Limpa a tela
    clear();

    background();
    player.draw();
    obstacles.draw();

    // Atualiza a tela
    refresh();
}

void Graphics::over() {
    // Limpa a tela
    clear();

    int height, width;
    getmaxyx(stdscr, height, width);

    // Imprime a mensagem de game over
    mvprintw(height / 2 - 3, width / 2 - 27, "   _____                         ____                      ");
    mvprintw(height / 2 - 2, width / 2 - 27, "  / ____|                       / __ \\                    ");
    mvprintw(height / 2 - 1, width / 2 - 27, " | |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __      ");
    mvprintw(height / 2,     width / 2 - 27, " | | |_ |/ _` | '_ ` _ \\ / _ \\ | |  | \\ \\ / / _ \\ '__|");
    mvprintw(height / 2 + 1, width / 2 - 27, " | |__| | (_| | | | | | |  __/ | |__| |\\ V /  __/ |       ");
    mvprintw(height / 2 + 2, width / 2 - 27, "  \\_____|\\__,_|_| |_| |_|\\___|  \\____/  \\_/ \\___|_|  ");

    // Atualiza a tela
    refresh();
}


void Graphics::background() {
    // Desenha o chão
    int width = getmaxx(stdscr);
    string ground(width - 1, '-');
    mvprintw(Game::GROUND, 0, ground.c_str());

    // Desenha o sol
    mvprintw(1, width - 30, "      ;   :   ;      ");
	mvprintw(2, width - 30, "   .   \\_,!,_/   ,  ");
	mvprintw(3, width - 30, "    `.,'     `.,'    ");
	mvprintw(4, width - 30, "     /         \\    ");
	mvprintw(5, width - 30, "~ -- |         | -- ~");
	mvprintw(6, width - 30, "     \\         /    ");
	mvprintw(7, width - 30, "    ,'`._   _.'`.    ");
	mvprintw(8, width - 30, "   '   / `!` \\   `  ");
	mvprintw(9, width - 30, "      ;   :   ;      ");
}
