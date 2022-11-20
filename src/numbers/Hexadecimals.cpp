/**
 * @file Hexadecimals.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief C++ allows the use of hexadecimal values (base 16) in code, and
 * programmers routinely use hex values when writing out binary representation
 * of numbers.
 *
 * @version 0.1
 * @date 2022-11-20
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <array>
#include <cinttypes>
#include <iostream>

using namespace std;

int main(void)
{
    array<uint32_t, 3> hexCode { 0x89, 0x00000001, 0xFFFFFFFF };

    for (const auto& it : hexCode) {
        cout << dec << "Decimal: " << it << endl;
        cout << hex << "Hex: " << it << endl;
        cout << showbase << "Hex with base: " << it << endl
             << endl;
    }

    return EXIT_SUCCESS;
}