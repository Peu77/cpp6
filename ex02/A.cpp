//
// Created by Emil Ebert on 19.04.25.
//

#include "A.h"
#include <iostream>
#include "colors.h"

A::~A() {
    std::cout << GREEN << "Destructor A called" << RESET << std::endl;
}