#include <random>
#include <ncurses.h>

#include "game.hpp"
#include "obstacle.hpp"


Obstacle::Obstacle() {
    x = getmaxx(stdscr) - 15;
    y = Game::GROUND - (rand() % 4 ? 1 : 5);

    width = 8;
    height = 5;

    velocity = 1;
}

void Obstacle::move() {
    x -= velocity;
}

void Obstacle::draw() {
    // Sprite voador
    if (flying()) {
        mvprintw(y - 4, x, "#########");
        mvprintw(y - 3, x, "#########");
        mvprintw(y - 2, x, "#########");
        mvprintw(y - 1, x, "#########");
        mvprintw(y,     x, "#########");
    }

    // Sprite no chão
    else {
        mvprintw(y - 5, x, "    _ "    );
        mvprintw(y - 4, x, " _ ( )   " );
        mvprintw(y - 3, x, "( \\| | _" );
        mvprintw(y - 2, x, " \\,. |/ )");
        mvprintw(y - 1, x, "   |  /'"  );
        mvprintw(y,     x, "   | |"    );
    }
}

bool Obstacle::flying() {
    return y < Game::GROUND - 1;
}


Obstacles::Obstacles() {
    counter = 0;
}

void Obstacles::draw() {
    for (Obstacle& obstacle : obstacles) {
        obstacle.draw();
    }
}

void Obstacles::update() {
    bool remove = false;

    // Adiciona um obstáculo
    if (counter % 60 == 0) {
        obstacles.emplace_front();
    }

    for (Obstacle& obstacle : obstacles) {
        obstacle.move();

        // Marca que deve remover um obstáculo
        if (obstacle.x < 0) {
            remove = true;
        }
    }

    // Remove o obstáculo mais antigo
    if (remove) {
        obstacles.pop_back();
    }

    counter++;
}
