#include <iostream>
#include "vectorArray.hpp"

int main(){ 
    vectorArr vector1(3,5);
    vectorArr vector2(vector1);
    std::cout << "Working" << std::endl;
    return 0;
}