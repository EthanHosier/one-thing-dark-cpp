#include <iostream>
#include <latch>
#include <thread>
#include <utility>

template<typename T>
class UniquePtr {
public:
    UniquePtr() noexcept : ptr(nullptr) {
    }

    explicit UniquePtr(T *ptr) noexcept : ptr(ptr) {
    }

    ~UniquePtr() { delete ptr; }

    UniquePtr(const UniquePtr &) = delete;

    UniquePtr& operator=(const UniquePtr &) = delete;

    UniquePtr(UniquePtr &&other) noexcept : ptr{other.ptr} {
        other.ptr = nullptr;
    }

    UniquePtr& operator=(UniquePtr&& other)  noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }

        return *this;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    T* get() const {
        return ptr;
    }

    explicit operator bool() const {
        return ptr;
    }

    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

private:
    T *ptr;
};

int main() {
    UniquePtr u {new int};
    *u = 4;
    std::cout << *u << std::endl;
    std::cout << static_cast<bool>(u) << std::endl;
    std::latch latch{1};

    std::jthread j{[uu = std::move(u), &latch] {
        std::cout << *uu << std::endl;
        std::cout << static_cast<bool>(uu) << std::endl;
        latch.count_down();
    }};

    latch.wait();
    std::cout << static_cast<bool>(u) << std::endl;
}
