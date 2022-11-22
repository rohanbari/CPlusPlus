/**
 * @file CopyConstructor.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief You can copy objects in C++ in a number of scenarios. An object is
 * copied when you pass it into the constructor of another object of the same
 * type. An object is also copied when you assign one object to another. Passing
 * an object into a function or method by value also results in a copy operation
 * taking place.
 *
 * C++ provides the copy constructor and assignment operator that you can use to
 * add code to your class that is executed when a copy takes place.
 *
 * @version 0.1
 * @date 2022-11-22
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <cinttypes>
#include <iostream>

using namespace std;

/**
 * @brief A class with explicitly-defined default-behavior c'tor and d'tor. It
 * is considered good practice to define these explicitly.
 *
 */
class Vehicle {
    int32_t wheels {};

public:
    Vehicle() = default;
    Vehicle(const int32_t& rhs)
        : wheels(rhs)
    {
    }

    Vehicle(const Vehicle& rhs) = default;
    Vehicle& operator=(const Vehicle& rhs) = default;

    // NOTE: TO DISALLOW COPY AND ASSIGNMENT, UNCOMMENT THE CODE BELOW.
    //       THE PROGRAM WILL FAIL TO COMPILE AS THEY WILL BE DELETED.
    //
    // Vehicle(const Vehicle& other) = delete;
    // Vehicle& operator=(const Vehicle& other) = delete;

    friend ostream& operator<<(ostream& out, const Vehicle& rhs)
    {
        out << rhs.wheels;
        return out;
    }

    ~Vehicle() = default;
};

int main(void)
{
    Vehicle carVar { Vehicle(4) };
    Vehicle car = carVar;

    cout << "A car has " << car << " wheels." << endl;

    return EXIT_SUCCESS;
}