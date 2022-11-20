/**
 * @file SpecificIntegers.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief The types supplied by cinttypes contain the number of bits that they
 * represent. They are often useful to be specific about the size of data
 * necessary to be stored.
 *
 * @version 0.1
 * @date 2022-11-20
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <cinttypes>
#include <iostream>
#include <limits>

using namespace std;

int main(void)
{
    // These variables are system-specific and might be different for different
    // systems as per the compatibilities.
    int8_t signedChar = numeric_limits<int8_t>::max();
    int16_t shortInteger = numeric_limits<int16_t>::max();
    int32_t normalInteger = numeric_limits<int32_t>::max();
    int64_t longlongInteger = numeric_limits<int64_t>::max();

    cout << "Signed types:" << endl;
    cout << "signed char: " << static_cast<int16_t>(signedChar) << endl
         << "signed short: " << shortInteger << endl
         << "signed int: " << normalInteger << endl
         << "signed long long: " << longlongInteger << endl
         << endl;

    cout << "Unsigned types:" << endl;
    uint8_t unsignedChar = numeric_limits<uint8_t>::max();
    uint16_t unsignedShort = numeric_limits<uint16_t>::max();
    uint32_t unsignedInteger = numeric_limits<uint32_t>::max();
    uint64_t unsignedLongLongInteger = numeric_limits<uint64_t>::max();

    cout << "unsigned char: " << static_cast<uint16_t>(unsignedChar) << endl
         << "unsigned short: " << unsignedShort << endl
         << "unsigned int: " << unsignedInteger << endl
         << "unsigned long long: " << unsignedLongLongInteger << endl;

    return EXIT_SUCCESS;
}