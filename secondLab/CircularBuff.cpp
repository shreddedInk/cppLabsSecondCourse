#include "CircularBuffer.h"

CircularBuffer::CircularBuffer(size_t size) 
    : capacity(size), buffer(new int[size]), head(0), tail(0), full(false) {}

CircularBuffer::~CircularBuffer() {
    delete[] buffer;
}

void CircularBuffer::push(int value) {
    if (full) {
        throw std::overflow_error("Buffer is full");
    }
    buffer[tail] = value;
    tail = (tail + 1) % capacity;
    full = (tail == head);
}

int CircularBuffer::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Buffer is empty");
    }
    int value = buffer[head];
    head = (head + 1) % capacity;
    full = false;
    return value;
}

int CircularBuffer::peek() const {
    if (isEmpty()) {
        throw std::underflow_error("Buffer is empty");
    }
    return buffer[head];
}

size_t CircularBuffer::size() const {
    if (full) {
        return capacity;
    }
    if (tail >= head) {
        return tail - head;
    }
    return capacity - head + tail;
}

void CircularBuffer::clear() {
    head = tail;
    full = false;
}

bool CircularBuffer::isEmpty() const {
    return !full && (head == tail);
}

bool CircularBuffer::isFull() const {
    return full;
}