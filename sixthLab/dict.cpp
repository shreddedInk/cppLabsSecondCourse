#include "dict.h"
#include <algorithm>


int FrequencyDictionary::height(AVLNode* node) {
    return node ? node->height : 0;
}

int FrequencyDictionary::balanceFactor(AVLNode* node) {
    return height(node->right) - height(node->left);
}

void FrequencyDictionary::updateHeight(AVLNode* node) {
    node->height = std::max(height(node->left), height(node->right)) + 1;
}

FrequencyDictionary::AVLNode* FrequencyDictionary::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    y->left = x->right;
    x->right = y;
    updateHeight(y);
    updateHeight(x);
    return x;
}

FrequencyDictionary::AVLNode* FrequencyDictionary::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    x->right = y->left;
    y->left = x;
    updateHeight(x);
    updateHeight(y);
    return y;
}

FrequencyDictionary::AVLNode* FrequencyDictionary::balance(AVLNode* node) {
    updateHeight(node);
    if (balanceFactor(node) == 2) {
        if (balanceFactor(node->right) < 0)
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    if (balanceFactor(node) == -2) {
        if (balanceFactor(node->left) > 0)
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    return node;
}

FrequencyDictionary::AVLNode* FrequencyDictionary::insert(AVLNode* node, const std::string& word) {
    if (!node) {
        totalWords++;
        return new AVLNode(word);
    }
    if (word < node->word)
        node->left = insert(node->left, word);
    else if (word > node->word)
        node->right = insert(node->right, word);
    else {
        node->count++;
        totalWords++;
    }
    return balance(node);
}

FrequencyDictionary::AVLNode* FrequencyDictionary::findMin(AVLNode* node) {
    return node->left ? findMin(node->left) : node;
}

FrequencyDictionary::AVLNode* FrequencyDictionary::removeMin(AVLNode* node) {
    if (!node->left)
        return node->right;
    node->left = removeMin(node->left);
    return balance(node);
}

FrequencyDictionary::AVLNode* FrequencyDictionary::remove(AVLNode* node, const std::string& word, bool& removed) {
    if (!node) return nullptr;
    if (word < node->word) {
        node->left = remove(node->left, word, removed);
    } else if (word > node->word) {
        node->right = remove(node->right, word, removed);
    } else {
        removed = true;
        if (node->count > 1) {
            node->count--;
            totalWords--;
            return node;
        } else {
            AVLNode* left = node->left;
            AVLNode* right = node->right;
            totalWords -= node->count;
            delete node;
            if (!right) return left;
            AVLNode* min = findMin(right);
            min->right = removeMin(right);
            min->left = left;
            return balance(min);
        }
    }
    return balance(node);
}

FrequencyDictionary::AVLNode* FrequencyDictionary::find(AVLNode* node, const std::string& word) const {
    if (!node) return nullptr;
    if (word < node->word)
        return find(node->left, word);
    else if (word > node->word)
        return find(node->right, word);
    else
        return node;
}

void FrequencyDictionary::clear(AVLNode* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

FrequencyDictionary::AVLNode* FrequencyDictionary::copyTree(AVLNode* node) {
    if (!node) return nullptr;
    AVLNode* newNode = new AVLNode(node->word);
    newNode->count = node->count;
    newNode->height = node->height;
    newNode->left = copyTree(node->left);
    newNode->right = copyTree(node->right);
    return newNode;
}

void FrequencyDictionary::printInOrder(AVLNode* node, std::ostream& os) const {
    if (node) {
        printInOrder(node->left, os);
        os << node->word << ": " << node->count << std::endl;
        printInOrder(node->right, os);
    }
}

//PUBLIC
FrequencyDictionary::FrequencyDictionary() : root(nullptr), totalWords(0) {}

FrequencyDictionary::FrequencyDictionary(const FrequencyDictionary& other) {
    root = copyTree(other.root);
    totalWords = other.totalWords;
}

FrequencyDictionary::~FrequencyDictionary() {
    clear(root);
}

FrequencyDictionary& FrequencyDictionary::operator=(const FrequencyDictionary& other) {
    if (this != &other) {
        clear(root);
        root = copyTree(other.root);
        totalWords = other.totalWords;
    }
    return *this;
}

int FrequencyDictionary::findWord(const std::string& word) const {
    AVLNode* node = find(root, word);
    return node ? node->count : 0;
}

void FrequencyDictionary::addWord(const std::string& word) {
    root = insert(root, word);
}

bool FrequencyDictionary::removeWord(const std::string& word) {
    bool removed = false;
    root = remove(root, word, removed);
    return removed;
}

int FrequencyDictionary::getTotalWordCount() const {
    return totalWords;
}

std::ostream& operator<<(std::ostream& os, const FrequencyDictionary& dict) {
    dict.printInOrder(dict.root, os);
    return os;
}



int main() {
    FrequencyDictionary dict;
    
    dict.addWord("apple");
    dict.addWord("banana");
    dict.addWord("apple");
    dict.addWord("cherry");
    dict.addWord("banana");
    dict.addWord("apple");
    
    std::cout << "Dictionary contents:" << std::endl;
    std::cout << dict;
    
    std::cout << "\nTotal words: " << dict.getTotalWordCount() << std::endl;
    
    std::cout << "\nFrequency of 'apple': " << dict.findWord("apple") << std::endl;
    std::cout << "Frequency of 'banana': " << dict.findWord("banana") << std::endl;
    std::cout << "Frequency of 'cherry': " << dict.findWord("cherry") << std::endl;
    std::cout << "Frequency of 'orange': " << dict.findWord("orange") << std::endl;
    
    dict.removeWord("apple");
    std::cout << "\nAfter removing one 'apple':" << std::endl;
    std::cout << dict;
    
    dict.removeWord("banana");
    dict.removeWord("banana");
    std::cout << "\nAfter removing all 'banana's:" << std::endl;
    std::cout << dict;
    
    return 0;
}