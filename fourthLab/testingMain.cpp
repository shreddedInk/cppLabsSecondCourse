#include <iostream>
#include "linkedHashSet.h" 

void test() {
    LinkedHashSet<int> set;

    std::cout << "Testing LinkedHashSet<int>\n";

    std::cout << "Checking isEmpty() for new set: "
              << (set.isEmpty() ? "OK" : "ERROR") << "\n";

    set.add(1);
    set.add(2);
    set.add(3);

    std::cout << "Adding elements (1, 2, 3):\n   ";
    for (auto item : set) {
        std::cout << item << " ";
    }
    std::cout << "\n   Expected: 1 2 3\n";

    std::cout << "Checking contains(2): "
              << (set.contains(2) ? "OK" : "ERROR") << "\n";
    std::cout << "Checking contains(5) (should not exist): "
              << (!set.contains(5) ? "OK" : "ERROR") << "\n";

    set.add(2);
    std::cout << "Attempting to add existing element (2):\n   ";
    for (auto item : set) {
        std::cout << item << " ";
    }
    std::cout << "\n   Expected: 1 2 3 (no duplicates)\n";

    set.remove(2);
    std::cout << "After removing element (2):\n   ";
    for (auto item : set) {
        std::cout << item << " ";
    }
    std::cout << "\n   Expected: 1 3\n";

    std::cout << "Checking contains(2) after removal: "
              << (!set.contains(2) ? "OK" : "ERROR") << "\n";

    set.makeEmpty();
    std::cout << "After makeEmpty(), isEmpty(): "
              << (set.isEmpty() ? "OK" : "ERROR") << "\n";

    std::cout << "Iterating through empty set: ";
    bool empty_iteration_ok = true;
    for (auto item : set) {
        std::cout << item << " ";  
        empty_iteration_ok = false;
    }
    if (empty_iteration_ok) {
        std::cout << "OK (nothing printed)";
    } else {
        std::cout << "ERROR";
    }
    std::cout << "\n";

    LinkedHashSet<std::string> strSet;
    strSet.add("first");
    strSet.add("second");
    strSet.add("third");

    std::cout << "\nTesting insertion order (LinkedHashSet<std::string>):\n";
    std::cout << "Expected order: first second third\n";
    std::cout << "Actual order: ";
    for (const auto& item : strSet) {
        std::cout << item << " ";
    }
    std::cout << "\n";

    strSet.remove("first");
    strSet.remove("third");
    std::cout << "After removing 'first' and 'third':\n";
    std::cout << "Expected order: second\n";
    std::cout << "Actual order: ";
    for (const auto& item : strSet) {
        std::cout << item << " ";
    }
    std::cout << "\n";
}

int main() {
    test();
    return 0;
}