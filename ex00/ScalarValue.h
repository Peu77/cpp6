#ifndef SCALAR_VALUE_H
#define SCALAR_VALUE_H

#include <string>
#include <limits>
#include <cmath>

enum ValueType {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID
};

class ScalarValue {
private:
    ValueType type;

    union {
        char charValue{};
        int intValue;
        float floatValue;
        double doubleValue;
    };

public:
    ScalarValue() : type(ValueType::INVALID) {
    }

    explicit ScalarValue(char value) : type(ValueType::CHAR), charValue(value) {
    }

    explicit ScalarValue(int value) : type(ValueType::INT), intValue(value) {
    }

    explicit ScalarValue(float value) : type(ValueType::FLOAT), floatValue(value) {
    }

    explicit ScalarValue(double value) : type(ValueType::DOUBLE), doubleValue(value) {
    }

    template<typename T>
    T getValue() const {
        static_assert(std::is_same_v<T, char> ||
                      std::is_same_v<T, int> ||
                      std::is_same_v<T, float> ||
                      std::is_same_v<T, double>,
                      "Unsupported value type");

        if (type == ValueType::INVALID) {
            throw std::runtime_error("Invalid scalar value");
        }

        switch (type) {
            case CHAR: return static_cast<T>(intValue);
            case INT: return static_cast<T>(intValue);
            case FLOAT: return static_cast<T>(floatValue);
            case DOUBLE: return static_cast<T>(doubleValue);
            default: return 0;
        }
    }
};

#endif // SCALAR_VALUE_H
