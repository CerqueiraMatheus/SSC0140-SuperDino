#include <queue>
#include <mutex>

#include "message.hpp"


std::mutex semaphore;
std::queue<int> messages;


void Message::send(int message) {
    // Validate message
    if (message == NONE) {
        return;
    }

    // Push message to queue
    semaphore.lock();
    messages.push(message);
    semaphore.unlock();
}

int Message::receive() {
    semaphore.lock();

    // Check for available messages
    if (messages.empty()) {
        semaphore.unlock();
        return NONE;
    }

    // Pop message from queue
    int message = messages.front();
    messages.pop();

    semaphore.unlock();
    return message;
}
