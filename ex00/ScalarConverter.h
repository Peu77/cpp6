//
// Created by Emil Ebert on 18.04.25.
//

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <string>
#include <array>
#include "IUnit.h"

class ScalarConverter {
  private:
    static std::array<std::unique_ptr<IUnit>, 4> units;

public:
    static void convert(std::string value);
};



#endif //SCALARCONVERTER_H
