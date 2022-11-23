/**
 * @file DeepCopy.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief When the default copy constructor or assignment operator overload is
 * called, the object on the LHS copies the values of the RHS. However, both
 * are dependent to each other as they point to the same memory. This is shallow
 * copy and okay to use unless otherwise required.
 *
 * Deep copy copies the exact amount of resources and store the values in its
 * own allocated location. Now, if the first object is altered, the second
 * object is not affected as it is now independent.
 *
 * This program describes the deep copy in C-style arrays.
 *
 * @warning If implemented the wrong way, the data of the second object may be
 * altered and the results would be undesired.
 *
 * @version 0.1
 * @date 2022-11-23
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <cinttypes>
#include <cstring>
#include <iostream>

using namespace std;

class Vehicle {
    char* name {};
    int32_t wheels {};

public:
    // Default constructor
    Vehicle() = default;
    // Overridden constructor
    Vehicle(const char* _name, const int32_t _wheels)
        : wheels(_wheels)
    {
        // Allocating the exact amount of memory used in char* name.
        const uint32_t size = strlen(_name) + 1;
        name = new char[size] {};

        strcpy(name, _name);
    }

    // Copy constructor override
    Vehicle(const Vehicle& rhs)
        : wheels(rhs.wheels)
    {
        const uint32_t size = strlen(rhs.name) + 1;
        name = new char[size] {};

        strcpy(name, rhs.name);
    }

    // Assignment operator overload
    Vehicle& operator=(const Vehicle& rhs)
    {
        if (name != nullptr)
            delete name;

        const uint32_t size = strlen(rhs.name) + 1;
        name = new char[size] {};

        strcpy(name, rhs.name);
        wheels = rhs.wheels;

        return *this;
    }

    // Output stream operator overload
    friend ostream& operator<<(ostream& out, const Vehicle& rhs)
    {
        return out << rhs.name << " has " << rhs.wheels << " wheels.";
    }

    ~Vehicle() = default;
};

int main(void)
{
    Vehicle myCar {};

    {
        // Sub-block object
        Vehicle mySameCar { "Bugatti Chiron", 4 };

        myCar = mySameCar;
        cout << myCar << endl;
    }

    // Independent to mySameCar object.
    cout << myCar << endl;

    return EXIT_SUCCESS;
}