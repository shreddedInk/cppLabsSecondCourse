#include "binaryTree.h"
#include <iostream>

void testConstructors() {
    std::cout << "Testing Constructors\n";
    binaryTree emptyTree;
    std::cout << "Empty tree is empty: " << (emptyTree.isEmpty() ? "true" : "false") << "\n";

    binaryTree singleNodeTree(42);
    std::cout << "Single node tree is empty: " << (singleNodeTree.isEmpty() ? "true" : "false") << "\n";
    std::cout << "Single node tree (should be 42): " << singleNodeTree << "\n";

    binaryTree copiedTree(singleNodeTree);
    std::cout << "Copied tree (should be 42): " << copiedTree << "\n";
}

void testPushAndPrint() {
    std::cout << "\nTesting Push and Print\n";
    binaryTree tree;
    tree.push(10, {});
    std::cout << "Tree with root 10: " << tree << "\n";

    tree.push(5, {0});
    tree.push(15, {1});
    std::cout << "Tree after adding left (5) and right (15): " << tree << "\n";

    tree.push(3, {0, 0});
    tree.push(7, {0, 1});
    tree.push(12, {1, 0});
    tree.push(18, {1, 1});
    std::cout << "Tree after adding more nodes: " << tree << "\n";

    std::cout << "Tree printed rotated (90 degrees counter-clockwise):\n";
    tree.printRotated(std::cout);
}

void testOperations() {
    std::cout << "\nTesting Operations\n";
    binaryTree tree;
    tree.push(10, {});
    tree.push(5, {0});
    tree.push(15, {1});
    tree.push(3, {0, 0});
    tree.push(7, {0, 1});
    tree.push(12, {1, 0});
    tree.push(18, {1, 1});

    std::cout << "Original tree: " << tree << "\n";
    std::cout << "Average value: " << tree.getAverage() << "\n";
    std::cout << "Even count: " << tree.getEvenCount() << "\n";
    std::cout << "All positive: " << (tree.checkForPositiveNumbers() ? "true" : "false") << "\n";
    std::cout << "Is BST: " << (tree.isBST() ? "true" : "false") << "\n";

    std::cout << "Path to 18: ";
    auto path = tree.find(18);
    for (int dir : path) {
        std::cout << dir << " ";
    }
    std::cout << "\n";

    std::cout << "After removing leaves:\n";
    tree.removeAllLeaves();
    tree.printRotated(std::cout);
}

void testEdgeCases() {
    std::cout << "\nTesting Edge Cases\n";
    binaryTree tree;
    
    try {
        tree.push(1, {0});
        std::cout << "Error: exception not thrown for invalid path\n";
    } catch (const std::runtime_error& e) {
        std::cout << "Caught expected exception: " << e.what() << "\n";
    }

    tree.push(10, {});
    tree.push(-5, {0});
    std::cout << "Tree with negative value (-5): " << tree << "\n";
    std::cout << "All positive: " << (tree.checkForPositiveNumbers() ? "true" : "false") << "\n";

    binaryTree emptyTree;
    std::cout << "Empty tree average: " << emptyTree.getAverage() << "\n";
    std::cout << "Empty tree even count: " << emptyTree.getEvenCount() << "\n";
    std::cout << "Empty tree is BST: " << (emptyTree.isBST() ? "true" : "false") << "\n";
}

void testAssignment() {
    std::cout << "\nTesting Assignment\n";
    binaryTree tree1;
    tree1.push(10, {});
    tree1.push(5, {0});
    tree1.push(15, {1});

    binaryTree tree2;
    tree2 = tree1;
    std::cout << "After assignment (should be same as tree1): " << tree2 << "\n";

    binaryTree tree3 = std::move(tree1);
    std::cout << "After move assignment (should be same as tree1): " << tree3 << "\n";
    std::cout << "Original tree after move (should be empty): " << (tree1.isEmpty() ? "empty" : "not empty") << "\n";
}

int main() {
    testConstructors();
    testPushAndPrint();
    testOperations();
    testEdgeCases();
    testAssignment();
    
    return 0;
}