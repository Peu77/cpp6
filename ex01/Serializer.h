//
// Created by Emil Ebert on 19.04.25.
//

#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <iostream>

typedef struct Data {
    int         i;
    float       f;
    double      d;
    std::string s;
} Data;

class Serializer {
  private:
    Serializer() = delete;
    Serializer(const Serializer&) = delete;
    Serializer& operator=(const Serializer&) = delete;
    ~Serializer() = delete;

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};



#endif //SERIALIZER_H
