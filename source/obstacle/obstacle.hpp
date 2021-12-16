#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <deque>

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

    private:
    bool flying();

    friend class Obstacles;
};

class Obstacles {
    private:
    int counter;
    std::deque<Obstacle> obstacles;

    public:
    Obstacles();
    void draw();
    void update();
};

#endif // OBSTACLE_HPP
