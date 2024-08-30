#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter : constructeur par défaut est appelé " << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &bur)
{
    (void)bur;
    std::cout << "ScalarConverter : constructeur de copie est appelé pour " << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &bur)
{
    std::cout << "ScalarConverter : " << " opérateur d'assignation appelé " << std::endl;
    (void)bur;
    return *this;
}

void toChar(std::string str)
{
    char c = str[1];
	if (static_cast<int> (c) < 32 || static_cast<int> (c)  > 126)
		std::cout << "char: can't display" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(c) << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convert(std::string str)
{
    
    if (isChar(str))
    {
        std::cout << "is char "  << std::endl;
        toChar(str);
    }
    else if(isInt(str)){
        std::cout << "is Int "  << std::endl;
    }
    else if (isFloat(str))
    {
        std::cout << "is float "  << std::endl;
    }
    else if (isDouble(str))
    {
        std::cout << "is double "  << std::endl;
    }
}

bool isChar(std::string str)
{
    return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');/*????*/
}

bool isInt(std::string str)
{
    char *end = 0;
    long long nombrell = std::strtoll(str.c_str(), &end, 10);
    std::string rest = end;
    return(rest.empty() && nombrell < INT_MAX && nombrell > INT_MIN);
}

bool    isFloat(std::string str)
{
    char *end = 0;
    if (str == "-inff" || str == "+inff" || str == "nanf")
        return (true);
    if (!str.empty() && (str[str.length() - 1] == '.' || str[0] == '.' || str == "nan" || str == "inf"))
        return (false);
    std::strtof(str.c_str(), &end);
    if (str.find('f') != std::string::npos)
    {
        if (str.find('f') != (str.length() - 1))
            return (false);
        return (end != str.c_str() && *end =='f');
    }
    return (end != str.c_str() && *end =='\0');
}

bool    isDouble(std::string str)
{
    char *end = 0;
    if (str == "-inf" || str == "+inf" || str == "nan")
		return (true);
    if (!str.empty() && (str[str.length() - 1] == '.' || str[0] == '.' || str == "inf"))
        return (false);
    std::strtod(str.c_str(), &end);
    return((end != str.c_str() && *end =='\0'));
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter : " << " destructeur est appelé " << std::endl;
}
