//
// Created by Emil Ebert on 19.04.25.
//

#include "FloatUnit.h"
#include <sstream>

FloatUnit::FloatUnit() {
    name = "float";
}

FloatUnit::~FloatUnit() = default;

FloatUnit::FloatUnit(const FloatUnit& other) = default;

FloatUnit& FloatUnit::operator=(const FloatUnit& other) = default;

std::string FloatUnit::convert(std::string value) {

    if (value == "inf" || value == "inff")
        return "infinityf";

    if (value == "nan" || value == "nanf")
        return "nanf";

    if (value.length() == 1 && !std::isdigit(value[0]))
        value = std::to_string(static_cast<float>(value[0]));

    if (value.back() == 'f' || value.back() == 'F')
        value.pop_back();

    std::istringstream iss(value);
    float floatValue;
    if (!(iss >> floatValue) || !iss.eof()) {
        return "impossible";
    }

    std::string result = std::to_string(floatValue);
    while (result.back() == '0' && result[result.length() - 2] != '.') {
        result.pop_back();
    }

    return result + "f";
}