#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {
   private:
    int width;
    int height;
    float velocity;
    const int GROUND = 20;

   private:
    bool grounded();

   public:
    float x;
    float y;
    Player();
    void move();
    void jump();
    void duck();
};

#endif  // PLAYER_HPP
