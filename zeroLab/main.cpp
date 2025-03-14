#include <iostream>
#include "Box.h"
#include "Container.h"

using namespace BoxAndContainer;

int main() {
    Box boxes[] = {
        Box(1, 2, 3, 4.5, 5),
        Box(2, 3, 4, 5.5, 6),
        Box(3, 4, 5, 6.5, 7)
    };
    int size = sizeof(boxes) / sizeof(boxes[0]);

    std::cout << "Sum of boxes values: " << sumOfBoxes(boxes, size) << std::endl;
    std::cout << "Can insert box: " << (CanInsertBox(boxes, size) ? "Yes" : "No") << std::endl;

    int limit = 120;
    std::cout << "Sum less than limit: " << (SumLessThanLimit(boxes, size, limit) ? "Yes" : "No") << std::endl;

    int maxV = 60;
    std::cout << "Max weight less than limit: " << maxWeightLessThanLimit(boxes, size, maxV) << std::endl;

    Box boxes2[2];
    std::cout << "Enter details for 2 boxes (width length height weight value):" << std::endl;
    for (int i = 0; i < 2; i++) {
        std::cin >> boxes2[i];
    }

    for (int i = 0; i < 2; i++) {
        std::cout << boxes2[i];
    }

    Container container(10, 10, 10, 50.0);
    for (int i = 0; i < size; i++) {
        if (container.addBox(boxes[i])) {
            std::cout << "Box " << i + 1 << " added to the container." << std::endl;
        } else {
            std::cout << "Box " << i + 1 << " could not be added to the container." << std::endl;
        }
    }

    std::cout << "Total weight in container: " << container.getTotalWeight() << std::endl;
    std::cout << "Total value in container: " << container.getTotalValue() << std::endl;

    return 0;
}
