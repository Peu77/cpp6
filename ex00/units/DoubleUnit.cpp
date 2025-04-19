//
// Created by Emil Ebert on 19.04.25.
//

#include "DoubleUnit.h"
#include <sstream>

#include <iostream>

DoubleUnit::DoubleUnit() {
    name = "double";
}

DoubleUnit::~DoubleUnit() = default;

DoubleUnit::DoubleUnit(const DoubleUnit &other) = default;

DoubleUnit &DoubleUnit::operator=(const DoubleUnit &other) = default;

std::string DoubleUnit::convert(std::string value) {
    if (value == "inf" || value == "inff")
        return "infinity";

    if (value == "nan" || value == "nanf")
        return "nan";

    if (value.length() == 1 && !std::isdigit(value[0]))
        value = std::to_string(static_cast<double>(value[0]));

    if (value.back() == 'f' || value.back() == 'F')
        value.pop_back();

    std::istringstream iss(value);
    double doubleValue;

    if (!(iss >> doubleValue) || !iss.eof()) {
        return "impossible";
    }

    std::string result = std::to_string(doubleValue);
    while (result.back() == '0' && result[result.length() - 2] != '.') {
        result.pop_back();
    }

    return result;
}
