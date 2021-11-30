#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {
private:
    int x;
    int y;
    int width;
    int height;
    int velocity;

private:
    bool grounded();

public:
    Player();
    void move();
    void jump();
    void duck();
};

#endif // PLAYER_HPP
