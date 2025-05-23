#ifndef LINKED_HASH_SET

#include <iostream>

template <typename T>
class linkedHashSet {
    private:
        struct item {
            T value;
            size_t next;
        };
    
    public:
        HashSet();
        ~HashSet();
        void add(T value);
        bool contains(T value);
        void remove(T value);
        void makeEmpty();
        bool isEmpty();
}