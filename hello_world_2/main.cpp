#include <iostream>

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

            ValueWrapper desired_value{ValueWrapper{false, std::move(val)}};
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

private:
    constexpr static int AllocSize = Size + 1;
    std::array<std::atomic<ValueWrapper<T>>, AllocSize> arr_{};
    std::atomic<ChannelState> state_{};

    constexpr bool is_full_(ChannelState &channel_state) const {
        return ((channel_state.reader_index_ - channel_state.writer_index_ + AllocSize) % AllocSize == 1) ;
    }

    constexpr int inc_index(const int i) const {
        return (i + 1) % AllocSize;
    }
};


int main() {
    Channel<5, int> channel;
    std::cout << channel.maybe_enqueue(3) << std::endl;
    std::cout << channel.maybe_enqueue(3) << std::endl;
    std::cout << channel.maybe_enqueue(3) << std::endl;
    std::cout << channel.maybe_enqueue(3) << std::endl;
    std::cout << channel.maybe_enqueue(3) << std::endl;
    std::cout << channel.maybe_enqueue(3) << std::endl;
    std::cout << channel.maybe_enqueue(3) << std::endl;
    std::cout << channel.maybe_enqueue(3) << std::endl;

}
