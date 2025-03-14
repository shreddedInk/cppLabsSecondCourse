#include "Box.h"


BoxAndContainer::Box::Box(
        int len, 
        int wid, 
        int heigh, 
        double wei, 
        int val
        ) {
        length = len;
        width = wid;
        height = heigh;
        weight = wei;
        value = val;
    }

BoxAndContainer::Box::Box(){
        width = 0;
         length = 0;
         height = 0;
         weight = 0;
         value = 0;
    }

int BoxAndContainer::sumOfBoxes(Box* boxes, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += boxes[i].getValue();
    }
    return sum;
}

bool BoxAndContainer::SumLessThanLimit(Box* boxes, int size, int limit) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += (boxes[i].getLength() + boxes[i].getHeight() + boxes[i].getWidth());
    }
    return sum <= limit;
}

double BoxAndContainer::maxWeightLessThanLimit(Box* boxes, int size, int maxV) {
    double maxWeight = 0.0;
    for (int i = 0; i < size; i++) {
        int V = boxes[i].getLength() * boxes[i].getHeight() * boxes[i].getWidth();
        if (V <= maxV && boxes[i].getWeight() > maxWeight) {
            maxWeight = boxes[i].getWeight();
        }
    }
    return maxWeight;
}

void BoxAndContainer::boxesSort(Box* boxes, int size, int left, int right) {
    if (left >= right) return;

    int pivot = boxes[(left + right) / 2].getHeight() + boxes[(left + right) / 2].getLength() + boxes[(left + right) / 2].getWidth();
    int i = left, j = right;

    while (i <= j) {
        while (boxes[i].getHeight() + boxes[i].getLength() + boxes[i].getWidth() < pivot) i++;
        while (boxes[j].getHeight() + boxes[j].getLength() + boxes[j].getWidth() > pivot) j--;
        if (i <= j) {
            Box tmp = boxes[i];
            boxes[i] = boxes[j];
            boxes[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j) boxesSort(boxes, size, left, j);
    if (i < right) boxesSort(boxes, size, i, right);
}

bool BoxAndContainer::CanInsertBox(Box* boxes, int size) {
    Box* fboxes = new Box[size];
    for (int i = 0; i < size; i++) {
        fboxes[i] = Box(boxes[i].getHeight(), boxes[i].getLength(), boxes[i].getValue(), boxes[i].getWeight(), boxes[i].getWidth());
    }
    boxesSort(boxes, size, 0, size - 1);
    for (int i = 0; i < size - 1; i++) {
        if (boxes[i].getHeight() > boxes[i + 1].getHeight() ||
            boxes[i].getLength() > boxes[i + 1].getLength() ||
            boxes[i].getWidth() > boxes[i + 1].getWidth()) {
            delete[] fboxes;
            return false;
        }
    }
    delete[] fboxes;
    return true;
}

bool BoxAndContainer::Box::operator==(const Box& box2) const {
    return (getWidth() == box2.getWidth() &&
            getLength() == box2.getLength() &&
            getHeight() == box2.getHeight() &&
            getValue() == box2.getValue() &&
            getWeight() == box2.getWeight());
}

std::ostream& BoxAndContainer::operator<<(std::ostream& os, const Box& box) {
    return os << "Box{\nwidth: " << box.getWidth() << "\nlength: " << box.getLength()
              << "\nheight: " << box.getHeight() << "\nweight: " << box.getWeight()
              << "\nvalue: " << box.getValue() << "\n}\n";
}

std::istream& BoxAndContainer::operator>>(std::istream& is, Box& box) {
    int w, l, h, v;
    double weigh;
    is >> w >> l >> h >> weigh >> v;
    box.setWidth(w);
    box.setLength(l);
    box.setHeight(h);
    box.setWeight(weigh);
    box.setValue(v);
    return is;
}

int BoxAndContainer::Box::getValue() const {
    return value;
}

int BoxAndContainer::Box::getHeight() const {
    return height;
}

int BoxAndContainer::Box::getLength() const {
    return length;
}

double BoxAndContainer::Box::getWeight() const {
    return weight;
}

int BoxAndContainer::Box::getWidth() const {
    return width;
}

void BoxAndContainer::Box::setValue(int val) {
    value = val;
}

void BoxAndContainer::Box::setWeight(double wei) {
    weight = wei;
}

void BoxAndContainer::Box::setLength(int len) {
    length = len;
}

void BoxAndContainer::Box::setWidth(int wid) {
    width = wid;
}

void BoxAndContainer::Box::setHeight(int hei) {
    height = hei;
}
