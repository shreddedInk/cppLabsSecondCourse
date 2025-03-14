#include "vectorArray.hpp"

vectorArr::vectorArr(){
    massive = new int[5];
    size = 5;  
}

vectorArr::vectorArr(size_t s){
    size = s;
    massive = new int[s];
    for (int i = 0; i < s; i++){
        massive[i] = 0;
    }
}

vectorArr::vectorArr(int n, size_t s){
    size = s;
    massive = new int[s];
    for (int i = 0; i < s; i++){
        massive[i] = n;
    }
}

vectorArr::vectorArr(const vectorArr &vector_arr){
    size = vector_arr.size;
    massive = new int[size];
    std::copy(vector_arr.massive, vector_arr.massive + size, massive);
}

vectorArr::vectorArr(vectorArr&& vector){
    size = vector.size;
    massive = vector.massive;
    vector.massive = nullptr;
    vector.size = 0;
}

void vectorArr::resize(size_t newSize) {
    int* newMassive = new int[newSize]{};

    size_t minSize = (newSize < size) ? newSize : size;
    std::copy(massive, massive + minSize, newMassive);

    delete[] massive;

    massive = newMassive;
    size = newSize;
}

size_t vectorArr::getSize() const{
    return size;
}

vectorArr& vectorArr::operator=(const vectorArr &vector_arr) {
    if (this == &vector_arr) {
        return *this; 
    }

    delete[] massive;

    size = vector_arr.size;
    massive = new int[size];
    std::copy(vector_arr.massive, vector_arr.massive + size, massive);

    return *this;
}

int& vectorArr::operator[](size_t index){
    return massive[index];
}

bool vectorArr::operator==(const vectorArr& vector) const {
    if (size != vector.size) {
        throw std::runtime_error("Arrays must have the same length for comparison.");
    }
    return std::equal(massive, massive + size, vector.massive);
}

bool vectorArr::operator!=(const vectorArr& vector) const {
    return !(*this == vector);
}

bool vectorArr::operator<(const vectorArr& vector) const {
    return std::lexicographical_compare(massive, massive + size, vector.massive, vector.massive + vector.size);
}

bool vectorArr::operator<=(const vectorArr& vector) const {
    return !(vector < *this);
}

bool vectorArr::operator>(const vectorArr& vector) const {
    return vector < *this;
}

bool vectorArr::operator>=(const vectorArr& vector) const {
    return !(*this < vector);
}

vectorArr vectorArr::operator+(const vectorArr& vector) const {
    vectorArr result(size + vector.size);
    std::copy(massive, massive + size, result.massive);
    std::copy(vector.massive, vector.massive + vector.size, result.massive + size);
    return result;
}

std::ostream& operator<<(std::ostream& os, const vectorArr& vector) {
    os << "[";
    for (size_t i = 0; i < vector.size; i++) {
        os << vector.massive[i];
        if (i < vector.size - 1) os << ", ";
    }
    os << "]";
    return os;
}

std::istream& operator>>(std::istream& is, vectorArr& vector) {
    for (size_t i = 0; i < vector.size; i++) {
        is >> vector.massive[i];
    }
    return is;
}

vectorArr::~vectorArr(){
    std::cout << "Destructor" << std::endl;
    delete[] massive;
}