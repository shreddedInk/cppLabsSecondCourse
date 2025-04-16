#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include "List.h"
#include <iostream>

template <typename T>
class CircularList : public List<T> {
private:
    using Node = typename List<T>::Node;
    Node* buffer;
    int count;

public:
    class CircularIterator : public Iterator<T> {
    private:
        Node* current;
        Node* buffer;
    public:
        CircularIterator(Node* buf);
        void start() override;
        T getValue() const override;
        void next() override;
        bool finish() const override;
        Node* getNode() const;
        void setNode(Node* node);
        friend class CircularList;
    };

    CircularList();
    ~CircularList();
    CircularList(const CircularList& other);
    CircularList(CircularList&& other) noexcept;
    CircularList& operator=(const CircularList& other);
    CircularList& operator=(CircularList&& other) noexcept;

    void insert(const T& value) override;
    void insertAt(const T& value, Iterator<T>* it) override;
    void removeAt(Iterator<T>* it) override;
    Iterator<T>* find(const T& value) override;
    void makeEmpty() override;
    bool isEmpty() const override;
    int size() const override;
    Iterator<T>* getIterator() const override;
};

#include "CircularList.cpp"  

#endif
