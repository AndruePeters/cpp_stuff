//
// Created by petersd on 4/30/25.
//
// STL includes
#include <string>
#include <string_view>

#include <catch2/catch_test_macros.hpp>

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
bool isStringLike(const T& t) {
    return true;
}

template <typename T> requires (!dp::StringLike<T>)
bool isStringLike(const T& t) {
    return false;
}

TEST_CASE( "Items are StringLike") {
    const char* constCharStar = "This is a const char*";
    constexpr char constCharArr [4] = {'A', 'B', 'C', '\0'};
    char CharArr [4] = {'A', 'B', 'C', '\0'};
    std::string string = "This is a std::string";
    const std::string constString = "This is a const std::string";
    std::string_view stringView = "This is a std::string_view";
    constexpr std::string_view constStringView = "This is a const std::string_view";

    REQUIRE (isStringLike(constCharStar));
    REQUIRE (isStringLike(constCharArr));
    REQUIRE (isStringLike(CharArr));
    REQUIRE (isStringLike(string));
    REQUIRE (isStringLike(constString));
    REQUIRE (isStringLike(stringView));
    REQUIRE (isStringLike(constStringView));

    REQUIRE_FALSE(isStringLike(5));
    REQUIRE_FALSE(isStringLike(5.0f));
    REQUIRE_FALSE(isStringLike(5.0));
}