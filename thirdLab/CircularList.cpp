#include "CircularList.h"

template <typename T>
CircularList<T>::CircularList() {
    buffer = new Node(T());
    buffer->next = buffer;
    buffer->prev = buffer;
    count = 0;
}

template <typename T>
CircularList<T>::~CircularList() {
    makeEmpty();
    delete buffer;
}

template <typename T>
CircularList<T>::CircularList(const CircularList& other) : CircularList() {
    auto it = other.getIterator();
    for (it->start(); !it->finish(); it->next())
        insert(it->getValue());
}

template <typename T>
CircularList<T>::CircularList(CircularList&& other) noexcept {
    buffer = other.buffer;
    count = other.count;
    other.buffer = nullptr;
    other.count = 0;
}

template <typename T>
CircularList<T>& CircularList<T>::operator=(const CircularList& other) {
    if (this != &other) {
        makeEmpty();
        auto it = other.getIterator();
        for (it->start(); !it->finish(); it->next())
            insert(it->getValue());
    }
    return *this;
}

template <typename T>
CircularList<T>& CircularList<T>::operator=(CircularList&& other) noexcept {
    if (this != &other) {
        makeEmpty();
        delete buffer;
        buffer = other.buffer;
        count = other.count;
        other.buffer = nullptr;
        other.count = 0;
    }
    return *this;
}

template <typename T>
void CircularList<T>::insert(const T& value) {
    Node* node = new Node(value, buffer, buffer->prev);
    buffer->prev->next = node;
    buffer->prev = node;
    count++;
}

template <typename T>
void CircularList<T>::insertAt(const T& value, Iterator<T>* it) {
    auto& cit = static_cast<CircularIterator&>(*it);
    Node* pos = cit.current;
    Node* node = new Node(value, pos, pos->prev);
    pos->prev->next = node;
    pos->prev = node;
    count++;
}

template <typename T>
void CircularList<T>::removeAt(Iterator<T>* it) {
    auto& cit = static_cast<CircularIterator&>(*it);
    Node* pos = cit.current;
    if (pos == buffer) return;
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    cit.current = pos->next;
    delete pos;
    count--;
}

template <typename T>
Iterator<T>* CircularList<T>::find(const T& value) {
    CircularIterator it(buffer);
    for (it.start(); !it.finish(); it.next()) {
        if (it.getValue() == value)
            return &it;
    }
    return nullptr;
}

template <typename T>
void CircularList<T>::makeEmpty() {
    Node* current = buffer->next;
    while (current != buffer) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    buffer->next = buffer;
    buffer->prev = buffer;
    count = 0;
}

template <typename T>
bool CircularList<T>::isEmpty() const {
    return count == 0;
}

template <typename T>
int CircularList<T>::size() const {
    return count;
}

template <typename T>
Iterator<T>* CircularList<T>::getIterator() const {
    return new CircularIterator(buffer);
}
