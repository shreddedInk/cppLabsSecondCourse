#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class WeightLimitExceededException : public std::runtime_error {
public:
    explicit WeightLimitExceededException(const std::string& message)
        : std::runtime_error(message) {}

    WeightLimitExceededException()
        : std::runtime_error("Превышен лимит веса. Невозможно добавить коробку.") {}
};

#endif 