#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <deque>
#include "player.hpp"

class Obstacle {
    private:
    int x;
    int y;
    int width;
    int height;
    int velocity;

    public:
    Obstacle();
    void move();
    void draw();
    bool hits(Player &player);

    private:
    bool flying();

    friend class Obstacles;
};

class Obstacles {
    private:
    int cooldown;
    std::deque<Obstacle> obstacles;

    public:
    Obstacles();
    void draw();
    void update();
    bool hits(Player &player);
};

#endif // OBSTACLE_HPP
