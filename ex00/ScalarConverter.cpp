//
// Created by Emil Ebert on 18.04.25.
//

#include "ScalarConverter.h"

#include <iostream>

#include "units/CharUnit.h"
#include "units/DoubleUnit.h"
#include "units/FloatUnit.h"
#include "units/IntUnit.h"

std::unique_ptr<IUnit> ScalarConverter::units[4] = {
    std::make_unique<CharUnit>(),
    std::make_unique<DoubleUnit>(),
    std::make_unique<FloatUnit>(),
    std::make_unique<IntUnit>()
};


void ScalarConverter::convert(std::string value) {
    IUnit *valueUnit = nullptr;
    for (auto &unit: units) {
        if (unit->isTypeOf(value)) {
            valueUnit = unit.get();
            break;
        }
    }
    if (valueUnit == nullptr) {
        std::cout << "Invalid value" << std::endl;
        return;
    }

    std::cout << valueUnit->name << std::endl;

    auto convertedValue = valueUnit->convert(value);
    for (auto &unit: units) {
            std::cout << unit->name << ": ";
            unit->castAndPrint(convertedValue);
    }
}
