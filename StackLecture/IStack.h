#ifndef ISTACK_H
#define ISTACK_H

template <typename T>
class IStack {
    virtual void push(const T&x) = 0;
    virtual T pop() = 0;
    virtual const T& top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual void clear() = 0;
    virtual size_t size() const = 0;
    virtual ~IStack() {};
}

#endif