//
// Created by Emil Ebert on 19.04.25.
//

#include "CharUnit.h"
#include <sstream>

CharUnit::CharUnit() {
    name = "char";
}

CharUnit::~CharUnit() = default;

CharUnit::CharUnit(const CharUnit &other) = default;

CharUnit &CharUnit::operator=(const CharUnit &other) = default;

std::string CharUnit::convert(std::string value) {
    if (value.length() == 1) {
        return value;
    }

    if (value == "nan" || value == "nanf" || value == "inf" || value == "inff")
        return "impossible";

    try {
        if (value.back() == 'f' || value.back() == 'F')
            value.pop_back();

        std::istringstream iss(value);
        float floatValue;

        if (!(iss >> floatValue) || !iss.eof()) {
            return "impossible";
        }
        if (!std::isprint(static_cast<int>(floatValue))) {
            return "non displayable";
        }
        char charValue = static_cast<char>(floatValue);
        return {1, charValue};
    } catch (...) {
        return "impossible";
    }
}
