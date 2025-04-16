#include <iostream>
#include "CircularList.h"

int main() {
    CircularList<int> list;

    std::cout << "Добавим числа 1, 2, 3 в список:\n";
    list.insert(1);
    list.insert(2);
    list.insert(3);

    std::cout << "Содержимое списка: ";
    auto it = list.getIterator();
    for (it->start(); !it->finish(); it->next()) {  // Используем -> для обращения к членам итератора
        std::cout << it->getValue() << " ";  // Используем -> для обращения к членам итератора
    }
    std::cout << "\nРазмер списка: " << list.size() << "\n";

    std::cout << "\nИщем элемент 2 и вставим перед ним 99:\n";
    auto found = list.find(2);
    if (found) {
        list.insertAt(99, found);
    }

    std::cout << "Список после вставки: ";
    it = list.getIterator();
    for (it->start(); !it->finish(); it->next()) {
        std::cout << it->getValue() << " ";
    }

    std::cout << "\n\nУдалим элемент 99:\n";
    found = list.find(99);
    if (found) {
        list.removeAt(found);
    }

    std::cout << "Список после удаления: ";
    it = list.getIterator();
    for (it->start(); !it->finish(); it->next()) {
        std::cout << it->getValue() << " ";
    }

    std::cout << "\n\nОчистим список:\n";
    list.makeEmpty();
    std::cout << "Список пуст? " << (list.isEmpty() ? "Да" : "Нет") << "\n";

    return 0;
}
