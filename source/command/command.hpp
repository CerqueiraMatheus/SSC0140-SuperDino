#ifndef COMMAND_HPP
#define COMMAND_HPP

namespace Command {
    enum {
        NONE  = -1,
        JUMP  = 0,
        DUCK  = 1,
        RESET = 2
    };

    int receive();
    void listen();
}

#endif  // COMMAND_HPP
