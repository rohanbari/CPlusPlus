/**
 * @file ConstExprCtor.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief Using constant expressions in class constructor.
 * @version 0.1
 * @date 2022-11-18
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <array>
#include <iostream>

using namespace std;

/**
 * @brief constexpr application in class c'tor.
 *
 */
class MyClass {
    uint32_t member;

public:
    constexpr MyClass(const uint32_t& rhs)
        : member(rhs)
    {
    }
    constexpr uint32_t getValue() const
    {
        return member;
    }
};

int main(void)
{
    // Compile-time expression evaluation.
    constexpr uint32_t ARRAY_SIZE { MyClass { 10 }.getValue() };
    array<int, ARRAY_SIZE> myArray;

    cout << myArray.size() << endl;

    return EXIT_SUCCESS;
}