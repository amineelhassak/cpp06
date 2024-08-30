#pragma once
#include <iostream>

class Serializer
{
    private:
        Serializer();
    public :
        Serializer &operator =(const Serializer & bur);
        Serializer(const Serializer &bur);
        ~Serializer();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};