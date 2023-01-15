/**
 * @file Concepts.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief Concepts are something that I don't understand in C++20 yet. This
 * program has only purpose to use the newly-welcomed 'Concepts' feature.
 *
 * The predicate Hashable is evaluated at compile-time to identify whether a
 * given function/class template is hashable or not.
 *
 * @version 0.1
 * @date 16-12-2022
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <concepts>
#include <iostream>

using namespace std;

template <typename T>
concept Hashable = requires(T param) {
    { hash<T> {}(param) } -> convertible_to<size_t>;
};

template <Hashable T>
void canHash(T data)
{
    cout << data << '\n';
}

int main()
{
    struct foo { };

    canHash("Hello, world!"s); // Hashable
    // canHash(foo{}); // Not hashable as it is not convertible to size_t.

    return EXIT_SUCCESS;
}