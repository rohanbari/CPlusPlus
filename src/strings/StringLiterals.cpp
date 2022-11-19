/**
 * @file StringLiterals.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief C++ has a concept known as a string table. It is created when using
 * string literals in code.
 * @version 0.1
 * @date 2022-11-19
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    // The literal is defined as:
    // inline std::string std::literals::string_literals::operator _
    //   ""s(const char *__str, std::size_t __len)
    const string myString { "Hello, world!"s };
    cout << myString << endl;

    return EXIT_SUCCESS;
}