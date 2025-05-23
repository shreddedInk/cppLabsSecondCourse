#ifndef LINKED_HASH_SET
#define LINKED_HASH_SET

#include <iostream>
#include <unordered_map>
#include <list>

template <typename T>
class LinkedHashSet {
private:
    struct Node {
        T value;
        typename std::list<T>::iterator list_it;
        
        Node(const T& val, typename std::list<T>::iterator it) : value(val), list_it(it) {}
    };

    std::unordered_map<T, Node> hash_map;
    std::list<T> insertion_order;

public:
    // Iterator class
    class Iterator {
    private:
        typename std::list<T>::iterator it;
        const std::list<T>* order_list;

    public:
        Iterator(typename std::list<T>::iterator list_it, const std::list<T>* list) 
            : it(list_it), order_list(list) {}

        Iterator& operator++() {
            ++it;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++it;
            return tmp;
        }

        const T& operator*() const {
            return *it;
        }

        bool operator==(const Iterator& other) const {
            return it == other.it;
        }

        bool operator!=(const Iterator& other) const {
            return it != other.it;
        }
    };

    LinkedHashSet() = default;
    
    ~LinkedHashSet() {
        makeEmpty();
    }

    void add(const T& value) {
        if (contains(value)) return;
        
        insertion_order.push_back(value);
        auto list_it = std::prev(insertion_order.end());
        hash_map.emplace(value, Node(value, list_it));
    }

    bool contains(const T& value) const {
        return hash_map.find(value) != hash_map.end();
    }

    void remove(const T& value) {
        auto it = hash_map.find(value);
        if (it != hash_map.end()) {
            insertion_order.erase(it->second.list_it);
            hash_map.erase(it);
        }
    }

    void makeEmpty() {
        hash_map.clear();
        insertion_order.clear();
    }

    bool isEmpty() const {
        return hash_map.empty();
    }

    Iterator begin() {
        return Iterator(insertion_order.begin(), &insertion_order);
    }

    Iterator end() {
        return Iterator(insertion_order.end(), &insertion_order);
    }

    Iterator begin() const {
        return Iterator(insertion_order.begin(), &insertion_order);
    }

    Iterator end() const {
        return Iterator(insertion_order.end(), &insertion_order);
    }
};

#endif