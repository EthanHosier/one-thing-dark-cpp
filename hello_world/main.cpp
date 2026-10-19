#include <iostream>

#define PASS
#define NDEBUG

#include <cassert>
#include <string_view>

#include "Employeee.h"
#include "aNum/aNum.h"
#include "aNum/aNum.h"

using namespace std::string_view_literals;


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

template<typename T>
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

template<typename T, typename U>
T max(T x, U y) {
    return (x > y) ? x : y;
}

template<typename T>
T addOne(T x, int n = 1) {
    return x + n;
}

template<>
std::string addOne(std::string x, int n) {
    return x + "!" + static_cast<char>(n);
}

template<>
bool addOne(bool x, int n) = delete;

template<typename T, typename U>
T add(T x, U y) {
    return x + y;
}

auto max2(auto t1, auto t2) {
    return (t1 > t2) ? t1 : t2;
}

template<int N>
void print_times() {
    for (int i = 0; i < N; i++) {
        std::cout << "Hello " << N << '\n';
    }
}

template<int I>
double getSqrt() {
    static_assert(I >= 0.0, "getSqrt(): I must be non-negative");

    if constexpr (I >= 0)
        return std::sqrt(I);

    return 0.0;
}

template<typename T>
constexpr bool is_lvalue(T &) {
    return true;
}

// T&& is an rvalue reference, so this overload will be preferred for rvalues
template<typename T>
constexpr bool is_lvalue(T &&) {
    return false;
}

void func4();

void func3() {
    int x;
    int y;

    std::cout << max(1, 2) << '\n';
    std::cout << max(4.1, 2.0) << '\n';
    std::cout << max("hello", "he") << '\n';
    std::cout << max(&x, &y) << '\n';
    //
    // struct Person {
    //     int age;
    // };
    //
    // Person a{20};
    // Person b{30};
    //
    // max(a, b);

    std::cout << addOne<std::string>(std::string("hello"), 98) << '\n';
    // std::cout << addOne(false) << '\n';
    std::cout << add<float, float>(1, 1.5) << '\n';
    std::cout << max<float>(1, 1.5) << '\n';

    print_times<2>();
    print_times<3>();

    std::cout << getSqrt<1>() << '\n';
    std::cout << getSqrt<2L>() << '\n';
    // std::cout <<  getSqrt<-1>() << '\n';

    std::cout << is_lvalue(x) << '\n';
    std::cout << is_lvalue(x + 1) << '\n';

    func4();
}

void printValue(const std::string &y) // type changed to std::string&
{
    std::cout << y << '\n';
}

void addOnee(int &out) {
    ++out;
}

void printByAddr(const int *ptr) {
    std::cout << *ptr << '\n';
}

void incrAddress(const int *&ptr) {
    ++ptr;
}

std::optional<float> divide(int a, int b) {
    if (!b) {
        return {};
    }

    return static_cast<float>(a) / b;
}

void func5();

void func4() {
    int x{5};
    int &ref{x};

    std::cout << x << '\n';
    std::cout << ref << '\n';

    x += 1;

    std::cout << x << '\n';
    std::cout << ref << '\n';

    const int &y{x};
    ref += 1;

    std::cout << x << '\n';
    std::cout << ref << '\n';
    std::cout << y << '\n';

    char c{'a'};
    const int &r2{c};
    std::cout << r2 << '\n';
    std::cout << c << '\n';
    c = 'b';
    std::cout << r2 << '\n';
    std::cout << c << '\n';

    std::string s{"hello"};
    printValue(s);

    int xx{1};
    std::cout << xx << '\n';
    addOnee(xx);
    std::cout << xx << '\n';
    //
    // const int yy {1};
    // addOnee(yy);
    // std::cout<<yy<<'\n';

    printValue("hello");
    const std::string ss{"hey"};
    printValue(ss);

    const int &a{5};
    // int& a {5};

    int *ptr{};
    int temp{5};
    std::cout << ptr << '\n';
    ptr = &temp;
    std::cout << ptr << '\n';

    int *ptr2{reinterpret_cast<int *>(temp)};
    std::cout << ptr2 << '\n';

    const int *ptrr{&x};
    ptrr += 1;

    // const double d {5};
    // const double* d_ptr {&d};
    // printByAddr(d_ptr);

    std::cout << ptrr << '\n';
    incrAddress(ptrr);
    std::cout << ptrr << '\n';

    std::cout << divide(2, 1).value_or(-1) << '\n';

    const int arr[5] = {3};
    std::cout << arr[3] << '\n';

    func5();
}

enum Color : std::int8_t {
    Red,
    Green,
    Blue,
};

static constexpr std::string_view toString(Color color) {
    switch (color) {
        case Red: return "Red";
        case Green: return "Green";
        case Blue: return "Blue";
    }
    return "Unknown";
}

std::ostream &operator<<(std::ostream &out, Color color) {
    return out << toString(color);
}

enum class Animal {
    Dog,
    Cat
};

struct Employee {
    int id{};
    int age{};
    double wage{};
};

void print_age(Employee &e) {
    std::cout << e.age << '\n';
}

void print_age(Employee *e) {
    std::cout << e->age << '!' << '\n';
}

template<typename T>
struct Pair {
    T first{};
    T second{};
};

template<typename T>
constexpr T max(Pair<T> p) {
    return (p.first < p.second ? p.second : p.first);
}

template<>
int max(Pair<int> p) {
    std::cout << "int max triggered" << '\n';
    return (p.first < p.second ? p.second : p.first);
}

template<typename T>
using Coord = Pair<T>;

template<typename T>
void print(const Coord<T> &c) {
    std::cout << c.first << ' ' << c.second << '\n';
}

void func6();

void func5() {
    Color apple{Red};
    Color shirt{Green};
    Color cup{Blue};

    std::cout << apple << '\n';
    std::cout << shirt << '\n';

    Animal dog{Animal::Dog};
    Animal cat{Animal::Cat};

    using enum Animal;
    Animal dog2{Dog};

    Employee e{.id = 4, .age = 3};
    std::cout << e.age << ',' << e.wage << '\n';

    Employee joe{1, 32, 60000.0};
    joe = {.id = joe.id + 32, .age = 33};
    std::cout << joe.id << ',' << joe.age << ',' << joe.wage << '\n';

    print_age(e);
    print_age(&e);
    auto &ee{e};
    print_age(ee);

    Pair<int> p1{1, 2};
    Pair p2{4.0, 3.0};

    std::cout << max(p1) << '\n';
    std::cout << max(p2) << '\n';

    Coord c1{1, 2};
    std::cout << max(c1) << '\n';
    print(c1);

    func6();
}

class Date {
public:
    explicit Date(const int d) : Date(d, 1, 1) {
        std::cout << "Other constructor" << '\n';
    }

    Date(const int d, const int m, const int y) : day_{d}, month_{m}, year_{y} {
        std::cout << "Constructed (" << day_ << '/' << month_ << '/' << year_ << ')' << '\n';
    };

    Date(const Date& date) : day_{date.day_}, month_{date.month_}, year_{date.year_} {
        std::cout << "Copied!" << '\n';
    }

    static void printSomething() {
        std::cout << "I am a date class" << '\n';
    }

    void printDate() const {
        std::cout << day_ << '/' << month_ << '/' << year_ << '\n';
    }

    void addYear(int n) {
        year_ += n;
        total_added_ += n;
    }

    void printTotalAdded() const {
        std::cout << total_added_ << '\n';
    }

private:
    const int day_{};
    const int month_{};
    int year_{};
    int total_added_{};
};

void doSomething(const Date &d) {
    d.printDate();
}

void doSomethingCopied(Date d) {
    d.printDate();
}

Date unitCopy(const Date& d) {
    return d;
}

class IntPair
{
private:
    int m_x{};
    int m_y{};

public:
    IntPair(int x, int y)
        : m_x { x }, m_y { y }
    {}

    [[nodiscard]] int x() const { return m_x; }
    [[nodiscard]] int y() const{ return m_y; }
};

void print(IntPair p)
{
    std::cout << "(" << p.x() << ", " << p.y() << ")\n";
}

template<typename T>
void printEmployeee(Employeee<T>& e) // has an Employee parameter
{
    std::cout << e.getName() << '\n';
}

void func6() {
    Date date{1, 2, 3};
    date.printDate();
    Date::printSomething();

    date.addYear(2);
    date.printDate();

    doSomething(date);
    date.printTotalAdded();

    Date date3 {3};

    print(IntPair { 1,2});
    print({1,2});

    Date date4{date};
    date.printTotalAdded();
    date4.printTotalAdded();

    doSomething(date4);
    doSomethingCopied(date4);
    Date date5 = unitCopy(date4);
    Date date6 = date5;
    Date date7 = Date{Date{4}};

    // doSomethingCopied(1);
    // printEmployeee("hello"sv);
    Employeee<int> e = Employeee(1, "Hello"sv);
    printEmployeee(e);

    std::cout << Employeee<int>::EmployeeeNationality::English << '\n';
    Employeee<std::string_view> e1 = Employeee("huh"sv, "Hello"sv);

    std::cout << e << '\n';

}

