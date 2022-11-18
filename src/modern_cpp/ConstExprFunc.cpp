/**
 * @file ConstExprFunc.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief Constant expressions in functions.
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
 * @brief Define the size of the array.
 *
 * @param param Size of the array in bytes
 * @return constexpr uint32_t Size of the array
 */
constexpr uint32_t arraySize(uint32_t param)
{
    return param;
}

int main(void)
{
    constexpr int32_t size { arraySize(16) };
    array<int, size> myArray;

    cout << myArray.size() << endl;

    return EXIT_SUCCESS;
}