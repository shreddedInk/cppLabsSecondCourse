#ifndef BOX_H
#define BOX_H

#include <iostream>

namespace BoxAndContainer{

class Box {
    
private:
    int length, width, height;
    double weight;
    int value;

public:
    Box(int len, int wid, int heigh, double wei, int val);
    Box();

    bool operator==(const Box& box2) const;
    friend std::ostream& operator<<(std::ostream& os, const Box& box);
    friend std::istream& operator>>(std::istream& is, Box& box);

    int getValue() const;
    double getWeight() const;
    int getLength() const;
    int getWidth() const;
    int getHeight() const;

    void setValue(int val);
    void setWeight(double wei);
    void setLength(int len);
    void setWidth(int wid);
    void setHeight(int hei);
};

int sumOfBoxes(Box* boxes, int size);
bool SumLessThanLimit(Box* boxes, int size, int limit);
double maxWeightLessThanLimit(Box* boxes, int size, int maxV);
void boxesSort(Box* boxes, int size, int left, int right);
bool CanInsertBox(Box* boxes, int size);
}
#endif 