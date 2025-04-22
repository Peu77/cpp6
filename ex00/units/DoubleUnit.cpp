//
// Created by Emil Ebert on 19.04.25.
//

#include "DoubleUnit.h"

#include <iomanip>
#include <sstream>

#include <iostream>
#include <regex>

DoubleUnit::DoubleUnit() {
    name = "double";
}

DoubleUnit::~DoubleUnit() = default;

DoubleUnit::DoubleUnit(const DoubleUnit &other) = default;

DoubleUnit &DoubleUnit::operator=(const DoubleUnit &other) = default;

ScalarValue DoubleUnit::convert(const std::string value) {
    return ScalarValue(std::stod(value));
}

void DoubleUnit::castAndPrint(ScalarValue& value) {
    double doubleValue = value.getValue<double>();

    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << doubleValue;

    std::string result = ss.str();
    while (result.back() == '0' && result[result.length() - 2] != '.') {
        result.pop_back();
    }

    std::cout << result << std::endl;

}

bool DoubleUnit::isTypeOf(std::string value) {
    if (value == "nan" || value == "inf" || value == "+inf" || value == "-inf")
        return true;

    int dotCount = 0;
    for (const char c : value) {
        if (c == '.')
            dotCount++;
    }

    if (dotCount != 1)
        return false;

    std::regex doubleRegex(R"(^[+-]?(\d+\.\d*|\.\d+|\d+)$)");
    if (!std::regex_match(value, doubleRegex))
        return false;

    try {
        std::size_t pos;
        std::stod(value, &pos);
        return pos == value.length();
    } catch (...) {
        return false;
    }
}
