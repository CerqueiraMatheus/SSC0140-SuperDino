#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

namespace Keyboard {
    enum Arrow {
        UP     = 1,
        DOWN   = 2,
        RIGHT  = 3,
        LEFT   = 4,
        START  = 91, // Preceding ASCII code for arrows
        OFFSET = 64  // Corrector from arrows ASCII to enum
    };

    void listen();
}

#endif // KEYBOARD_HPP
