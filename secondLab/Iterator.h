#ifndef CIRCULARBUFFERITERATOR_H
#define CIRCULARBUFFERITERATOR_H

#include "CircularBuffer.h"

class CircularBufferIterator {
    private:

    CircularBuffer& buffer; 
    size_t currentIndex;    
    size_t initialSize;   

    public:
    CircularBufferIterator(CircularBuffer& buffer);

    void start();

    bool finish() const;

    void next();

    int getValue() const;
};

#endif 