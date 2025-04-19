#include "Serializer.h"
#include "colors.h"

int main() {
    Data* data = new Data();
    data->i = 42;
    data->f = 3.14f;
    data->d = 2.718281828459045;
    data->s = "Hello, World!";
    std::cout << YELLOW << "Original Data:" << RESET << std::endl;
    std::cout << "i: " << data->i << std::endl;
    std::cout << "f: " << data->f << std::endl;
    std::cout << "d: " << data->d << std::endl;
    std::cout << "s: " << data->s << std::endl;

    uintptr_t raw = Serializer::serialize(data);
    std::cout << YELLOW << "Serialized Data:" << RESET << std::endl;
    std::cout << "raw: " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << YELLOW << "Deserialized Data:" << RESET << std::endl;
    std::cout << "i: " << deserializedData->i << std::endl;
    std::cout << "f: " << deserializedData->f << std::endl;
    std::cout << "d: " << deserializedData->d << std::endl;
    std::cout << "s: " << deserializedData->s << std::endl;
    std::cout << YELLOW << "Memory Address:" << RESET << std::endl;
    std::cout << "Original: " << data << std::endl;
    std::cout << "Deserialized: " << deserializedData << std::endl;
    std::cout << YELLOW << "Memory Address Comparison:" << RESET << std::endl;
    if (data == deserializedData) {
        std::cout << GREEN << "The memory addresses are the same." << RESET << std::endl;
    } else {
        std::cout << RED << "The memory addresses are different." << RESET << std::endl;
    }
    delete data;
    return 0;
}
