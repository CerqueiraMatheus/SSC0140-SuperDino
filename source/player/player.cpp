#include <ncurses.h>

#include "game.hpp"
#include "player.hpp"
#include "graphics.hpp"

using namespace std;


Player::Player() {
    x = 15;
    y = Game::GROUND - 1;

    width = 12;
    height = 5;

    timer = 0;
    velocity = 0;
}

void Player::move() {
    timer--;
    y -= velocity;
    velocity -= Game::GRAVITY;

    // Para de cair quando encostar no chão
    if (!jumping()) {
        y = Game::GROUND - 1;
        velocity = 0;
    }

    // Levanta quando o tempo acabar
    if (timer <= 0) {
        height = 5;
    }
}

void Player::jump() {
    // Pula se estiver no chão
    if (!jumping()) {
        height = 5;
        velocity = 1.5;
    }
}

void Player::duck() {
    // Cai mais rápido se estiver no ar
    if (jumping()) {
        velocity -= .7;
    }

    // Abaixa se estiver no chão
    else {
        height = 3;
        timer = 35;
    }
}

void Player::draw() {
    // Sprite abaixado
    if (ducking()) {
        mvprintw(y - 3, x - 1, "          __   ");
        mvprintw(y - 2, x - 1, ",___.---¨`o o  ");
        mvprintw(y - 1, x - 1, " '-.__ )_,\\_/)");
        mvprintw(y    , x - 1, "     / \\      ");
    }

    // Sprite de pé
    else {
        mvprintw(y - 5, x - 1, "          __   ");
        mvprintw(y - 4, x - 1, "         /o o  ");
        mvprintw(y - 3, x - 1, "        / \\_/)");
        mvprintw(y - 2, x - 1, ",___.--` /     ");
        mvprintw(y - 1, x - 1, " '-.__ )/'     ");
        mvprintw(y,     x - 1, "     / \\      ");
    }
}

pair<int, int> Player::dimensions() {
    return {width, height};
}

pair<float, float> Player::position() {
    return {x, y};
}


bool Player::jumping() {
    return y < Game::GROUND - 1;
}

bool Player::ducking() {
    return height == 3;
}
