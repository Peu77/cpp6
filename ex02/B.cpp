//
// Created by Emil Ebert on 19.04.25.
//

#include "B.h"
#include <iostream>
#include "colors.h"

B::~B() {
    std::cout << GREEN << "Destructor B called" << RESET << std::endl;
}