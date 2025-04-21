//
// Created by Emil Ebert on 19.04.25.
//

#ifndef DOUBLEUNIT_H
#define DOUBLEUNIT_H



#include "../IUnit.h"

class DoubleUnit: public IUnit {
public:
    DoubleUnit();
    ~DoubleUnit() override;
    DoubleUnit(const DoubleUnit& other);
    DoubleUnit& operator=(const DoubleUnit& other);

    void castAndPrint(ScalarValue& value) override;
    ScalarValue convert(std::string value) override;
    bool isTypeOf(std::string value) override;
};



#endif //DOUBLEUNIT_H
