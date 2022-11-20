/**
 * @file IntegerDefinition.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief The C language defines several integer data types: integer, short
 * integer, long integer, and character, all in both signed and unsigned
 * varieties. The GNU C compiler extends the language to contain long long
 * integers as well.
 *
 * The C integer types were intended to allow code to be portable among machines
 * with different inherent data sizes (word sizes), so each type may have
 * different ranges on different machines. The problem with this is that a
 * program often needs to be written for a particular range of integers, and
 * sometimes must be written for a particular size of storage, regardless of
 * what machine the program runs on.
 *
 * Source: <https://www.gnu.org/software/libc/manual/html_node/Integers.html>
 *
 * @version 0.1
 * @date 2022-11-20
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <cstdint>
#include <iostream>

using namespace std;

int main(void)
{
    int number = 100;
    cout << number << endl;

    return EXIT_SUCCESS;
}