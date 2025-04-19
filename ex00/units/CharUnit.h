//
// Created by Emil Ebert on 19.04.25.
//

#ifndef CHARUNIT_H
#define CHARUNIT_H

#include "../IUnit.h"

class CharUnit: public IUnit {
public:
    CharUnit();
    ~CharUnit();
    CharUnit(const CharUnit& other);
    CharUnit& operator=(const CharUnit& other);

    std::string convert(std::string value) override;
};



#endif //CHARUNIT_H
