//
// Created by petersd on 4/30/25.
//
// STL includes
#include <string>
#include <string_view>

// Test our StringLike Concepts
#include <concepts/string_like.hpp>


// There are several things that should satisfy StringLike...
// I'm also not interested in specifically supporting wide-char sets or UTF at the moment
// These things are:
//      1. const char *
//      2. char [N]
//      3. std::string_view
//      4. std::string
//      Should a span of char be stringlike?
template <typename T> requires dp::StringLike<T>
void isStringLike(const T& t) {
    static_assert(true, "isStringLikeTrue");
}

template <typename T> requires (!dp::StringLike<T>)
void isNotStringLike(const T& t) {
    static_assert(true, "isNotStringLikeTrue");
}

int main()
{
    const char* constCharStar = "This is a const char*";
    constexpr char constCharArr [4] = {'A', 'B', 'C', '\0'};
    char CharArr [4] = {'A', 'B', 'C', '\0'};
    std::string string = "This is a std::string";
    const std::string constString = "This is a const std::string";
    std::string_view stringView = "This is a std::string_view";
    constexpr std::string_view constStringView = "This is a const std::string_view";

    isStringLike(constCharStar);
    isStringLike(constCharArr);
    isStringLike(CharArr);
    isStringLike(string);
    isStringLike(constString);
    isStringLike(stringView);
    isStringLike(constStringView);

    isNotStringLike(5);
    isNotStringLike(5.0f);
    isNotStringLike(5.0);
}