#include <iostream>

#define PASS
#define NDEBUG

#include <cassert>
#include <iomanip>
#include <string_view>

#include "Cents.h"
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

int main(int argc, char *argv[]) {
    std::cout << argc << '\n';
    std::cout << argv[argc - 1] << '\n';
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

//
// enum class Animal {
//     Dog,
//     Cat
// };

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

void func7();

void func5() {
    Color apple{Red};
    Color shirt{Green};
    Color cup{Blue};

    std::cout << apple << '\n';
    std::cout << shirt << '\n';

    // Animal dog{Animal::Dog};
    // Animal cat{Animal::Cat};
    //
    // using enum Animal;
    // Animal dog2{Dog};

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
    func7();
}

class Date {
public:
    explicit Date(const int d) : Date(d, 1, 1) {
        std::cout << "Other constructor" << '\n';
    }

    Date(const int d, const int m, const int y) : day_{d}, month_{m}, year_{y} {
        std::cout << "Constructed (" << day_ << '/' << month_ << '/' << year_ << ')' << '\n';
    };

    Date(const Date &date) : day_{date.day_}, month_{date.month_}, year_{date.year_} {
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

Date unitCopy(const Date &d) {
    return d;
}

class IntPair {
private:
    int m_x{};
    int m_y{};

public:
    IntPair(int x, int y)
        : m_x{x}, m_y{y} {
    }

    [[nodiscard]] int x() const { return m_x; }
    [[nodiscard]] int y() const { return m_y; }
};

void print(IntPair p) {
    std::cout << "(" << p.x() << ", " << p.y() << ")\n";
}

template<typename T>
void printEmployeee(Employeee<T> &e) // has an Employee parameter
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

    Date date3{3};

    print(IntPair{1, 2});
    print({1, 2});

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
    std::cout << e.getName() << '\n';
    std::cout << Employeee{e}.getName() << '\n';
}

void printByRef(const auto &vec) {
    std::cout << vec[0] << '\n';
}

void func8();

void func7() {
    const std::vector primes{2, 3, 5, 7};
    std::cout << primes[0] << '\n';
    std::cout << &primes[0] << '\n';
    std::cout << &primes[1] << '\n';

    std::cout << primes.size() << '\n';
    std::vector a_vec(1, 2);
    std::vector<int> another_vec(34);

    std::cout << a_vec.size() << '\n';
    std::cout << another_vec.size() << '\n';

    printByRef(a_vec);

    std::string s1{"Hello"};
    std::cout << s1.size() << '\n';
    std::string s2{std::move(s1)};
    std::cout << s1.size() << '\n';


    for (size_t i{0}; i < s2.size(); ++i) {
        std::cout << s2[i] << '\n';
    }

    for (const char &c: s2) {
        std::cout << c << '\n';
    }

    s2.resize(3);
    std::cout << s2[4] << '\n';

    std::array<int, 7> arr{};
    arr[0] = 32;
    std::cout << arr[0] << '\n';

    constexpr int len = 8 + 1;
    constexpr std::array<int, len> arr2{1, 2};

    constexpr std::array a3{1, 2, 3};

    int x{1};
    int y{2};
    int z{3};

    std::array<std::reference_wrapper<int>, 3> arrr{x, y, z};
    arrr[1].get() = -3;
    arrr[0] = z;

    std::cout << y << '\n';
    std::cout << arrr[0] << '\n';
    arrr[0].get() = -44;
    std::cout << arrr[2] << '\n';


    func8();
}


std::string testFunc() {
    return std::string{"hello"};
}


struct Student {
    int id{};
    std::string_view name{};
};

enum StudentNames {
    kenny, // 0
    kyle, // 1
    stan, // 2
    butters, // 3
    cartman, // 4
    max_students // 5
};

void func9();

void func8() {
    // const char* ptr{ "Alex" };
    // std::cout << ptr << '\n';                           // print ptr as C-style string
    // std::cout << static_cast<const void*>(ptr) << '\n'; // print address held by ptr

    std::array arr{0, 1, 2, 3, 4, 5, 6};
    int *begin{&arr[0]};
    int *end{begin + std::size(arr)};
    // int * e{arr.data() + std::size(arr)};

    for (const int *ptr{begin}; ptr < end; ++ptr) {
        std::cout << *ptr << '\n';
    }

    for (int *p{arr.begin()}; p != arr.end(); ++p) {
        std::cout << *p << '\n';
    }

    for (int &i: arr) {
        std::cout << i << '\n';
    }

    std::cout << std::find(arr.begin(), arr.end(), 3) << '\n';

    auto funcc = [](int a) {
        std::cout << a << '\n';
    };

    funcc(111);


    new int;
    int *ptr{new(std::nothrow) int{6}};
    std::cout << *ptr << '\n';
    std::cout << ptr << '\n';
    *ptr = 1;
    std::cout << ptr << '\n';
    std::cout << *ptr << '\n';

    delete ptr;
    ptr = nullptr;

    int *array{new int[4]};
    array[3] = 32;
    std::cout << array[3] << '\n';
    delete[] array;

    Employeee<int> *e{new Employeee{1, "name"}};
    delete e;
    std::cout << '\n';

    func9();
}

int foo(int x = 5) // code starts at memory address 0x002717f0
{
    return x;
}

void print_all(int count, ...) {
    std::va_list list;
    va_start(list, count);

    for (int arg{0}; arg < count; ++arg) {
        std::cout << va_arg(list, int) << '\n';
    }

    va_end(list);
}

void doSomethingToNumbers(const auto &fn) {
    fn(1, 2, 3);
}

void func10();

void func9() {
    std::cout << foo() << '\n';
    std::cout << reinterpret_cast<void *>(foo) << '\n';

    int (*funcPtr)(int){foo};
    std::cout << funcPtr(2) << '\n';

    print_all(4, 42, 3, 4, 5);

    constexpr std::array<std::string_view, 4> arr{"apple", "banana", "walnut", "lemon"};

    const auto containsNut = [](std::string_view str) {
        return str.find("nut") != std::string_view::npos;
    };

    const std::string_view *found{
        std::find_if(arr.begin(), arr.end(), containsNut)
    };

    if (found == arr.end()) {
        std::cout << "No nuts" << '\n';
    } else {
        std::cout << "Found " << *found << '\n';
    }

    constexpr double (*addNumbers1)(double, double){
        [](double a, double b) {
            return a + b;
        }
    };

    int x = 34;
    int y = 6;

    auto somethingFn{
        // [funcPtr, &x, y](int i1, int i2, int i3) {
        // [=](int i1, int i2, int i3) {
        [&](int i1, int i2, int i3) {
            std::cout << funcPtr(i1) << ',' << --x << ',' << y << '\n';
            std::cout << i1 << ',' << i2 << ',' << i3 << '\n';
        }
    };

    x = 35;
    y = 8;
    doSomethingToNumbers(somethingFn);

    int ammo{10};
    auto shoot{
        [ammo]() mutable {
            // now mutable
            // We're allowed to modify ammo now
            --ammo;

            std::cout << "Pew! " << ammo << " shot(s) left.\n";
        }
    };

    shoot();
    shoot();

    int ammo2{10};

    auto shoot2{
        // We don't need mutable anymore
        [&ammo2]() {
            // &ammo means ammo is captured by reference
            // Changes to ammo will affect main's ammo
            --ammo2;

            std::cout << "Pew! " << ammo2 << " shot(s) left.\n";
        }
    };

    shoot2();

    std::cout << ammo2 << " shot(s) left\n";

    Cents cents{1};
    std::cout << cents + 332 << '\n';

    std::cout << (cents + 3) * 2 << '\n';
    std::cout << (cents += 4) << '\n';
    std::cout << cents << '\n';
    std::cout << -cents << '\n';

    std::cout << (Cents{1} < Cents{2}) << '\n';
    std::cout << (Cents{1} > Cents{2}) << '\n';
    std::cout << (Cents{1} >= Cents{1}) << '\n';

    int index = 64;
    cents[index] = 12;
    std::cout << cents[index] << '\n';

    func10();
}

void funr(const int &ref) {
    std::cout << ref << '\n';
}

void fun(int &&rref) // r-value arguments will select this function
{
    rref = 1;
    std::cout << rref << '\n';
}


#include <iostream>

template<typename T>
class Auto_ptr5 {
    T *m_ptr{};

public:
    Auto_ptr5(T *ptr = nullptr)
        : m_ptr{ptr} {
    }

    ~Auto_ptr5() {
        delete m_ptr;
    }

    // Copy constructor -- no copying allowed!
    Auto_ptr5(const Auto_ptr5 &a) = delete;

    // Move constructor
    // Transfer ownership of a.m_ptr to m_ptr
    Auto_ptr5(Auto_ptr5 &&a) noexcept
        : m_ptr{a.m_ptr} {
        a.m_ptr = nullptr;
    }

    // Copy assignment -- no copying allowed!
    Auto_ptr5 &operator=(const Auto_ptr5 &a) = delete;

    // Move assignment
    // Transfer ownership of a.m_ptr to m_ptr
    Auto_ptr5 &operator=(Auto_ptr5 &&a) noexcept {
        // Self-assignment detection
        if (&a == this)
            return *this;

        // Release any resource we're holding
        delete m_ptr;

        // Transfer ownership of a.m_ptr to m_ptr
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;

        return *this;
    }

    T &operator*() const { return *m_ptr; }
    T *operator->() const { return m_ptr; }
    bool isNull() const { return m_ptr == nullptr; }
};


class Name {
private:
    std::string m_name{};

public:
    Name(std::string_view name) : m_name{name} {
    }

    Name(const Name &name) = delete;

    Name &operator=(const Name &name) = delete;

    // Create our own swap friend function to swap the members of Name
    void swap(Name &a, Name &b) noexcept {
        // We avoid recursive calls by invoking std::swap on the std::string member,
        // not on Name
        std::swap(a.m_name, b.m_name);
    }

    Name(Name &&name) noexcept {
        std::cout << "Move ctor\n";

        swap(*this, name); // Now calling our swap, not std::swap
    }

    Name &operator=(Name &&name) noexcept {
        std::cout << "Move assign\n";

        swap(*this, name); // Now calling our swap, not std::swap

        return *this;
    }

    friend std::ostream &operator <<(std::ostream &os, Name &n) {
        return os << n.m_name;
    }

    const std::string &get() const { return m_name; }
};

void func11();

void func10() {
    int &&rref{5};
    rref = 10;

    std::cout << rref << '\n';

    // fun(std::move(rref));
    funr(1);

    int *x{new int{4}};
    Auto_ptr5 autoptr{x};

    Name n{"hello"};
    Name n2{"hello2"};

    n = std::move(n2);

    std::cout << n << ',' << n2 << '\n';

    func11();
}

class Resource {
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

void take_ownership(std::unique_ptr<Resource> r) {
    std::cout << "Ownership taken" << '\n';
}

void useResource(Resource const &r) {
    std::cout << "Resource used" << '\n';
}

std::weak_ptr<Resource> getWeakPtr() {
    std::shared_ptr r{std::make_shared<Resource>()};
    return {r};
}

void func12();

void func11() {
    {
        std::unique_ptr res{std::make_unique<Resource>()};
        std::unique_ptr<Resource> res2 = std::move(res);

        useResource(*res2);
        take_ownership(std::move(res2));
        std::cout << "After given ownership" << '\n';

        std::shared_ptr ptr1{std::make_shared<Resource>()};
        {
            std::shared_ptr ptr2{ptr1};
            std::cout << ptr2.use_count() << '\n';
            std::cout << ptr1.use_count() << '\n';
        }

        std::cout << ptr1.use_count() << '\n';
    }

    if (auto r = getWeakPtr().lock()) {
        std::cout << 1 << '\n';
    } else {
        std::cout << 2 << '\n';
    }

    func12();
}

class Person {
protected:
    int m_age{};

public:
    const std::string m_name{};
    const int age() const { return m_age; }

    Person(std::string_view name = "", int age = 0) : m_age(age), m_name(name) {
        std::cout << "Initializing person" << '\n';
    };

    ~Person() {
        std::cout << "Destroying person" << '\n';
    }
};

class BaseballPlayer : public Person {
public:
    int m_homeRuns;

    BaseballPlayer(int home_runs = 0) : m_homeRuns(home_runs), Person("bob", 5) {
        std::cout << "Initializing baseball player" << '\n';

        m_age = 44;
    };

    ~BaseballPlayer() {
        std::cout << "Destroying baseball player" << '\n';
    }
};

class Base {
public:
    int m_public{9999};

    void print(int) { std::cout << "Base::print(int)\n"; }
    void print(double) { std::cout << "Base::print(double)\n"; }
    void print(std::string_view) { std::cout << "Base::print(string_view)\n"; }

protected:
    int m_protected{};

private:
    int m_private{};
};

class Pri : private Base // note: private inheritance
{
private:
    int m_pri_private{4};
    // Private inheritance means:
    // Public inherited members become private (so m_public is treated as private)
    // Protected inherited members become private (so m_protected is treated as private)
    // Private inherited members stay inaccessible (so m_private is inaccessible)
public:
    using Base::print;
    void print(double) { std::cout << "Derived::print(double)"; }

    Pri() {
        m_public = 1; // okay: m_public is now private in Pri
        m_protected = 2; // okay: m_protected is now private in Pri
        // m_private = 3; // not okay: derived classes can't access private members in the base class
    }

    friend void idk(Pri p);
};

class Pub : public Base {
public:
    // void print(std::string_view) = delete;

private:
    using Base::print;
};

void idk(Pri p) {
    p.m_pri_private = 3;
}

void func13();

void func12() {
    {
        BaseballPlayer bp{3};
        std::cout << bp.m_name << ',' << bp.age() << ',' << bp.m_homeRuns << '\n';
        std::cout << sizeof(Person) << '\n';
        std::cout << sizeof(BaseballPlayer) << '\n';
    }

    Base b{};
    Pri p{};
    Pub pub{};
    std::cout << b.m_public << '\n';
    p.print(312);
    // pub.print("hello");
    pub.Base::print("Hello");
    func13();
}

#include <iostream>
#include <string_view>
#include <string>

class Animal {
protected:
    std::string m_name;

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(std::string_view name)
        : m_name{name} {
    }

    // To prevent slicing (covered later)
    Animal(const Animal &) = delete;

    Animal &operator=(const Animal &) = delete;

public:
    std::string_view getName() const { return m_name; }
    std::string_view speak() const { return "???"; }
};

class Cat : public Animal {
public:
    Cat(std::string_view name)
        : Animal{name} {
    }

    std::string_view speak() const { return "Meow"; }
};

class Dog : public Animal {
public:
    Dog(std::string_view name)
        : Animal{name} {
    }

    std::string_view speak() const { return "Woof"; }
};

void func14();

void func13() {
    const Cat cat{"Fred"};
    std::cout << cat.speak() << '\n';

    const Dog dog{"Bob"};
    std::cout << dog.speak() << '\n';

    const Animal *animal{&cat};
    std::cout << animal->speak() << '\n';

    animal = &dog;
    std::cout << animal->speak() << '\n';

    func14();
}

void func15();


void func14() {
    class Base {
    public:
        virtual std::string_view getName() const { return "Base"; }

        void doSomething() {
            idk();
            std::cout << "Base::doSomething()" << '\n';
        }

        virtual std::unique_ptr<Base> makeNew() const {
            return std::make_unique<Base>();
        }

        virtual Base * getThis() {
            std::cout << "called Base::getThis()\n";
            return this;
        }

        virtual ~Base() {std::cout << "Base destructor" <<'\n';}

    private:
        virtual void idk() {
            std::cout << "idk" << '\n';
        }

    };

    class Derived : public Base {
    public:
        std::string_view getName() const override { return "Derived"; }

        void doSomething() {
            std::cout << "Derived::doSomething()" << '\n';
        }

        std::unique_ptr<Base> makeNew() const override {
            return std::make_unique<Derived>();
        }

        Derived* getThis() override {
            std::cout << "called Derived::getThis()\n";
            return this;
        }

        ~Derived() override {std::cout << "Derived destructor" <<'\n';}
    };

    auto takeOwnership{
        [](std::unique_ptr<Base> b) {
            std::cout << "take ownership" << '\n';
        }
    };
    {
        Derived derived{};
        Base &rBase{derived};
        std::cout << "rBase is a " << rBase.getName() << '\n';
        rBase.doSomething();
        derived.doSomething();

        std::unique_ptr u = std::make_unique<Derived>(derived);
        takeOwnership(std::move(u));
        std::cout << "After take ownership" << '\n';
    }
    func15();
}

void func16();

void func15() {
    class ISpeaker {
    public:
        virtual ~ISpeaker() = default;

        virtual void speak() = 0;
    };

    class Person : ISpeaker {
    public:
        void speak() override {
            std::cout << "Hello (as person)" << '\n';
        }

        ~Person() override {
            std::cout << "Person destructor" << '\n';
        }
    };
    {
        Person p{};
        p.speak();
    }
    class A {
    public:
        int val;
        A(int x) : val{x} {}
        virtual ~A() = default;
    };

    class B : virtual public A {
    public:
        int idk;
        B() : idk{3}, A{10} {}
    };

    class Printer : public B {
    public:
        Printer() : A{20}, B{} {}
    };

    class Copier : public Printer {
    public:
        Copier() : A{30}, Printer{} {}
    };

    Copier c;
    std::cout << c.val << '\n';


    A *a{new Printer{}};
    Printer *d {dynamic_cast<Printer *>(a)};
    if (!d) {
        std::cout << "Dynamic cast failed!" << '\n';
        return;
    }

    std::cout << "Dynamic cast succeeded! idk: " << d->idk << '\n';

    func16();
}

// template <typename T, int container_size = 1>
// class Container {
// public:
//     std::array<T, container_size> arr {};
//     T val {};
//     Container(T t) : val{t} {}
//     constexpr size_t size() const {
//         return arr.size();
//     }
// };
//
// template <>
// Container<double>::Container(double) : val{696969} {}

template <typename T, int container_size>
class ContainerBase {
public:
        std::array<T, container_size> arr {};
        T val {};
        ContainerBase(T t) : val{t} {}
        constexpr size_t size() const {
            return arr.size();
        }
    };

template <typename T, int container_size>
class Container: public ContainerBase<T, container_size> {
public:
    Container(T t) : ContainerBase<T, container_size>{t} {}
};


template <typename T,int container_size>
class Container<T*, container_size>: public ContainerBase<T*, 4200> {
public:
    Container(T* t) : ContainerBase<T*, 4200>{t} {}
};

template <int container_size>
class Container<double, container_size>: public ContainerBase<double, container_size> {
public:
    Container(double) : ContainerBase<double, container_size>{696969} {}
};


// template <typename T>
// void doSomething(T t) {
//     std::cout << t << '\n';
// }

template <typename T, int size>
void doSomething(T& t) {
    std::cout << t << '\n';
}

template <int size>
void doSomething(std::string& t) {
    std::cout << t << '?' << size << '\n';
}

// void doSomething(std::string& t) {
//     std::cout << t << '!' << '\n';
// }

// template <int container_size>
// class Container<double, container_size> {
// public:
//     std::array<double, container_size> arr {};
//     double val {};
//     Container(double) : val{696969} {}
//     constexpr size_t size() const {
//         return arr.size();
//     }
// };


void func16() {


    std::cout << Container<int, 1>{1}.val << '\n';
    std::cout << Container<double, 1>{1.2}.val << '\n';
    std::cout << Container<std::string, 1>{"Hello"}.val << '\n';

    std::cout << Container<int, 4>{1}.size() << '\n';
    std::cout << Container<double, 5>{1}.size() << '\n';

    std::string s{"hello"};
    doSomething<3>(s);

    int x{1};
    std::cout << Container<int*, 5>{&x}.size() << '\n';
};
