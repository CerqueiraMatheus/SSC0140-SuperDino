#ifndef GAME_HPP
#define GAME_HPP

namespace Game {
    const float GRAVITY = .1;
    const int GROUND = 25;

    bool running();
    void exit();
    void loop();
}

#endif // GAME_HPP
