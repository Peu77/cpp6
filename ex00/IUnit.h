//
// Created by Emil Ebert on 19.04.25.
//

#ifndef UNIT_H
#define UNIT_H

#include <string>

#include "ScalarValue.h"


class IUnit {
public:
  virtual ~IUnit() = default;

  std::string name;
  virtual ScalarValue convert(std::string value) = 0;
  virtual void castAndPrint(ScalarValue& value) = 0;
  virtual bool isTypeOf(std::string value) = 0;
};



#endif //UNIT_H
