#ifndef STACK_H
#define STACK_H

#include "IStack.h"

template <typename T>
class Stack : public IStack<T> {
    
    struct Node {
        T data;
        Node* next;
        Node(const T& theData, Node* theNext = nullptr) : data(theData), next(theNext) {}
    };

    Node* top;
    size_t size;

public:
    void push(const T& x){
        top = new Node(x,top);
        size++;
    }

    T pop() {
        if (!top) {
            throw std::runtime_error("Stack is empty: cannot pop");
        }
        T value = top->data;
        Node* p = top->next;
        delete top;
        top = p;
        size--;
        return value;
    }

    const T& top() const{
        if (!top) {
            throw std::runtime_error("Stack is empty");
        }
        return top->data;
    }
    // T& top() {
    //     if (!top) {
    //         throw std::runtime_error("Stack is empty");
    //     }
    //     return top->data;
    // }

    bool isEmpty() const {
        return top==nullptr;
    }

    void clear(){
        while(top){
            Node* p = top;
            top = top->next;
            delete p;
        }
        size = 0;
    }

    size_t size() const{
        return size;
    }


    Stack() : top(nullptr), size(0) {}

    ~Stack() { clear(); }

    Stack(const Stack<T>& st) : size(st.size), top(nullptr){
        if (st.isEmpty){
            return; 
        }
        top = new Node(st.top->data);
        Node *src = st.top;
        Node *dest = top;
        while (src->next){
            src = src->next;
            dest->next = new Node(src->data);
            dest = dest->next;
        }
    }

    Stack(Stack && st) : top(st.top), size(st.size){
        st.top = nullptr;
        st.size=0;
    }

    Stack& operator=(const Stack<T>& st){
        if(this==&st){
            return *this;
        }
        Stack<T> local(st);
        std::swap(top,local.top);
        std::swap(size, local.size);
        return *this;
    }

    Stack & operator=(Stack<T>&& st){
        if (this == &st) {return *this}
        std::swap(top, st.top);
        std::swap(size, st.size);
        return *this;
    }
};

#endif