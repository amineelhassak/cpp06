#include "Serializer.hpp"

int main()
{
    data *dat = new data;
    dat->id = 1;
    dat->name = "Example";
    dat->value =42.0;

    uintptr_t raw = Serializer::serialize(dat);

    dat  = Serializer::deserialize(raw);

    std::cout << "Success! Deserialized pointer matches the original pointer." << std::endl;
    std::cout << "Data contents:" << std::endl;
    std::cout << "ID: " << dat->id << std::endl;
    std::cout << "Name: " << dat->name << std::endl;
    std::cout << "Value: " << dat->value << std::endl;
    return (0);
}

// #include <stdlib.h>
// int main()
// {
//     data *ptr = new data;
//     std::cout << ptr << std::endl;
//     ptr->id = 102902;
//     uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
//     std::cout << raw << std::endl;
// }
// Pour convertir l'adresse mémoire en base 16 (hexadécimale) 0x131606950 en base 10 (décimale), vous pouvez interpréter cette valeur comme suit :

// L'adresse mémoire 0x131606950 est un nombre en hexadécimal. Chaque chiffre hexadécimal représente une puissance de 16.

// Étape de Conversion
// Voici la conversion de 0x131606950 en base 10 :

// Identifier les positions et leurs valeurs en base 16 :

// scss
// Copier le code
// 0x131606950 = (1 * 16^8) + (3 * 16^7) + (1 * 16^6) + (6 * 16^5) + (0 * 16^4) + (6 * 16^3) + (9 * 16^2) + (5 * 16^1) + (0 * 16^0)
// Calculer chaque terme :

// 1
// ×
// 1
// 6
// 8
// =
// 1
// ×
// 4294967296
// =
// 4294967296
// 1×16 
// 8
//  =1×4294967296=4294967296
// 3
// ×
// 1
// 6
// 7
// =
// 3
// ×
// 268435456
// =
// 805306368
// 3×16 
// 7
//  =3×268435456=805306368
// 1
// ×
// 1
// 6
// 6
// =
// 1
// ×
// 16777216
// =
// 16777216
// 1×16 
// 6
//  =1×16777216=16777216
// 6
// ×
// 1
// 6
// 5
// =
// 6
// ×
// 1048576
// =
// 6291456
// 6×16 
// 5
//  =6×1048576=6291456
// 0
// ×
// 1
// 6
// 4
// =
// 0
// ×
// 65536
// =
// 0
// 0×16 
// 4
//  =0×65536=0
// 6
// ×
// 1
// 6
// 3
// =
// 6
// ×
// 4096
// =
// 24576
// 6×16 
// 3
//  =6×4096=24576
// 9
// ×
// 1
// 6
// 2
// =
// 9
// ×
// 256
// =
// 2304
// 9×16 
// 2
//  =9×256=2304
// 5
// ×
// 1
// 6
// 1
// =
// 5
// ×
// 16
// =
// 80
// 5×16 
// 1
//  =5×16=80
// 0
// ×
// 1
// 6
// 0
// =
// 0
// ×
// 1
// =
// 0
// 0×16 
// 0
//  =0×1=0
// Additionner les termes pour obtenir la valeur en base 10 :

// 4294967296
// +
// 805306368
// +
// 16777216
// +
// 6291456
// +
// 0
// +
// 24576
// +
// 2304
// +
// 80
// +
// 0
// =
// 5139347328
// 4294967296+805306368+16777216+6291456+0+24576+2304+80+0=5139347328
// Résultat
// L'adresse hexadécimale 0x131606950 correspond à 5139347328 en base 10.