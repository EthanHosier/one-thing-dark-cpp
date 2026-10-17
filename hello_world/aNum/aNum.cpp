#include "aNum.h"

#include <iostream>

static int bob = 3;
extern int hello;

int idkkk();
extern const int pp;

int yeahhBoyy();

int aNum() {
    std::cout << huh  << pp << "\n";
    idkkk();
    return 9999;
}

inline int aFuncDef() {
    return -2;
}

namespace ANumNamespace {
    int aNum() {
        hello += 4;
        std::cout << hello << '\n';
        return 8888;
    }

    namespace AnotherANumNamespace {
        int aNum() {
            aFuncDef();
            return 777;
        }
    }
}
