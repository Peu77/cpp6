//
// Created by Emil Ebert on 19.04.25.
//

#ifndef FLOATUNIT_H
#define FLOATUNIT_H

#include "../IUnit.h"

class FloatUnit: public IUnit {
public:
    FloatUnit();
    ~FloatUnit() override;
    FloatUnit(const FloatUnit& other);
    FloatUnit& operator=(const FloatUnit& other);

    void castAndPrint(ScalarValue& value) override;
    ScalarValue convert(std::string value) override;
    bool isTypeOf(std::string value) override;
};




#endif //FLOATUNIT_H
