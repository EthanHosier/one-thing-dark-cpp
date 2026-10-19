//
// Created by Ethan Hosier on 19/10/2026.
//

#ifndef HELLO_WORLD_EMPLOYEE_H
#define HELLO_WORLD_EMPLOYEE_H
#include <string>

template<typename T>
class Employeee
{
private:
    std::string m_name{};
    T something_;

public:
    enum EmployeeeNationality {
        English,
        Other
    };

    explicit Employeee(const T& something_, std::string_view name);
    ~Employeee();
    const std::string& getName() const;
    void print_name() const;

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Employeee<U>& acc);
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Employeee<T>& acc) {
    return os << acc.m_name << ';' << acc.something_;
};


#endif //HELLO_WORLD_EMPLOYEE_H
