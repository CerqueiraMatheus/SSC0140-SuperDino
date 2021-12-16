#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {
   private:
    float x;
    float y;
    int timer;
    int width;
    int height;
    float velocity;

   private:
    bool jumping();
    bool ducking();

   public:
    Player();
    void move();
    void jump();
    void duck();
    void draw();
};

#endif  // PLAYER_HPP
