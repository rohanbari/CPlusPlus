/**
 * @file VexingParse.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief The vexing-parse problem in C++.
 * @version 0.1
 * @date 2022-11-17
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>

using namespace std;

/**
 * @brief A simple class.
 *
 */
class MyClass {
    int member;

public:
    MyClass() = default;
    MyClass(const MyClass& rhs) = default;
};

int main(void)
{
    MyClass objectA;
    MyClass objectB(MyClass());

    // In the Vexing-parse problem, the last line above is not interpreted as:
    //   - an object initialized with MyClass constructor
    // Rather, it is interpreted as:
    //   - a function accepting a void pointer to the MyClass and has no params
    //     MyClass objectB(MyClass (*)())
    //
    // WARNING: Clang and Visual Studio compilers will generate a warning.

    // To solve this vexing-parse problem, we use the uniform initialization.
    MyClass objectX;
    MyClass objectY { MyClass {} };

    return EXIT_SUCCESS;
}