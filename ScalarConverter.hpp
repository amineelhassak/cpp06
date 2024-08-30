#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <iostream>

enum
{
	CHAR,
    INT,
    FLOAT,
    DOUBLE,
    UNKNOW
};

class ScalarConverter
{
    private:
        // if (isChar(literal)) {
        //     convertFromChar(literal[1]);  // Convert from char literal like 'a'
        // }
        //  else if (isInt(literal)) {
        //     convertFromInt(std::atoi(literal.c_str()));
        // } else if (isFloat(literal)) {
        //     convertFromFloat(std::strtof(literal.c_str(), nullptr));
        // } else if (isDouble(literal)) {
        //     convertFromDouble(std::strtod(literal.c_str(), nullptr));
        // } else {
        //     handleSpecialCases(literal);
        // }
        // }
    public:
        static void convert(std::string literal);
        ScalarConverter();
        ScalarConverter &operator =(const ScalarConverter & bur);
        ScalarConverter(const ScalarConverter &bur);
        ~ScalarConverter();
};

bool isChar(std::string str);
bool isInt(std::string str);
bool isFloat(std::string str);
bool isDouble(std::string str);
void toChar(std::string str);
#endif