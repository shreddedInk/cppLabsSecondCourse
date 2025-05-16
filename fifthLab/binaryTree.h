#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <stdexcept>

class binaryTree {
private:
    struct Node {
        int value;
        Node* left;
        Node* right;
        
        Node(int val) : value(val), left(nullptr), right(nullptr) {}
    };
    
    Node* root;
    
    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
    
    Node* copyTree(Node* otherNode) {
        if (!otherNode) return nullptr;
        
        Node* newNode = new Node(otherNode->value);
        newNode->left = copyTree(otherNode->left);
        newNode->right = copyTree(otherNode->right);
        return newNode;
    }

    void printLeftToRight(Node* node) const {
        if (node == nullptr) return;  
        printLeftToRight(node->left);
        std::cout << node->value << " ";
        printLeftToRight(node->right);
    }

    int countEvenNumbers(Node* node) const {
        if (node == nullptr) return 0;
        
        int count = (node->value % 2 == 0) ? 1 : 0;
        return count + countEvenNumbers(node->left) + countEvenNumbers(node->right);
    }
    
public:
    binaryTree() : root(nullptr) {}
    
    explicit binaryTree(int value) : root(new Node(value)) {} 
    
    binaryTree(const binaryTree& other) : root(copyTree(other.root)) {} 
    
    ~binaryTree() {
        clear(root);
    }
    
    binaryTree& operator=(binaryTree&& other) noexcept {
        if (this != &other) {
            clear(root);
            root = other.root;
            other.root = nullptr;
        }
        return *this;
    }

    binaryTree& operator=(const binaryTree& other) {
        if (this != &other) {
            binaryTree temp(other);
            std::swap(root, temp.root);
        }
        return *this;
    }
    
    bool isEmpty() const {
        return root == nullptr;
    }
    
    void push(int value, const std::vector<int>& seq) {
        if (seq.empty()) {
            if (root) {
                root->value = value;
            } else {
                root = new Node(value);
            }
            return;
        }
    
        if (!root) {
            throw std::runtime_error("Invalid path: tree is empty but path is not empty");
        }
    
        Node* current = root;
        Node* parent = nullptr;
        size_t i = 0;
    
        while (current && i < seq.size()) {
            parent = current;
            if (seq[i] == 0) {
                current = current->left;
            } else if (seq[i] == 1) {
                current = current->right;
            } else {
                throw std::runtime_error("Invalid path: sequence contains values other than 0 and 1");
            }
            i++;
        }
    
        if (i < seq.size()) {
            throw std::runtime_error("Invalid path: path goes through null node");
        }
    
        if (current) {
            current->value = value;
        } else {
            if (seq.back() == 0) {
                parent->left = new Node(value);
            } else {
                parent->right = new Node(value);
            }
        }
    }
    
    friend std::ostream& operator<<(std::ostream& stream, const binaryTree& tree) {
        stream << "Tree: ";
        tree.printLeftToRight(tree.root);
        return stream << std::endl;
    }

    int getEvenCount() const {
        return countEvenNumbers(root);
    }

};

#endif 