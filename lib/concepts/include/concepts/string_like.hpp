#pragma once

#include <concepts>
#include <ranges>
#include <string_view>
#include <type_traits>

namespace dp {

    // Concept to represent anything that is StringLike -- meaning it can convert to a std::string_view
    template <typename T>
    concept StringLike = std::convertible_to<T, std::string_view>;

    // Checks if Range is a range AND its elements satisfy StringViewConvertible
    template <typename Range>
    concept RangeOfStringViewConvertible =
            std::ranges::range<Range> && // First, R must model the range concept
            StringLike<std::ranges::range_value_t<Range>>; // Second, the *value type* of the range's elements
}

