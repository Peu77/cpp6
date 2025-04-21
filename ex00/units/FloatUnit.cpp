//
// Created by Emil Ebert on 19.04.25.
//

#include "FloatUnit.h"

#include <iomanip>
#include <iostream>
#include <regex>
#include <sstream>

FloatUnit::FloatUnit() {
    name = "float";
}

FloatUnit::~FloatUnit() = default;

FloatUnit::FloatUnit(const FloatUnit &other) = default;

FloatUnit &FloatUnit::operator=(const FloatUnit &other) = default;

ScalarValue FloatUnit::convert(const std::string value) {
    return ScalarValue(std::stof(value));
}

void FloatUnit::castAndPrint(ScalarValue &value) {
    float floatValue = value.getValue<float>();
    std::stringstream ss;
    ss << std::fixed << std::setprecision(5) << floatValue;

    std::string result = ss.str();
    while (result.back() == '0' && result[result.length() - 2] != '.') {
        result.pop_back();
    }

    std::cout << result << "f" << std::endl;
}

bool FloatUnit::isTypeOf(std::string value) {
    if (value.empty() || (value.back() != 'f' && value.back() != 'F'))
        return false;

    if (value == "nanf" || value == "nanF")
        return true;

    if (std::regex_match(value, std::regex("^[+-]?inf[fF]?$")))
        return true;

    int dotCount = 0;
    for (const char c: value) {
        if (c == '.')
            dotCount++;
    }

    if (dotCount != 1)
        return false;

    std::string numericPart = value.substr(0, value.length() - 1);

    try {
        std::size_t pos;
        std::stof(numericPart, &pos);
        return pos == numericPart.length();
    } catch (...) {
        return false;
    }
}
