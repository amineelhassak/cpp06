#include "ScalarConverter.hpp"

int main(int ac,char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: invalid" << std::endl;
        return (1);
    }
    else
    {
        std::string str = av[1];
        if (str.empty())
        {
            std::cout << "Empty string" << std::endl;
            return (1);
        }
        else
        {
            ScalarConverter::convert(av[1]);
        }
    }
}