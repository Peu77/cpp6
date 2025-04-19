//
// Created by Emil Ebert on 19.04.25.
//

#ifndef UNIT_H
#define UNIT_H

#include <string>

class IUnit {
public:
  std::string name;
  virtual ~IUnit() = default;
  virtual std::string convert(std::string value) = 0;
};



#endif //UNIT_H
