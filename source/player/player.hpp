#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <utility>

class Player {
    private:
    float x;
    float y;
    int timer;
    int width;
    int height;
    float velocity;

    public:
    Player();
    void move();
    void jump();
    void duck();
    void draw();
    std::pair<int, int> dimensions();
    std::pair<float, float> position();

    private:
    bool jumping();
    bool ducking();
};

#endif  // PLAYER_HPP
