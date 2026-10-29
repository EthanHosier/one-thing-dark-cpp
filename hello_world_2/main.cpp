#include <assert.h>
#include <iostream>
#include <sstream>

template <typename T>
std::string str(const T& vec) {
    std::ostringstream os{};
    os << '[';

    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i < vec.size() - 1) {
            os << ',';
        }
    }
    os << ']';
    return os.str();
}

inline constexpr char StdVec[] = "StdVec";
inline constexpr char MyVec[] = "MyVec";

template <typename T, auto& Name>
class Container {
public:
    Container(T val) : val_{val} {}
    // ~Container() {
    //     std::cout << Name << ": Destroying " << val_ << std::endl;
    // }

    friend std::ostream& operator<<(std::ostream& os, const Container& c) {
        return os << c.val_;
    }

private:
    T val_;
};

template <typename T>
class Vector {
public:
    Vector(std::initializer_list<T> init_list) : size_{init_list.size()}, arr_{new std::optional<T>[init_list.size()]} {
        std::copy(init_list.begin(), init_list.end(), arr_.get());
    }

    T& operator[](size_t i) const{
        return arr_[i].value();
    }

    void pop_back() {
        --size_;
        arr_[size_].reset();
    }

    size_t size() const noexcept {
        return size_;
    }

private:
    std::unique_ptr<std::optional<T>[]> arr_;
    size_t size_;
};


int main() {
    std::vector<Container<int, StdVec>> stdVec {1,2,3} ;
    Vector<Container<int, MyVec>> myVec {1,2,3};

    auto assertSame{[&stdVec, &myVec] {
        assert(str(myVec) == str(stdVec));
        std::cout << "MyVec:   " << str(myVec) << std::endl;
        std::cout << "stdVec:  " << str(stdVec) << std::endl;
    }};

    assertSame();

    stdVec.pop_back();
    myVec.pop_back();
    assertSame();

    return 0;
}
