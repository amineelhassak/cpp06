#pragma once
#include <iostream>
#include <cstdint>

typedef struct Data_t {
    int id;
    std::string name;
    double value;
} data;

class Serializer
{
    private:
        Serializer();
    public :
        Serializer &operator = (const Serializer & bur);
        Serializer(const Serializer &bur);
        ~Serializer();
        static uintptr_t serialize(data* ptr);
        static data* deserialize(uintptr_t raw);
};
