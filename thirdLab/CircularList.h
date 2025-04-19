#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include <iostream>

//Iterator
template <typename T>
class Iterator {
public:
    virtual void start() = 0;
    virtual T getValue() const = 0;
    virtual void next() = 0;
    virtual bool finish() const = 0;
    virtual ~Iterator() = default;
};

//List
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

//CircularList
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
        CircularIterator(Node* buf) {
            buffer = buf;
            current = buffer->next;
        }

        void start() override {
            current = buffer->next;
        }

        T getValue() const override {
            return current->data;
        }

        void next() override {
            current = current->next;
        }

        bool finish() const override {
            return current == buffer;
        }

        Node* getNode() const {
            return current;
        }

        void setNode(Node* node) {
            current = node;
        }

        friend class CircularList;
    };

    CircularList() {
        buffer = new Node(T());
        buffer->next = buffer;
        buffer->prev = buffer;
        count = 0;
    }

    ~CircularList() {
        makeEmpty();
        delete buffer;
    }

    CircularList(const CircularList& other) : CircularList() {
        auto it = other.getIterator();
        for (it->start(); !it->finish(); it->next())
            insert(it->getValue());
        delete it;
    }

    CircularList(CircularList&& other) noexcept {
        buffer = other.buffer;
        count = other.count;
        other.buffer = nullptr;
        other.count = 0;
    }

    CircularList& operator=(const CircularList& other) {
        if (this != &other) {
            makeEmpty();
            auto it = other.getIterator();
            for (it->start(); !it->finish(); it->next())
                insert(it->getValue());
            delete it;
        }
        return *this;
    }

    CircularList& operator=(CircularList&& other) noexcept {
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

    void insert(const T& value) override {
        Node* node = new Node(value, buffer, buffer->prev);
        buffer->prev->next = node;
        buffer->prev = node;
        count++;
    }

    void insertAt(const T& value, Iterator<T>* it) override {
        auto& cit = static_cast<CircularIterator&>(*it);
        Node* pos = cit.current;
        Node* node = new Node(value, pos, pos->prev);
        pos->prev->next = node;
        pos->prev = node;
        count++;
    }

    void removeAt(Iterator<T>* it) override {
        auto& cit = static_cast<CircularIterator&>(*it);
        Node* pos = cit.current;
        if (pos == buffer) return;
        pos->prev->next = pos->next;
        pos->next->prev = pos->prev;
        cit.current = pos->next;
        delete pos;
        count--;
    }

    Iterator<T>* find(const T& value) override {
        CircularIterator* it = new CircularIterator(buffer);
        for (it->start(); !it->finish(); it->next()) {
            if (it->getValue() == value)
                return it;
        }
        delete it;
        return nullptr;
    }

    void makeEmpty() override {
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

    bool isEmpty() const override {
        return count == 0;
    }

    int size() const override {
        return count;
    }

    Iterator<T>* getIterator() const override {
        return new CircularIterator(buffer);
    }
};

#endif
