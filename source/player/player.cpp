#include "player.hpp"

#include <unistd.h>

#include "game.hpp"
#include "graphics.hpp"
#include "ncurses.h"  // Temporario

Player::Player() {
    x = 75;
    y = GROUND;
    width = 14;
    height = 5;
    velocity = 0;
}

void Player::move() {
    y -= velocity;
    velocity -= Game::GRAVITY;

    // Checa pelo contato com o chão
    if (grounded()) {
        y = GROUND;
        velocity = 0;
    }
}

void Player::jump() {
    // Pula se estiver no chão
    if (grounded()) {
        velocity = 1.5;
    }
}

void Player::duck() {
    if (!grounded()) {
        velocity -= .9;
    }
}

bool Player::grounded() { return y >= GROUND; }
