//
// Created by Ethan Hosier on 13/10/2026.
//

#ifndef HELLO_WORLD_ANUM_HPP
#define HELLO_WORLD_ANUM_HPP

static int huh = 3;

int aNum();
int anotherNum();

inline int aFuncDef();

namespace ANumNamespace {
    int aNum();

    namespace AnotherANumNamespace {
        int aNum();
    }
}

#endif //HELLO_WORLD_ANUM_HPP
