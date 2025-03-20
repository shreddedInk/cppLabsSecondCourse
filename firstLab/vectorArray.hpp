#ifndef VECTORARR_H
#define VECTORARR_H

#include <iostream>
#include <algorithm>
#include <stdexcept>

class vectorArr {
private:
    int *massive;
    size_t size;
    size_t capacity_;  

public:
    vectorArr();
    vectorArr(size_t);
    vectorArr(size_t, size_t);
    vectorArr(int, size_t);
    vectorArr(const vectorArr &smthg);
    vectorArr(vectorArr &&smthg);

    ~vectorArr();

    size_t getSize() const;
    size_t capacity() const;  

    void reserve(size_t);  
    void resize(size_t); 
    void pushBack(int);  
    void popBack(); 

    vectorArr& operator=(const vectorArr &smthg);
    int& operator[](size_t);

    bool operator==(const vectorArr& smthg) const;
    bool operator!=(const vectorArr& smthg) const;
    
    bool operator<(const vectorArr& smthg) const;
    bool operator<=(const vectorArr& smthg) const;
    bool operator>(const vectorArr& smthg) const;
    bool operator>=(const vectorArr& smthg) const;
    
    vectorArr operator+(const vectorArr& smthg) const;

    friend std::ostream& operator<<(std::ostream& os, const vectorArr& vector); 
    friend std::istream& operator>>(std::istream& is, vectorArr& vector); 
};

#endif