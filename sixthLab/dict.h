#ifndef FREQUENCY_DICTIONARY_H
#define FREQUENCY_DICTIONARY_H

#include <iostream>
#include <string>

class FrequencyDictionary {
private:
    struct AVLNode {
        std::string word;
        int count;
        int height;
        AVLNode* left;
        AVLNode* right;

        AVLNode(const std::string& w) : word(w), count(1), height(1), left(nullptr), right(nullptr) {}
    };

    AVLNode* root;
    int totalWords;

    int height(AVLNode* node);
    int balanceFactor(AVLNode* node);
    void updateHeight(AVLNode* node);
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);
    AVLNode* balance(AVLNode* node);
    AVLNode* insert(AVLNode* node, const std::string& word);
    AVLNode* findMin(AVLNode* node);
    AVLNode* removeMin(AVLNode* node);
    AVLNode* remove(AVLNode* node, const std::string& word, bool& removed);
    AVLNode* find(AVLNode* node, const std::string& word) const;
    void clear(AVLNode* node);
    AVLNode* copyTree(AVLNode* node);
    void printInOrder(AVLNode* node, std::ostream& os) const;

public:
    FrequencyDictionary();
    FrequencyDictionary(const FrequencyDictionary& other);
    ~FrequencyDictionary();
    FrequencyDictionary& operator=(const FrequencyDictionary& other);

    int findWord(const std::string& word) const;
    void addWord(const std::string& word);
    bool removeWord(const std::string& word);
    int getTotalWordCount() const;

    friend std::ostream& operator<<(std::ostream& os, const FrequencyDictionary& dict);
};

#endif 