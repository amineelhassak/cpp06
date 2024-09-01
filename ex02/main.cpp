#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
    int random = std::rand() % 3;
    if (random == 0) {
        std::cout << "Généré : A" << std::endl;
        return new A();
    } else if (random == 1) {
        std::cout << "Généré : B" << std::endl;
        return new B();
    } else {
        std::cout << "Généré : C" << std::endl;
        return new C();
    }
}

void    identify(Base* p)
{
     if (dynamic_cast<A*>(p)) {
        std::cout << "Identifié : A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "Identifié : B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "Identifié : C" << std::endl;
    } else {
        std::cout << "Type inconnu" << std::endl;
    }
}


void    identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "Identifié : A" << std::endl;
    }
    catch (std::bad_cast&)
    {
        try
        {
            (void)dynamic_cast<B&>(p);
            std::cout << "Identifié : B" << std::endl;
        }
        catch (std::bad_cast&)
        {
            try
            {
                (void)dynamic_cast<C&>(p);
                std::cout << "Identifié : C" << std::endl;
            } 
            catch (std::bad_cast&)
            {
                std::cout << "Type inconnu" << std::endl;
            }
        }
    }
}

int main()
{
    Base* base = generate();
    identify(base);
    identify(*base);
    delete base;
    return 0;
}