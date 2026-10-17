#include <iostream>

#define PASS
#define NDEBUG

#include <cassert>

#include "aNum/aNum.h"
#include "aNum/aNum.h"

static int bob = 1;
int hello = 1;

extern const int pp{444};

void do_print() {
    std::cout << "hello\n";
}

void print_value(int /*x*/);

void func1();

void func2();

int idkkk() {
    std::cout << "helloooo" << '\n';
    return -1;
}

int main() {
    const auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";

    for (int i = 1; i <= 5; i++) {
        std::cout << "i = " << i << std::endl;
    }

    // int x{};
    // std::cin >> x;
    //
    // int y{};
    // std::cin >> y;
    //
    // std::cout << "You entered " << x << " and " << y << '\n';
    //
    // int z{};
    // std::cin >> z;
    // std::cout << "You entered " << z;


    int p;
    std::cout << p << '\n';

    std::cout << (p = 4) << '\n';
    std::cout << p << '\n';


    do_print();
    do_print();

    std::cout << aNum() << "\n";
    print_value(3);

    func1();

    return EXIT_SUCCESS;
}

void print_value(int x) {
    std::cout << x << "!\n";
}

// g++ -E main.cpp
#define ONE 1

namespace n1 {
    void aFunc1() {
        std::cout << "a func " << ONE << '\n';
    }
}

namespace n2 {
    void aFunc2() {
        std::cout << "a func 2" << '\n';
    }
}

namespace {
    int idk = -3;
}

inline int aFuncDef() {
    return -2;
}

void func1() {
    n1::aFunc1();
    n2::aFunc2();

    using namespace n1;
    using namespace n2;

    aFunc1();
    aFunc2();

    // #define HELLO

#ifdef HELLO
    std::cout << "Hello" << '\n';
#else
    std::cout << "No hello\n";
#endif

#ifndef IDKK
    std::cout << "idkkk\n";
#endif
#ifndef HELLO
    std::cout << "Not hello\n";
#endif

#if 3
    std::cout << "hiii\n";
#endif

    std::cout << aNum() << "\n";
    std::cout << ANumNamespace::aNum() << "\n";

    std::cout << ANumNamespace::AnotherANumNamespace::aNum() << "\n";
    namespace Alias = ANumNamespace::AnotherANumNamespace;
    std::cout << Alias::aNum() << "\n";

    std::cout << idk << '\n';

    aFuncDef();
    func2();
}

namespace {
    int yeahhBoyy() {
        return -1;
    }
}

auto trailing_syntax(int x = 3) -> int {
    return x;
}

void printInt(int x) {
    std::cout << x << '\n';
}

// void printInt(char) = delete;
// void printInt(bool) = delete;

template <typename T>
void printInt(T x) = delete;

void func3();

void func2() {
    std::cout << yeahhBoyy() << '\n';

    if (false)
        std::cout << 1 << '\n';;

    PASS

    if (true)
        PASS;

    if (true)
        ;

    const int x{1};

    constexpr double gravity{x};
    if constexpr (gravity == 9.8)
        std::cout << "Gravity is normal" << '\n';
    else
        std::cout << "Gravity not normal" << '\n';

    switch (1) {
        int y;
        case 1:
            y = 1;
            std::cout << y << '\n';
        case 2: {
            int xx = 3;
            std::cout << y << '!' << xx << '\n';
            break;
        }
        default:
            std::cout << "default" << '\n';
    }

    assert(false && "hello");
    constexpr int z = 1;
    static_assert(z == 1);

    int zz = static_cast<int>(z);

    using Miles = int;
    Miles m{3};
    print_value(m);

    std::cout << trailing_syntax(4) << std::endl;

    printInt(1);
    // printInt(1u);
    // printInt('a');
    // printInt(false);

    func3();
}

template <typename T, typename U>
T max(T x, U y) {
    return (x > y) ? x : y;
}

template <typename T>
T addOne(T x) {
    return x + 1;
}

std::string addOne(std::string x) {
    return x + "!";
}

void func3() {
    int x;
    int y;

    std::cout << max(1,2) << '\n';
    std::cout << max(4.1,2.0) << '\n';
    std::cout << max("hello","he") << '\n';
    std::cout << max(&x,&y) << '\n';
    //
    // struct Person {
    //     int age;
    // };
    //
    // Person a{20};
    // Person b{30};
    //
    // max(a, b);

    std::cout << addOne(std::string("hello")) << '\n';
}
