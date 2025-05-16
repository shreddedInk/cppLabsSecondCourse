#include "binaryTree.h"
#include <iostream>

int main() {
    binaryTree tree;
    
    // Создаем дерево:
    //       5
    //      / \
    //     3   7
    //    / \
    //   1   4
    tree.push(5, {});
    tree.push(3, {0});
    tree.push(7, {1});
    tree.push(1, {0, 0});
    tree.push(4, {0, 1});
    
    // Выводим дерево
    std::cout << tree; // Вывод: Tree: 1 3 4 5 7
    
    // Проверка копирования
    binaryTree tree2 = tree;
    std::cout << "Copied tree: " << tree2;
    
    return 0;
}