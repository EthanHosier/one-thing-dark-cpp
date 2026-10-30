#include <iostream>
#include <__thread/jthread.h>

template<typename T>
struct ValueWrapper {
    bool contains_value{};
    T value{};
};

struct ChannelState {
    int writer_index_{};
    int reader_index_{};
};

template<int Size, typename T>
class Channel {
public:
    Channel() {
        static_assert(std::atomic<ChannelState>::is_always_lock_free);
        static_assert(std::atomic<ValueWrapper<T> >::is_always_lock_free);
    }

    bool maybe_enqueue(T &&val) {
        for (;;) {
            ChannelState current_channel_state = state_.load();
            if (is_full_(current_channel_state)) {
                return false;
            }

            ValueWrapper current_value = arr_[current_channel_state.writer_index_].load();
            if (current_value.contains_value) {
                return false;
            }

            ValueWrapper desired_value{ValueWrapper{true, std::move(val)}};
            if (!arr_[current_channel_state.writer_index_].compare_exchange_weak(current_value, desired_value)) {
                continue;
            }

            for (;;) {
                ChannelState desired_channel_state = {
                    .writer_index_ = inc_index(current_channel_state.writer_index_),
                    .reader_index_ = current_channel_state.reader_index_
                };

                if (state_.compare_exchange_weak(current_channel_state, desired_channel_state)) {
                    return true;
                }
            }
        }
    }

    std::optional<T> maybe_dequeue() {
        for (;;) {
            ChannelState current_channel_state = state_.load();
            if (is_empty_(current_channel_state)) {
                return {};
            }

            ValueWrapper current_value = arr_[current_channel_state.reader_index_].load();
            if (!current_value.contains_value) {
                return {};
            }

            ValueWrapper desired_value{ValueWrapper{false, T{}}};
            if (!arr_[current_channel_state.reader_index_].compare_exchange_weak(current_value, desired_value)) {
                continue;
            }

            for (;;) {
                ChannelState desired_channel_state = {
                    .writer_index_ = current_channel_state.writer_index_,
                    .reader_index_ = inc_index(current_channel_state.reader_index_)
                };

                if (state_.compare_exchange_weak(current_channel_state, desired_channel_state)) {
                    return {current_value.value};
                }
            }
        }
    }

private:
    constexpr static int AllocSize = Size + 1;
    std::array<std::atomic<ValueWrapper<T>>, AllocSize> arr_{};
    std::atomic<ChannelState> state_{};

    constexpr bool is_full_(ChannelState &channel_state) const {
        return Size == 0 || ((channel_state.reader_index_ - channel_state.writer_index_ + AllocSize) % AllocSize == 1);
    }

    constexpr bool is_empty_(ChannelState &channel_state) const {
        return Size == 0 || channel_state.writer_index_ == channel_state.reader_index_;
    }

    constexpr int inc_index(const int i) const {
        return (i + 1) % AllocSize;
    }
};


int main() {
    constexpr int num_threads = 5;
    constexpr int iter_size{2000 / num_threads};

    Channel<100, int> channel;

    std::vector<std::jthread> threads;
    threads.reserve(num_threads * 2);

    for (int j = 0; j < num_threads; j ++) {
        threads.emplace_back(
            [&channel, j] {
                for (int i = 0; i < iter_size; i++) {
                    for (;!channel.maybe_enqueue(std::move(i));) {};
                    std::cout << "Thread " << j << ": Enqueued " << i << std::endl;
                }
            }
        );
    }

    for (int j = 0; j < num_threads; j ++) {
        threads.emplace_back(
        [&channel, j] {
            for (int i = 0; i < iter_size; i++) {
                std::optional<int> x;
                for (;!x.has_value(); x = channel.maybe_dequeue()) {}
                std::cout << "Thread " << j << ": Consumed " << x.value() << std::endl;
            }
        }
    );
    }

   for (auto& t: threads) {
       t.join();
   };
}
