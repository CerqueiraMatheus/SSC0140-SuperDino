#include "game.hpp"
#include "player.hpp"

#include "ncurses.h" // Temporario


Player::Player() {
    x = 0;
    y = 0;
    width = 15;
    height = 15;
    velocity = 0;
}

void Player::move() {
    // Atualiza a velocidade do pulo/queda
    y += velocity;
    velocity -= Game::GRAVITY;
    
    // Checa pelo contato com o chão
    if (grounded()) {
        y = 0;
        velocity = 0;
    }
}

void Player::jump() {
    printw("Jump!\n"); // Temporario

    // Pula se estiver no chão
    if (grounded()) {
        velocity = 10;
    }
}

void Player::duck() {
    printw("Duck!\n"); // Temporario

    // TODO
}

bool Player::grounded() {
    return y <= 0;
}
