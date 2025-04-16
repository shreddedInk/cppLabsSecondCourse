#ifndef LIST_H
#define LIST_H

#include "Iterator.h"

template <typename T>
class List {
protected:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& value, Node* n = nullptr, Node* p = nullptr)
            : data(value), next(n), prev(p) {}
    };

public:
    virtual void insert(const T& value) = 0;
    virtual void insertAt(const T& value, Iterator<T>* it) = 0;
    virtual void removeAt(Iterator<T>* it) = 0;
    virtual Iterator<T>* find(const T& value) = 0;
    virtual void makeEmpty() = 0;
    virtual bool isEmpty() const = 0;
    virtual int size() const = 0;
    virtual Iterator<T>* getIterator() const = 0;
    virtual ~List() = default;
};

#endif
