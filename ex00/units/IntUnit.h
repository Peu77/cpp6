//
// Created by Emil Ebert on 19.04.25.
//

#ifndef INTUNIT_H
#define INTUNIT_H

#include "../IUnit.h"

class IntUnit: public IUnit {
public:
    IntUnit();
    ~IntUnit();
    IntUnit(const IntUnit& other);
    IntUnit& operator=(const IntUnit& other);

    std::string convert(std::string value) override;
};



#endif //INTUNIT_H
