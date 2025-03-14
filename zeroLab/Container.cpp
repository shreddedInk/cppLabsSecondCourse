#include "Container.h"
#include "Exception.h"

namespace BoxAndContainer {

Container::Container(
        int len, 
        int wid, 
        int heigh, 
        double maxWei 
        ) {
        length = len;
        width = wid;
        height = heigh;
        maxWeight = maxWei;
    }

Container::Container(){
    length = 0;
    width = 0;
    height = 0;
    maxWeight = 0;
}


int Container::addBox(const Box& box) {
    if (getTotalWeight() + box.getWeight() <= maxWeight) {
        boxes.push_back(box);
        return boxes.size() - 1; 
    }
    throw WeightLimitExceededException();
}

void Container::removeBoxByIndex(int index) {
    if (index < 0 || index >= boxes.size()) {
        throw std::out_of_range("Index out of range");
    }
    boxes.erase(boxes.begin() + index);
}

double Container::getTotalWeight() const {
    double totalWeight = 0.0;
    for (const auto& box : boxes) {
        totalWeight += box.getWeight();
    }
    return totalWeight;
}

int Container::getTotalValue() const {
    int totalValue = 0;
    for (const auto& box : boxes) {
        totalValue += box.getValue();
    }
    return totalValue;
}


int Container::getBoxCount() const {
    return boxes.size();
}

const std::vector<Box>& Container::getBoxes() const {
    return boxes;
}

bool Container::isEmpty() const {
    return boxes.empty();
}

void Container::clearBoxes() {
    boxes.clear();
}

const Box& Container::getBoxByIndex(int index) const {
    if (index < 0 || index >= boxes.size()) {
        throw std::out_of_range("Index out of range");
    }
    return boxes[index];
}

std::ostream& operator<<(std::ostream& os, const Container& container) {
    os << "Container (Length: " << container.length
       << ", Width: " << container.width
       << ", Height: " << container.height
       << ", Max Weight: " << container.maxWeight << ")\n";
    os << "Boxes:\n";
    for (const auto& box : container.boxes) {
        os << box << "\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Container& container) {
    int len, wid, heigh;
    double maxWei;
    is >> len >> wid >> heigh >> maxWei;

    container.length = len;
    container.width = wid;
    container.height = heigh;
    container.maxWeight = maxWei;

    int boxCount;
    is >> boxCount;
    container.boxes.clear();
    for (int i = 0; i < boxCount; ++i) {
        Box box;
        is >> box;
        container.boxes.push_back(box);
    }
    return is;
}

Box& Container::operator[](int index) {
    if (index < 0 || index >= boxes.size()) {
        throw std::out_of_range("Index out of range");
    }
    return boxes[index];
}

}