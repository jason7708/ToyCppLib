#include <cstddef>
#include <type_traits>
// compile time counter

namespace toy {

namespace details {

template<std::size_t N>
struct reader {
    friend auto counted_flag(reader<N>);
};

template<std::size_t N>
struct setter {
    friend auto counted_flag(reader<N>) {}
    static constexpr std::size_t n = N;
};

template<typename T, std::size_t NextVal = 0ul>
[[ nodiscard ]] consteval auto type_id_impl() {
    constexpr bool counted = requires(reader<NextVal> r) {
        counted_flag(r);
    };
    if constexpr(counted) {
        return type_id_impl<T, NextVal+1>();
    }
    else {
        setter<NextVal> s;
        return s.n;
    }
}

} // namespace details

template<typename T, auto Val = details::type_id_impl<std::remove_cvref_t<T>>()>
constexpr auto type_id = Val;

} // namespace toy