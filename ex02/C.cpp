//
// Created by Emil Ebert on 19.04.25.
//

#include "C.h"
#include <iostream>
#include "colors.h"

C::~C() {
    std::cout << GREEN << "Destructor C called" << RESET << std::endl;
}