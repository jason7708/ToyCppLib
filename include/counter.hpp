#include <cstddef>

// compile time counter

namespace toy {

template<std::size_t N>
struct reader {
    friend auto counted_flag(reader<N>);
};

template<std::size_t N>
struct setter {
    friend auto counted_flag(reader<N>) {}
    static constexpr std::size_t n = N;
};

template<auto Tag, std::size_t NextVal = 0ul>
[[ nodiscard ]] consteval auto counter_impl() {
    constexpr bool counted = requires(reader<NextVal> r) {
        counted_flag(r);
    };
    if constexpr(counted) {
        return counter_impl<Tag, NextVal+1>();
    }
    else {
        setter<NextVal> s;
        return s.n;
    }
}

template<auto Tag = [] {}, auto Val = counter_impl<Tag>()>
constexpr auto counter = Val;

} // namespace toy