#include "vectorArr.h"



vectorArr::vectorArr() : size(0), capacity_(5) {
    massive = new int[capacity_];
}

vectorArr::vectorArr(size_t s) : size(s), capacity_(s) {
    massive = new int[capacity_]{};
}

vectorArr::vectorArr(size_t s, size_t cap) : size(s), capacity_(cap) {
    if (capacity_ < size) {
        capacity_ = size;
    }
    massive = new int[capacity_]{};
}

vectorArr::vectorArr(int n, size_t s) : size(s), capacity_(s) {
    massive = new int[capacity_];
    std::fill(massive, massive + size, n);
}

vectorArr::vectorArr(const vectorArr &vector_arr) : size(vector_arr.size), capacity_(vector_arr.capacity_) {
    massive = new int[capacity_];
    std::copy(vector_arr.massive, vector_arr.massive + size, massive);
}

vectorArr::vectorArr(vectorArr&& vector) : size(vector.size), capacity_(vector.capacity_), massive(vector.massive) {
    vector.massive = nullptr;
    vector.size = 0;
    vector.capacity_ = 0;
}


vectorArr::~vectorArr() {
    std::cout << "Destructor" << std::endl;
    delete[] massive;
}

size_t vectorArr::getSize() const {
    return size;
}

size_t vectorArr::capacity() const {
    return capacity_;
}

void vectorArr::reserve(size_t newCapacity) {
    if (newCapacity <= capacity_) {
        return;
    }

    int* newMassive = new int[newCapacity]{};
    std::copy(massive, massive + size, newMassive);

    delete[] massive;
    massive = newMassive;
    capacity_ = newCapacity;
}

void vectorArr::resize(size_t newSize) {
    if (newSize > capacity_) {
        reserve(newSize);
    }
    size = newSize;
}

void vectorArr::pushBack(int x) {
    if (size >= capacity_) {
        reserve(capacity_ * 2);
    }
    massive[size++] = x;
}

void vectorArr::popBack() {
    if (size > 0) {
        --size;
    }
}

vectorArr& vectorArr::operator=(const vectorArr &vector_arr) {
    if (this == &vector_arr) {
        return *this; 
    }

    delete[] massive;

    size = vector_arr.size;
    capacity_ = vector_arr.capacity_;
    massive = new int[capacity_];
    std::copy(vector_arr.massive, vector_arr.massive + size, massive);

    return *this;
}

int& vectorArr::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
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