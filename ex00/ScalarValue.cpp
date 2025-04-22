//
// Created by Emil Ebert on 21.04.25.
//

#include "ScalarValue.h"

#include <limits>


ScalarValue::ScalarValue() : type(ValueType::INVALID) {}
ScalarValue::ScalarValue(char value) : type(ValueType::CHAR), charValue(value) {}
ScalarValue::ScalarValue(int value) : type(ValueType::INT), intValue(value) {}
ScalarValue::ScalarValue(float value) : type(ValueType::FLOAT), floatValue(value) {}
ScalarValue::ScalarValue(double value) : type(ValueType::DOUBLE), doubleValue(value) {}

ScalarValue::ScalarValue(const ScalarValue &other) : type(other.type) {
    *this = other;
}

ScalarValue &ScalarValue::operator=(const ScalarValue &other) {
    if (this != &other) {
        type = other.type;
        switch (type) {
            case CHAR: charValue = other.charValue; break;
            case INT: intValue = other.intValue; break;
            case FLOAT: floatValue = other.floatValue; break;
            case DOUBLE: doubleValue = other.doubleValue; break;
            default: break;
        }
    }
    return *this;
}

ScalarValue::~ScalarValue() {
}
