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
    static std::unique_ptr<IUnit> units[4];

public:
    static void convert(std::string value);
};



#endif //SCALARCONVERTER_H
