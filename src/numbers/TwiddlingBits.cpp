/**
 * @file TwiddlingBits.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief We can develop applications where data can be packed into a format as
 * small as possible. We can use bitwise operators to set and test individual
 * bits on a variable.
 *
 * @version 0.1
 * @date 2022-11-21
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <cinttypes>
#include <iostream>

using namespace std;

/**
 * @brief Method illustrating the usage of &.
 *
 */
void bitAnd(void)
{
    uint32_t myBit { 0x00011000 };

    cout << myBit << " & " << myBit << ": " << (myBit & myBit)
         << endl
         << myBit << " & ~" << myBit << ": " << (myBit & ~myBit)
         << endl
         << endl;
}

/**
 * @brief Method illustrating the usage of |.
 *
 */
void bitOr(void)
{
    uint32_t left { 0x00011000 };
    uint32_t right { 0x00010100 };

    cout << left << " | " << right << ": " << (left | right)
         << endl
         << left << " | ~" << left << ": " << (left | ~left)
         << endl
         << endl;
}

/**
 * @brief Method illustrating the usage of ^.
 *
 */
void bitXor(void)
{
    uint32_t left { 0x00011000 };
    uint32_t right { 0x00010100 };

    cout << left << " ^ " << right << ": " << (left ^ right)
         << endl
         << left << " ^ ~" << left << ": " << (left ^ ~left)
         << endl
         << endl;
}

/**
 * @brief Method illustrating the usage of bit << and >>.
 *
 */
void bitShift(void)
{
    const int32_t bitMask { 16 };

    uint32_t leftShifted { 0x00000011 << bitMask };
    cout << "0x00000011 << 16: " << leftShifted << endl;

    uint32_t rightShift { leftShifted >> bitMask };
    cout << leftShifted << " >> 16: " << rightShift << endl;
}

/**
 * @brief Method describing how the bits are narrowed.
 * @warning Compilation will fail when called.
 *
 */
void narrowBit(void)
{
    const uint32_t bitMask { 16 };
    // This line will cause the compilation to abort.
    uint32_t narrowingBits { 0x00008000 << bitMask };

    cout << narrowingBits << endl;
}

int main(void)
{
    // Setting manipulator mode to show the base along side the hex.
    cout << showbase << hex;

    bitAnd();
    bitOr();
    bitXor();
    bitShift();

    return EXIT_SUCCESS;
}