#include <iostream>
#include "type_id.hpp"

int main() {
    static_assert(toy::type_id<int> == 0);
    static_assert(toy::type_id<double> == 1);
    static_assert(toy::type_id<float> == 2);
    static_assert(toy::type_id<short> == 3);
    static_assert(toy::type_id<int> == 0);
    static_assert(toy::type_id<double> == 1);
    static_assert(toy::type_id<float> == 2);
    static_assert(toy::type_id<short> == 3);
}