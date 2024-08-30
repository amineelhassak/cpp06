#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <iostream>
#include <iomanip>


class ScalarConverter
{
    private:
        ScalarConverter();
    public:
        static void convert(std::string literal);
        ScalarConverter &operator =(const ScalarConverter & bur);
        ScalarConverter(const ScalarConverter &bur);
        ~ScalarConverter();
};

bool isChar(std::string str);
bool isInt(std::string str);
bool isFloat(std::string str);
bool isDouble(std::string str);
void toChar(std::string str);
void toFloatDouble(std::string str);
#endif