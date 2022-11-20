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

    cout << static_cast<int>(signedChar) << endl
         << shortInteger << endl
         << normalInteger << endl
         << longlongInteger << endl;

    return EXIT_SUCCESS;
}