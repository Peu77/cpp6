//
// Created by Emil Ebert on 19.04.25.
//

#ifndef DOUBLEUNIT_H
#define DOUBLEUNIT_H



#include "../IUnit.h"

class DoubleUnit: public IUnit {
public:
    DoubleUnit();
    ~DoubleUnit();
    DoubleUnit(const DoubleUnit& other);
    DoubleUnit& operator=(const DoubleUnit& other);

    std::string convert(std::string value) override;
};



#endif //DOUBLEUNIT_H
