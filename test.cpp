#include <iostream>
// #include <string>
// #include <cstdlib> // Pour std::strtof et std::strtod
// #include <cerrno>  // Pour gérer les erreurs

// bool isFloat(const std::string &str)
// {
//     char *end = nullptr;
//     errno = 0;

//     float val = std::strtof(str.c_str(), &end);
//     std::cout << "=====================> " << val << std::endl;
//     std::cout << "=====================> " << end << std::endl;
//     std::cout << end << std::endl;
//     if (errno == ERANGE || *end != '\0') {
//         return false;
//     }
//     return true;
// }


int main(int ac,char **av)
{
    float  f  = 0.5f;
    int n = static_cast <float>(f);
    std::cout << n << std::endl;
    // std::string test1 = "123.45";
    // std::string test2 = "42";
    // std::string test3 = "abc";
    // std::string test4 = "1.0f";
    // std::string test5 = "-inf";
    
    // std::cout << "Test 1 : " << (isFloat(test1) ? "Valide" : "Invalide") << std::endl;
    // std::cout << "Test 2 : " << (isFloat(test2) ? "Valide" : "Invalide") << std::endl;
    // std::cout << "Test 3 : " << (isFloat(test3) ? "Valide" : "Invalide") << std::endl;
    // std::cout << "Test 4 : " << (isFloat(test4) ? "Valide" : "Invalide") << std::endl;
    // std::cout << "Test 5 : " << (isFloat(test5) ? "Valide" : "Invalide") << std::endl;

    return 0;
}
