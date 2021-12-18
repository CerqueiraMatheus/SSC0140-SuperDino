#include <random>
#include <ncurses.h>

#include "game.hpp"
#include "player.hpp"
#include "obstacle.hpp"

using namespace std;


Obstacle::Obstacle() {
    // Define se é um obstáculo de chão ou voador
    if (rand() % 7 > 1) {
        x = getmaxx(stdscr) - 10;
        y = Game::GROUND - 1;
    }
    else {
        x = getmaxx(stdscr) - 10;
        y = Game::GROUND - 5;
    }

    width = 7;
    height = 5;

    velocity = 1.3;
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
        mvprintw(y - 5, x - 1, "    _     ");
        mvprintw(y - 4, x - 1, " _ ( )    ");
        mvprintw(y - 3, x - 1, "( \\| | _ ");
        mvprintw(y - 2, x - 1, " \\,. |/ )");
        mvprintw(y - 1, x - 1, "   |  /'  ");
        mvprintw(y,     x - 1, "   | |    ");
    }
}

bool Obstacle::hits(Player& player) {
    pair<int, int> dimensions = player.dimensions();
    pair<float, float> position = player.position();

    // Calcula a colisão retangular
    return (
        x < position.first  + dimensions.first  &&
        y > position.second - dimensions.second &&
        position.first  < x + width             &&
        position.second > y - height
    );
}

bool Obstacle::flying() {
    return y < Game::GROUND - 1;
}


Obstacles::Obstacles() {
    cooldown = 0;
    srand(time(nullptr));
}

void Obstacles::draw() {
    for (Obstacle& obstacle : obstacles) {
        obstacle.draw();
    }
}

void Obstacles::update() {
    bool remove = false;

    // Adiciona um obstáculo
    if (rand() % 75 == 0 && cooldown > 30) {
        obstacles.emplace_front();
        cooldown = 0;
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

    cooldown++;
}

bool Obstacles::hits(Player& player) {
    for (Obstacle& obstacle : obstacles) {
        if (obstacle.hits(player)) {
            return true;
        }
    }

    return false;
}
