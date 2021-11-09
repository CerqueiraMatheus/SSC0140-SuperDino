#include "ncurses.h" // Temporary
#include "player.hpp"


const int GRAVITY = 1;


Player::Player() {
    x = 0;
    y = 0;
    width = 15;
    height = 15;
    velocity = 0;
}

void Player::move() {
    y += velocity;
    velocity -= GRAVITY;
    
    if (ground()) {
        y = 0;
        velocity = 0;
    }
}

void Player::jump() {
    printw("Player jump!\n"); // Temporary

    if (ground()) {
        velocity = 10;
    }
}

void Player::crouch() {
    printw("Player crouch!\n"); // Temporary

    // TODO
}

bool Player::ground() {
    return y <= 0;
}
