/**
 * @file Variations.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief Not in all cases we require large data-type like an integer. That is,
 * sometimes, we need to store data like a character, a small number, or even
 * a boolean choice. So, it is convenient to use data-types of suitable
 * requirement. It can save the memory at runtime to increase efficiency.
 *
 * @version 0.1
 * @date 2022-11-20
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>

using namespace std;

int main(void)
{
    char smallInput = 'Y';

    short int smallNumber = 64;
    int number = 4234234;
    long int bigNumber = 1234567890;
    long long int biggerNumber = 93240293490238490;

    cout << smallInput << endl
         << smallNumber << endl
         << number << endl
         << bigNumber << endl
         << biggerNumber << endl;

    return EXIT_SUCCESS;
}