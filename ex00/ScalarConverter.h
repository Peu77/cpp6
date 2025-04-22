//
// Created by Emil Ebert on 18.04.25.
//

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <string>
#include <memory>
#include "IUnit.h"

class ScalarConverter {
  private:
    static std::unique_ptr<IUnit> units[4];
    ScalarConverter() = delete;
    ScalarConverter(const ScalarConverter &other) = delete;
    ScalarConverter &operator=(const ScalarConverter &other) = delete;
    ~ScalarConverter() = delete;

public:
    static void convert(std::string value);
};



#endif //SCALARCONVERTER_H
