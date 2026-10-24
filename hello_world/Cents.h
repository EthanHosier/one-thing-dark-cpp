//
// Created by Ethan Hosier on 23/10/2026.
//

#ifndef HELLO_WORLD_CENTS_H
#define HELLO_WORLD_CENTS_H
#include <iosfwd>
#include <compare>
#include <iostream>


class Cents
{
private:
    int m_cents {};

public:
    Cents(int cents) : m_cents{ cents } { }

    friend Cents operator+(const Cents&c1, const Cents& c2);
    friend Cents operator+(const Cents& c1, int value);
    friend Cents operator+(int value, const Cents& c1);
    friend std::ostream& operator<< (std::ostream& out, const Cents& c);

    Cents operator*(int c) const {
        return m_cents * c;
    }

    Cents operator +=(int c) {
        m_cents += c;
        return *this;
    }

    Cents operator-() const {
        return -m_cents;
    }

    auto operator <=>(const Cents& other) const {
        return m_cents <=> other.m_cents;
    }

    int& operator[] (int& index) const {
        return index;
    }

    int getCents() const { return m_cents; }
};

inline Cents operator+ (const Cents& c1, const Cents& c2) {
    return c1.m_cents + c2.m_cents;
}

inline Cents operator+(const Cents& c1, int value)
{
    return Cents { c1.m_cents + value };
}

inline Cents operator+(int value, const Cents& c1)
{
    return Cents { c1.m_cents + value };
}

inline std::ostream& operator<<(std::ostream& out, const Cents& c) {
    out << c.m_cents << 'c';
    return out;
}


// note: this function is not a member function nor a friend function!
inline Cents operator-(const Cents& c1, const Cents& c2)
{
    // use the Cents constructor and operator+(int, int)
    // we don't need direct access to private members here
    return Cents{ c1.getCents()- c2.getCents() };
}

#endif //HELLO_WORLD_CENTS_H
