#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {
private:
    int x;
    int y;
    int width;
    int height;
    int velocity;
    bool ground();

public:
    Player();
    void move();
    void jump();
    void crouch();
};

#endif // PLAYER_HPP
