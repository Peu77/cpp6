//
// Created by Emil Ebert on 19.04.25.
//

#include "IntUnit.h"

#include <iostream>
#include <regex>
#include <sstream>
#include <limits.h>

IntUnit::IntUnit() {
    name = "int";
}

IntUnit::~IntUnit() = default;

IntUnit::IntUnit(const IntUnit &other) = default;

IntUnit &IntUnit::operator=(const IntUnit &other) = default;

ScalarValue IntUnit::convert(const std::string value) {
    return ScalarValue(std::stoi(value));
}

void IntUnit::castAndPrint(ScalarValue& value) {
    double doubleValue = value.getValue<double>();

    if (std::isnan(doubleValue)) {
        std::cout << "impossible" << std::endl;
        return;
    }

    if (std::isinf(doubleValue)) {
        std::cout << "impossible" << std::endl;
        return;
    }

    if (doubleValue > static_cast<double>(std::numeric_limits<int>::max()) || doubleValue < static_cast<double>(std::numeric_limits<int>::min())) {
        std::cout << "impossible" << std::endl;
        return;
    }

    std::cout << value.getValue<int>() << std::endl;
}

bool IntUnit::isTypeOf(std::string value) {
    if (const std::regex intRegex("^[+-]?\\d+$"); !std::regex_match(value, intRegex))
        return false;

    try {
        std::size_t pos;
        std::stoi(value, &pos);
        return pos == value.length();
    } catch (...) {
        return false;
    }
}
