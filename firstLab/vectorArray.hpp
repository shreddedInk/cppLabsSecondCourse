#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <algorithm>
#include <stdexcept>

class vectorArr {
    private:
        int *massive;
        size_t size;

    public:
        vectorArr();
        vectorArr(size_t);
        vectorArr(int, size_t);
        vectorArr(const vectorArr &smthg);
        vectorArr(vectorArr &&smthg);

        size_t getSize() const;

        void resize(size_t);

        vectorArr& operator=(const vectorArr &smthg);
        int& operator[](size_t);

        bool vectorArr::operator==(const vectorArr& smthg) const;
        bool vectorArr::operator!=(const vectorArr& smthg) const;
        
        bool vectorArr::operator<(const vectorArr& smthg) const;
        bool vectorArr::operator<=(const vectorArr& smthg) const;
        bool vectorArr::operator>(const vectorArr& smthg) const;
        bool vectorArr::operator>=(const vectorArr& smthg) const;
        
        vectorArr vectorArr::operator+(const vectorArr& smthg) const;
        
        std::ostream& operator<<(std::ostream& os, const vectorArr& smthg);
        std::istream& operator>>(std::istream& is, vectorArr& smthg);

        ~vectorArr();
};

#endif