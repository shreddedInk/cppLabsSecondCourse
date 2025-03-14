#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include "Box.h"

namespace BoxAndContainer {

class Container {
private:
    int length, width, height;
    double maxWeight;
    std::vector<Box> boxes;

public:
    Container(int len, int wid, int heigh, double maxWei);
    Container();

    int addBox(const Box& box);
    void removeBoxByIndex(int index);

    const std::vector<Box>& getBoxes() const;
    double getTotalWeight() const;
    int getTotalValue() const;
    int getBoxCount() const;
    const Box& getBoxByIndex(int index) const;

    bool isEmpty() const;
    void clearBoxes();

    friend std::ostream& operator<<(std::ostream& os, const Container& container);
    friend std::istream& operator>>(std::istream& is, Container& container);

    Box& operator[](int index);
};

}

#endif

