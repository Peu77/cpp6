//
// Created by Emil Ebert on 19.04.25.
//

#ifndef CHARUNIT_H
#define CHARUNIT_H

#include "../IUnit.h"

class CharUnit: public IUnit {
public:
    CharUnit();
    ~CharUnit() override;
    CharUnit(const CharUnit& other);
    CharUnit& operator=(const CharUnit& other);

    void castAndPrint(ScalarValue& value) override;
    ScalarValue convert(std::string value) override;
    bool isTypeOf(std::string value) override;
};



#endif //CHARUNIT_H
