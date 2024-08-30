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
    if (static_cast<int>(c) < 32 || static_cast<int>(c) > 126)
        std::cout<< "char : can't display" << std::endl;
    else 
        std::cout << "char : '" << static_cast<char>(c) << "'" << std::endl;
    std::cout << "int : " << static_cast<int>(c) << std::endl;
    std::cout << "float : " << static_cast<float>(c) << std::endl;
    std::cout << "double : " << static_cast<double>(c) << std::endl;
}

void toInt(std::string str)
{
    double dbl = strtod(str.c_str(),0);

    if (static_cast<int>(dbl) < 0 || static_cast<int>(dbl) > 255)
        std::cout << "char : overflow" << std::endl;
    else if (static_cast<int>(dbl) < 32 || static_cast<int>(dbl) > 126)
        std::cout<< "char : can't display" << std::endl;
    else
        std::cout << "char : '" << static_cast<char>(dbl) << "'" << std::endl;
    if (dbl > static_cast<double>(INT_MAX) || dbl < static_cast<double>(INT_MIN))
        std::cout << "int : overflow" << std::endl;
    else
        std::cout << "int : " << static_cast<int>(dbl) << std::endl;
    std::cout << "float : " << static_cast<float>(dbl) << "f" << std::endl;
    std::cout << "double : " << static_cast<double>(dbl) << std::endl;
}

void    toFloatDouble(std::string str)
{
    double dbl = strtof(str.c_str(),0);

    if (str == "nanf")
    {
        std::cout << "int : impossible" << std::endl;
        std::cout << "char : impossible" << std::endl;
        std::cout << "float : " << static_cast<float>(dbl)  << "f" << std::endl;
        std::cout << "double : " << static_cast<double>(dbl) << std::endl;
        return ;
    }
    if (str == "nan")
    {
        std::cout << "int : impossible" << std::endl;
        std::cout << "char : impossible" << std::endl;
        std::cout << "float : " << static_cast<float>(dbl) << "f" << std::endl;
        std::cout << "double : " << static_cast<double>(dbl) << std::endl;
        return ;
    }
    if (static_cast<int>(dbl) < 0 || static_cast<int>(dbl) > 255)
        std::cout << "char : overflow" << std::endl;
    else if (static_cast<int>(dbl) < 32 || static_cast<int>(dbl) > 126)
        std::cout<< "char : can't display" << std::endl;
    else
        std::cout << "char : '" << static_cast<char>(dbl) << "'" << std::endl;
    if (dbl > static_cast<double>(INT_MAX) || dbl < static_cast<double>(INT_MIN))
        std::cout << "int : overflow" << std::endl;
    else
        std::cout << "int : " << static_cast<int>(dbl) << std::endl;
    std::cout << "float : " << std::fixed << std::setprecision(2) << static_cast<float>(dbl) << "f" << std::endl;
    std::cout << "double : " << std::fixed << std::setprecision(2) << static_cast<double>(dbl) << std::endl;
}

void ScalarConverter::convert(std::string str)
{
    
    if (isChar(str))
        toChar(str);
    else if(isInt(str))
        toInt(str);
    else if (isFloat(str) || isDouble(str))
        toFloatDouble(str);
    else
        std::cout << "UNKNOWN" << std::endl;
}

bool isChar(std::string str)
{
    return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}

bool isInt(std::string str)
{
    char *end = 0;
    std::strtol(str.c_str(), &end, 10);
    std::string rest = end;
    return(rest.empty());
}

bool    isFloat(std::string str)
{
    char *end = 0;
    size_t pos = str.find('.');
    if (str == "-inff" || str == "+inff" || str == "nanf")
        return (true);
    if (!str.empty() && (str[str.length() - 1] == '.' || str[0] == '.' || str == "nan" || str == "inf" || \
        (str[pos - 1] && !(str[pos - 1] >='0' && str[pos - 1] <= '9')) ||  (str[pos + 1] && str[pos + 1] == 'f')))
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
    size_t pos = str.find('.');
    if (str == "-inf" || str == "+inf" || str == "nan")
		return (true);
    if (!str.empty() && (str[str.length() - 1] == '.' || str[0] == '.' || str == "inf" || \
        (str[pos - 1] && !(str[pos - 1] >='0' && str[pos - 1] <= '9')) ||  (str[pos + 1] && str[pos + 1] == 'f')))
        return (false);
    std::strtod(str.c_str(), &end);
    return((end != str.c_str() && *end =='\0'));
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter : " << " destructeur est appelé " << std::endl;
}
