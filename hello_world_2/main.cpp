#include <future>
#include <iostream>
#include <latch>
#include <semaphore>

int main() {
    // std::atomic<int> total{};
    // std::atomic<bool> done{};
    //
    //
    // auto _ = std::jthread([&total, &done]() {
    //     for (int i{0}; i < 1000; ++i) {
    //         total.fetch_add(1, std::memory_order_relaxed);
    //     }
    //
    //     done.store(true, std::memory_order_release);
    // });
    //
    // bool expected{true};
    // while (!done.compare_exchange_weak(expected, false, std::memory_order_acquire, std::memory_order_relaxed)) {
    //     expected = true;
    //     std::this_thread::yield();
    // };
    // std::cout << total.load(std::memory_order_relaxed) << std::endl;

    std::string* s = new std::string{"hello"};

    std::cout << *s << std::endl;
}
