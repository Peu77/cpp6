//
// Created by Emil Ebert on 19.04.25.
//

#ifndef INTUNIT_H
#define INTUNIT_H

#include "../IUnit.h"
#include "../ScalarValue.h"

class IntUnit: public IUnit {
public:
    IntUnit();
    ~IntUnit() override;
    IntUnit(const IntUnit& other);
    IntUnit& operator=(const IntUnit& other);

    void castAndPrint(ScalarValue& value) override;
    ScalarValue convert(std::string value) override;
    bool isTypeOf(std::string value) override;
};



#endif //INTUNIT_H
