#include <ncurses.h>

#include "game.hpp"
#include "player.hpp"
#include "graphics.hpp"


Player::Player() {
    x = 15;
    y = Game::GROUND - 1;

    width = 14;
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
        velocity -= .9;
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
        mvprintw(y - 3, x, "          __"   );
        mvprintw(y - 2, x, ",___.---¨`o o"  );
        mvprintw(y - 1, x, " '-.__ )_,\\_/)");
        mvprintw(y    , x, "     / \\"      );
    }

    // Sprite de pé
    else {
        mvprintw(y - 5, x, "          __"   );
        mvprintw(y - 4, x, "         /o o"  );
        mvprintw(y - 3, x, "        / \\_/)");
        mvprintw(y - 2, x, ",___.--` /"     );
        mvprintw(y - 1, x, " '-.__ )/'"     );
        mvprintw(y,     x, "     / \\"      );
    }
}


bool Player::jumping() {
    return y < Game::GROUND - 1;
}

bool Player::ducking() {
    return height == 3;
}
