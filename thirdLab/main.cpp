#include <iostream>
#include "CircularList.h"
#include <locale>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001); 

    CircularList<int> list;

    std::cout << "=== Тест: Вставка элементов ===\n";
    std::cout << "Добавим числа 1, 2, 3 в список...\n";
    list.insert(1);
    list.insert(2);
    list.insert(3);

    std::cout << "Содержимое списка: ";
    Iterator<int>* it = list.getIterator();
    for (it->start(); !it->finish(); it->next()) {
        std::cout << it->getValue() << " ";
    }
    std::cout << "\nРазмер списка: " << list.size() << "\n";
    delete it;

    std::cout << "\n=== Тест: Вставка перед элементом ===\n";
    std::cout << "Ищем элемент 2 и вставим перед ним 99...\n";
    Iterator<int>* found = list.find(2);
    if (found) {
        list.insertAt(99, found);
    }

    std::cout << "Содержимое списка: ";
    it = list.getIterator();
    for (it->start(); !it->finish(); it->next()) {
        std::cout << it->getValue() << " ";
    }
    std::cout << "\n";
    delete it;
    delete found;

    std::cout << "\n=== Тест: Удаление элемента ===\n";
    std::cout << "Удалим элемент 99...\n";
    found = list.find(99);
    if (found) {
        list.removeAt(found);
        delete found;
    }

    std::cout << "Содержимое списка: ";
    it = list.getIterator();
    for (it->start(); !it->finish(); it->next()) {
        std::cout << it->getValue() << " ";
    }
    std::cout << "\n";
    delete it;

    std::cout << "\n=== Тест: Очистка списка ===\n";
    std::cout << "Очищаем список...\n";
    list.makeEmpty();

    std::cout << "Список пуст? " << (list.isEmpty() ? "Да" : "Нет") << "\n";
    std::cout << "Размер списка: " << list.size() << "\n";

    return 0;
}
