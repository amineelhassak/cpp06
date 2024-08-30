#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Serializer : constructeur par défaut est appelé " << std::endl;
}

Serializer::Serializer(const Serializer &bur)
{
    (void)bur;
    std::cout << "Serializer : constructeur de copie est appelé pour " << std::endl;
}

Serializer& Serializer::operator=(const Serializer &bur)
{
    std::cout << "Serializer : " << " opérateur d'assignation appelé " << std::endl;
    (void)bur;
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{

}

Data* Serializer::deserialize(uintptr_t raw)
{

}

Serializer::~Serializer()
{
    std::cout << "Serializer : " << " destructeur est appelé " << std::endl;
}
