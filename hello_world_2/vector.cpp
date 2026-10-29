//
// Created by Ethan Hosier on 29/10/2026.
//

#include "vector.h"

/*
 A little buggy, some of these i fixed, some I didn't
 ```
Yes. The iterator works for your current range-based loop, but there are a few semantic issues.

- A const vector lets you modify its elements. Your operator[] const returns T&, and the iterator stores a const Vector& but also returns T&. Consequently, this is allowed:

  const Vector<int> vec{1, 2, 3};
for (auto& x : vec) {
    x = 99;
}

  For behavior like std::vector, mutable access should return T&, while access through a const vector should return const T&.
- Iterator comparison only checks the index. Iterators from different vectors with the same index compare as equal. Comparing the vector’s address too would distinguish them. Also, take const VectorIterator& other so comparison accepts const iterators and temporaries.
- It supports range-based for, but isn’t yet a general standard-library iterator. It lacks things such as postfix ++, ==, and iterator type information needed by various algorithms.

Elsewhere in Vector, the main issues are:

- Growing from zero capacity fails. size_ * 2 remains zero, so pushing into an initially empty vector writes outside the allocation.
- Pushing into a moved-from vector fails. move() clears other.size_ but leaves its capacity nonzero while its array is null. The next push skips allocation and accesses that null array.
- push_back(vec[0]) can use a dangling reference when growth occurs. Reallocation destroys the old array before you copy from t, which refers into that array.
- emplace_back doesn’t correctly forward a constructor’s argument pack. Forward each argument using its corresponding Args type, and construct inside the existing optional:

  arr_[size_].emplace(std::forward<Args>(args)...);

  That also avoids placement-new replacing an already-existing optional.
- Copy assignment can leave inconsistent state if allocation or copying throws, because copy() changes size and capacity before successfully finishing.


 ```



 */

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

    Vector(const Vector& other) {
        copy(other);
    };

    Vector& operator=(const Vector& other) {
        if (&other != this) {
            copy(other);
        }
        return *this;
    }

    Vector(Vector&& other) {
        move(other);
    }

    Vector& operator=(Vector&& other) {
        if (&other != this) {
            move(other);
        }
        return *this;
    }


    const T& operator[](size_t i) const{
        return arr_[i].value();
    }

    T& operator[](size_t i) {
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
        new (arr_.get() + size_) std::optional {std::forward<Args>(args)...};
        ++size_;
    }

    size_t size() const noexcept {
        return size_;
    }

    size_t capacity() const noexcept {
        return capacity_;
    }

    class VectorIterator {
    public:
        VectorIterator(const Vector& vec, size_t index) : vector_{vec}, index_{index} {}

        VectorIterator& operator++() {
            index_ += 1;
            return *this;
        }

        bool operator!=(const VectorIterator& other) const {
            return other.index_ != index_ && &vector_ == &other.vector_;
        }

        const T& operator*() const {
            return vector_[index_];
        }

    private:
        size_t index_;
        const Vector& vector_;
    };

    // std::optional<T>* begin() const noexcept {
    //     return arr_.get();
    // }
    //
    // std::optional<T>* end() const noexcept {
    //     return arr_.get() + size_;
    // }

    VectorIterator begin() const noexcept {
        return VectorIterator{*this, 0};
    }

    VectorIterator end() const noexcept {
        if (arr_ == nullptr) {
            return begin();
        }

        return VectorIterator(*this, size_);
    }

private:
    std::unique_ptr<std::optional<T>[]> arr_;
    size_t size_;
    size_t capacity_;

    void maybe_grow() {
        if (size_ == capacity_) {
            capacity_= size_ == 0 ? 1 : size_ * 2;
            std::unique_ptr new_arr{std::make_unique<std::optional<T>[]>(capacity_)};
            std::copy(arr_.get(), arr_.get() + size_, new_arr.get());
            arr_ = std::move(new_arr);
        }
    }

    void copy(const Vector &other) {
        size_ = other.size_;
        capacity_ = other.capacity_;
        arr_ = std::make_unique<std::optional<T>[]>(other.capacity_);
        if (other.arr_.get() != nullptr) {
            std::copy(other.arr_.get(), other.arr_.get() + size_, arr_.get());
        }
    }

    void move(Vector &other) {
        size_ = other.size_;
        capacity_ = other.capacity_;
        arr_ = std::move(other.arr_);
        other.size_ = 0;
    }

};