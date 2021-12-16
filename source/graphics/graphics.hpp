#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include "player.hpp"
#include "obstacle.hpp"

namespace Graphics {
    const int FPS = 60;

    void draw(Player& player, Obstacles& obstacles);
}

#endif // GRAPHICS_HPP
