#include <iostream>

template<typename T>
class ValueWrapper {
    bool contains_value{};
    T value;
};

template<typename T>
struct ChannelState {
    int writer_index_{};
    int reader_index_{};
};

template <int Size, typename T>
class Channel {
public:
    Channel() {
        static_assert(std::atomic<ChannelState<T>>::is_always_lock_free);
    }

private:
    constexpr static int AllocSize = Size + 1;
    std::array<std::atomic<ValueWrapper<T>>, AllocSize> array_{};
    std::atomic<ChannelState<T>> state_{};

    constexpr bool is_full_(ChannelState<T>& channel_state) const {
        return (channel_state.reader_index_ - channel_state.writer_index_) % AllocSize == 1;
    }
};


int main() {
    Channel<5, int> channel;
}
