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
    Vector(std::initializer_list<T> init_list) : size_{init_list.size()}, capacity_{init_list.size()}, arr_{new std::optional<T>[init_list.size()]} {
        std::copy(init_list.begin(), init_list.end(), arr_.get());
    }

    Vector(const Vector& other) : size_{other.size_}, capacity_{other.capacity_}, arr_{std::make_unique<std::optional<T>[]>(other.capacity_)} {
        if (other.arr_.get() != nullptr) {
            std::copy(other.arr_.get(), other.arr_.get() + size_, arr_.get());
        }
    };

    Vector(Vector&& other) : size_{other.size_}, capacity_{other.capacity_}, arr_{std::move(other.arr_)} {
        other.size_ = 0;
    }

    T& operator[](size_t i) const{
        return arr_[i].value();
    }

    void pop_back() {
        --size_;
        arr_[size_].reset();
    }

    void push_back(const T& t) {
        maybe_grow();
        arr_[size_] = t;
        ++size_;
    }

    template <typename... Args>
    void emplace_back(Args&& ... args) {
        maybe_grow();
        new (arr_.get() + size_) std::optional {std::forward<T>(args...)};
        ++size_;
    }

    size_t size() const noexcept {
        return size_;
    }

    size_t capacity() const noexcept {
        return capacity_;
    }

private:
    std::unique_ptr<std::optional<T>[]> arr_;
    size_t size_;
    size_t capacity_;

    void maybe_grow() {
        if (size_ == capacity_) {
            std::unique_ptr new_arr{std::make_unique<std::optional<T>[]>(size_ * 2)};
            std::copy(arr_.get(), arr_.get() + size_, new_arr.get());
            arr_ = std::move(new_arr);
            capacity_ *= 2;
        }
    }
};

template <typename T, typename U>
void assertSame(T& stdVec, U& myVec) {
    std::cout << "MyVec:   " << str(myVec) << std::endl;
    std::cout << "stdVec:  " << str(stdVec) << std::endl;
    assert(str(myVec) == str(stdVec));
    std::cout << '\n' << std::endl;
};

int main() {
    std::vector<Container<int, StdVec>> stdVec {1,2,3} ;
    Vector<Container<int, MyVec>> myVec {1,2,3};

    {
        auto assertSame{[&stdVec, &myVec] {
            std::cout << "MyVec:   " << str(myVec) << std::endl;
            std::cout << "stdVec:  " << str(stdVec) << std::endl;
            assert(str(myVec) == str(stdVec));
            std::cout << '\n' << std::endl;
        }};

        assertSame();

        stdVec.pop_back();
        myVec.pop_back();
        assertSame();

        stdVec.push_back(4);
        myVec.push_back(4);
        assertSame();

        stdVec[2] = 64;
        myVec[2] = 64;
        assertSame();

        stdVec.emplace_back(6);
        myVec.emplace_back(6);
        assertSame();
        assert(stdVec.size() == myVec.size());
    }


    std::vector stdVec2 = stdVec;
    Vector myVec2 = myVec;

    assertSame(stdVec, myVec);
    assertSame(stdVec2, myVec2);

    std::vector stdVec3 = std::move(stdVec2);
    Vector myVec3 = std::move(myVec2);
    assertSame(stdVec3, myVec3);

    assert(stdVec3.size() == myVec3.size());
    assert(stdVec2.size() == myVec2.size());
    std::cout << stdVec2.size() << std::endl;

    return 0;
}
