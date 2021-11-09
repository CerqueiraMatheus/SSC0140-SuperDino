#ifndef MESSAGE_HPP
#define MESSAGE_HPP

namespace Message {
    const int NONE = -1;
    const int EXIT = 0;

    void send(int message);
    int receive();
}

#endif // MESSAGE_HPP
