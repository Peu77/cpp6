#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"
#include <iostream>
#include <random>

#include "colors.h"

Base *generate(void) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 2);

    switch (dist(gen)) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return nullptr;
    }
}

void identify(Base *p) {
    if (p == nullptr) {
        std::cerr << RED << "Null pointer" << RESET << std::endl;
        return;
    }

    if (dynamic_cast<A *>(p))
        std::cout << GREEN << "A" << RESET << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << BLUE << "B" << RESET << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << YELLOW << "C" << RESET << std::endl;
    else
        std::cerr << RED << "Unknown type" << RESET << std::endl;
}

int main() {
    std::cout << "Generating and identifying 10 random objects:" << std::endl;

    for (int i = 0; i < 10; i++) {
        std::cout << "Object " << i + 1 << ": ";
        Base *obj = generate();
        identify(obj);
        delete obj;
    }

    return 0;
}
