/**
 * @file NarrowConversion.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief Uniform initialization helps prevent narrow conversions.
 * @version 0.1
 * @date 2022-11-17
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>

using namespace std;

int main(void)
{
    // Uncomment to view actions
    // char veryBigChar { 512 }; // Will warn about
    // double veryBigNumber { 1.0 }; // Might not warn about

    // cout << veryBigChar << endl
    //      << veryBigNumber << endl;

    char superNumber { static_cast<char>(512) };

    double number { 1.0 };
    float unlostPrecision { static_cast<float>(number) };

    cout << superNumber << endl
         << unlostPrecision << endl;

    return EXIT_SUCCESS;
}