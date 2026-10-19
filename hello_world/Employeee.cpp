//
// Created by Ethan Hosier on 19/10/2026.
//

#include "Employeee.h"

#include <iostream>

/*
 * THESE SHOULD BE MOVED INTO EMPLOYEEE.H file hbut oh whell
 */

template<typename T>
Employeee<T>::Employeee(const T& something, std::string_view name) : something_(something), m_name{ name }
{}

template<typename T>
Employeee<T>::~Employeee() {
    std::cout << "Employeee destroyed: " << something_ << '\n';
}

template<typename T>
const std::string& Employeee<T>::getName() const {
    return m_name;
}

template<typename T>
void Employeee<T>::print_name() const {
    std::cout << m_name << '\n';
}

template class Employeee<int>;
template class Employeee<std::string_view>;