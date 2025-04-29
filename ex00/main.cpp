#include <iomanip>
#include <iostream>
#include <ostream>
#include "ScalarConverter.h"

int main(const int argc, const char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <value>" << std::endl;
        return 1;
    }

    ScalarConverter::convert(argv[1]);
    return 0;
}
