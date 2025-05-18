#include "binaryTree.h"
#include <iostream>

int main() {
    // Тест пустого дерева
    binaryTree emptyTree;
    std::cout << "Empty tree:\n";
    std::cout << "Is empty? " << std::boolalpha << emptyTree.isEmpty() << " (expected: true)\n";
    std::cout << "Even count: " << emptyTree.getEvenCount() << " (expected: 0)\n";
    std::cout << "All positive? " << emptyTree.checkForPositiveNumbers() << " (expected: true)\n\n";

    // Тест дерева с одним элементом
    binaryTree singleTree(7);
    std::cout << "Single node tree:\n" << singleTree;
    std::cout << "Even count: " << singleTree.getEvenCount() << " (expected: 0)\n";
    std::cout << "All positive? " << singleTree.checkForPositiveNumbers() << " (expected: true)\n\n";

    // Основное тестовое дерево
    binaryTree tree;
    tree.push(5, {});
    tree.push(3, {0});
    tree.push(8, {1});  // Четное
    tree.push(2, {0, 0}); // Четное
    tree.push(4, {0, 1}); // Четное
    tree.push(7, {1, 0});
    
    std::cout << "Original tree:\n" << tree;
    std::cout << "Even count: " << tree.getEvenCount() << " (expected: 3)\n";
    std::cout << "All positive? " << tree.checkForPositiveNumbers() << " (expected: true)\n\n";

    // Добавляем отрицательное число
    tree.push(-1, {1, 1});
    std::cout << "Tree after adding -1:\n" << tree;
    std::cout << "Even count: " << tree.getEvenCount() << " (expected: 3)\n";
    std::cout << "All positive? " << tree.checkForPositiveNumbers() << " (expected: false)\n\n";

    // Тест копирования
    binaryTree treeCopy = tree;
    std::cout << "Copied tree:\n" << treeCopy;
    std::cout << "Copy even count: " << treeCopy.getEvenCount() << " (original: " << tree.getEvenCount() << ")\n";
    std::cout << "Copy all positive: " << treeCopy.checkForPositiveNumbers() 
              << " (original: " << tree.checkForPositiveNumbers() << ")\n\n";

    // Тест перемещения
    binaryTree movedTree = std::move(tree);
    std::cout << "Moved tree:\n" << movedTree;
    std::cout << "Original after move is empty? " << tree.isEmpty() << " (expected: true)\n";

    return 0;
}