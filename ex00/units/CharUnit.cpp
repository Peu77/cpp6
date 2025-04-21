//
// Created by Emil Ebert on 19.04.25.
//

#include "CharUnit.h"
#include <sstream>
#include <iostream>

CharUnit::CharUnit() {
    name = "char";
}

CharUnit::~CharUnit() = default;

CharUnit::CharUnit(const CharUnit &other) = default;

CharUnit &CharUnit::operator=(const CharUnit &other) = default;

void CharUnit::castAndPrint(ScalarValue& value) {
    double doubleValue = value.getValue<double>();

    if (std::isnan(doubleValue)) {
        std::cout << "impossible" << std::endl;
        return;
    }

    if (std::isinf(doubleValue)) {
        std::cout << "impossible" << std::endl;
        return;
    }

    if (doubleValue > std::numeric_limits<char>::max() || doubleValue < std::numeric_limits<char>::min()) {
        std::cout << "impossible" << std::endl;
        return;
    }

    char charValue = static_cast<char>(doubleValue);


    if (!std::isprint(charValue)) {
        std::cout << "non displayable" << std::endl;
        return;
    }

    std::cout << charValue << std::endl;
}

ScalarValue CharUnit::convert(std::string value) {
    return ScalarValue(value[0]);
}

bool CharUnit::isTypeOf(const std::string value) {
    return value.length() == 1 && !std::isdigit(value[0]);
}
