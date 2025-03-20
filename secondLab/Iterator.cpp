#include "CircularBufferIterator.h"

CircularBufferIterator::CircularBufferIterator(CircularBuffer& buffer) 
    : buffer(buffer), currentIndex(buffer.head), initialSize(buffer.size()) {}

void CircularBufferIterator::start() {
    currentIndex = buffer.head;
    initialSize = buffer.size();
}

void CircularBufferIterator::next() {
    if (finish()) {
        throw std::out_of_range("Iterator has reached the end");
    }
    currentIndex = (currentIndex + 1) % buffer.capacity;
}

bool CircularBufferIterator::finish() const {
    return (currentIndex == buffer.tail) || (initialSize == 0);
}

int CircularBufferIterator::getValue() const {
    if (finish()) {
        throw std::out_of_range("Iterator has reached the end");
    }
    return buffer.buffer[currentIndex];
}