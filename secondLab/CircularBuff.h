#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

#include <stdexcept>
#include <cstddef>

class CircularBuffer {
    private:
    
    int* buffer;       
    size_t capacity;   
    size_t head;       
    size_t tail;      
    bool full;   

    public:
    CircularBuffer(size_t size);

    ~CircularBuffer();

    void push(int value);

    int pop();
    int peek() const;

    size_t size() const;
    void clear();

    bool isEmpty() const;
    bool isFull() const;

    friend class CircularBufferIterator;
};

#endif 