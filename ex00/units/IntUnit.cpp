//
// Created by Emil Ebert on 19.04.25.
//

#include "IntUnit.h"

#include <iostream>
#include <sstream>

IntUnit::IntUnit() {
    name = "int";
}

IntUnit::~IntUnit() = default;

IntUnit::IntUnit(const IntUnit &other) = default;

IntUnit &IntUnit::operator=(const IntUnit &other) = default;

std::string IntUnit::convert(std::string value) {
    if (value == "nan" || value == "nanf" || value == "inf" || value == "inff") {
        return "impossible";
    }

    try {
        if (value.length() == 1 && !std::isdigit(value[0]))
            value = std::to_string(static_cast<int>(value[0]));

        if (value.back() == 'f' || value.back() == 'F')
            value.pop_back();
        std::istringstream iss(value);
        float floatValue;

        if (!(iss >> floatValue) || !iss.eof()) {
            return "impossible";
        }

        const int intValue = static_cast<int>(floatValue);
        return std::to_string(intValue);
    } catch (...) {
        return "impossible";
    }
}
