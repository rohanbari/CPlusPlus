/**
 * @file OldSchool.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief Old-school C-style arrays.
 * @version 0.1
 * @date 2022-11-25
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>

using namespace std;

const int SIZE = 5;

int main(void)
{
    int array[SIZE] = { 10, 2, 6, 3, 9 };

    for (int i = 0; i < SIZE; i++)
        cout << array[i] << ' ';
    cout << endl;

    return EXIT_SUCCESS;
}