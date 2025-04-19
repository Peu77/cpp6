//
// Created by Emil Ebert on 18.04.25.
//

#include "ScalarConverter.h"

#include <iostream>

#include "units/CharUnit.h"
#include "units/DoubleUnit.h"
#include "units/FloatUnit.h"
#include "units/IntUnit.h"
#include <memory>
#include <array>

std::array<std::unique_ptr<IUnit>, 4> ScalarConverter::units = {
    std::make_unique<CharUnit>(),
    std::make_unique<DoubleUnit>(),
    std::make_unique<FloatUnit>(),
    std::make_unique<IntUnit>()
};


void ScalarConverter::convert(std::string value) {
    for (auto &unit: units)
        std::cout << unit->name << ": " << unit->convert(value) << std::endl;
}
