#ifndef TESTA_H
#define TESTA_H

#include <string.h>
#include <functional>

class TestA
{
public:
    TestA();

    static std::string StaticCallback(){
        return "Static member callback";
    }

    std::string NonstaticCallback(){
        return member;
    }

private:
    std::string member = "Non static member callback";
};

#endif // TESTA_H
