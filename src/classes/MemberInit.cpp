/**
 * @file MemberInit.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief There are several ways to access the class fields in C++. Let's have
 * a look at them with examples.
 *
 * @version 0.1
 * @date 22-11-2022
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <cinttypes>
#include <iostream>

using namespace std;

/**
 * @brief The Vehicle class. It contains a default constructor, and two
 * overloaded copy constructors that accepts int32_t and Vehicle type (that
 * eventually accesses the int32_t field from the object) with a destructor.
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
    Vehicle(const Vehicle& rhs)
        : wheels(rhs.wheels)
    {
    }
    ~Vehicle() { wheels = 0; }

    // Overloading operator<< that supports output streams like cout.
    friend ostream& operator<<(ostream& out, const Vehicle& vehicle)
    {
        out << vehicle.wheels;
        return out;
    }
};

int main(void)
{
    // With the help of rule-of-three, there are now many ways to initialize the
    // object. Often, they can be used as if they were built-in variables.

    // 1: By default, wheels is assigned to zero.
    Vehicle human;
    cout << "human: " << human << endl;

    // 2: Along uniform initialization, copy elision-like way can also be used.
    Vehicle motorcycle {2};
    cout << "motorcycle: " << motorcycle << endl;

    /**
     * @brief 3: Copy elision-like method.
     * @warning In specific places, this can cause the vexing-parse problem.
     *
     */
    Vehicle car(Vehicle(4));
    cout << "car: " << car << endl;

    // 4: Instantiation with the help of initialization list.
    Vehicle truck {Vehicle {8}};
    cout << "truck: " << truck << endl;

    // 5: Copy elision-like method with initialization list. (unlikely to use!)
    Vehicle train(Vehicle {72});
    cout << "train: " << train << endl;

    return EXIT_SUCCESS;
}