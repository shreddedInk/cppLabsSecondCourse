#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <stdexcept>
#include <numeric>
#include <climits>

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

    Node* removeLeaves(Node* node) {
        if (!node) return nullptr;
        if (!node->left && !node->right) {
            delete node;
            return nullptr;
        }
        node->left = removeLeaves(node->left);
        node->right = removeLeaves(node->right);
        return node;
    }

    int sumNodes(Node* node) const {
        if (!node) return 0;
        return node->value + sumNodes(node->left) + sumNodes(node->right);
    }

    int countNodes(Node* node) const {
        if (!node) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    bool findPath(Node* node, int x, std::vector<int>& path) const {
        if (!node) return false;
        if (node->value == x) return true;
        
        path.push_back(0);
        if (findPath(node->left, x, path)) return true;
        path.pop_back();
        
        path.push_back(1);
        if (findPath(node->right, x, path)) return true;
        path.pop_back();
        
        return false;
    }

    bool isBSTUtil(Node* node, int min, int max) const {
        if (!node) return true;
        if (node->value < min || node->value > max) return false;
        return isBSTUtil(node->left, min, node->value - 1) && 
               isBSTUtil(node->right, node->value + 1, max);
    }

    bool positiveCheck(Node* node) const {
        if (node == nullptr) return true;
        if (node -> value < 0) return false;
        return positiveCheck(node->left) && positiveCheck(node->right);
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
    ~binaryTree() { clear(root); }

    binaryTree& operator=(const binaryTree& other) {
        if (this != &other) {
            binaryTree temp(other);
            std::swap(root, temp.root);
        }
        return *this;
    }
    binaryTree& operator=(binaryTree&& other) noexcept {
        if (this != &other) {
            clear(root);
            root = other.root;
            other.root = nullptr;
        }
        return *this;
    }

    bool isEmpty() const { return root == nullptr; }

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
    
//Second/Third/Fifth tasks

    int getEvenCount() const {
        return countEvenNumbers(root);
    }

    bool checkForPositiveNumbers() const {
        return positiveCheck(root);
    }

    void removeAllLeaves() {
        root = removeLeaves(root);
    }

    double getAverage() const {
        if (!root) return 0.0;
        return static_cast<double>(sumNodes(root)) / countNodes(root);
    }

    std::vector<int> find(int x) const {
        std::vector<int> path;
        findPath(root, x, path);
        return path;
    }

    bool isBST() const {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }

    friend std::ostream& operator<<(std::ostream& stream, const binaryTree& tree) {
        tree.printLeftToRight(tree.root);
        return stream;
    }

    void printRotated(std::ostream& stream) const {
        printNineteenDegrees(stream, root);
    }

private:
    void printLeftToRight(Node* node) const {
        if (!node) return;
        printLeftToRight(node->left);
        std::cout << node->value << " ";
        printLeftToRight(node->right);
    }

    void printNineteenDegrees(std::ostream& stream, Node* node, int level = 0) const {
        if (!node) return;
        printNineteenDegrees(stream, node->right, level+1);
        for (int i=0; i<level;++i){
            stream << "   ";
        }
        stream << node->value << "\n";
        printNineteenDegrees(stream, node->left, level+1);
    }
};

#endif 