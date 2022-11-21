/**
 * @file SimpleClass.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief Classes are the language feature that sets C++ apart from the C
 * programming language. The addition of classes to C++ allows it to be used for
 * programs designed using the object-oriented programming (OOP) paradigm.
 *
 * Apart from structs, classes provide extended features that can be utilized.
 *
 * @version 0.1
 * @date 2022-11-21
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>

using namespace std;

/**
 * @brief This is an empty class.
 *
 */
class Vehicle {
};

int main(void)
{
    // This is called instantiation. Here, 'vehicle' object is created.
    // 'Vehicle' is a type now, and 'vehicle' is an object.
    Vehicle vehicle;

    return EXIT_SUCCESS;
}