/**
 * @file SimpleClassWithData.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief A simple demo class with data management in it.
 *
 * @version 0.1
 * @date 2022-11-21
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <cinttypes>
#include <iostream>

using namespace std;

/**
 * @brief A basic class with a member variable, three constructors, and a
 * member method that displays the value of the member variable.
 *
 */
class Vehicle {
    // This member variable is encapsulated by default. That means, only the
    // member methods can have access to this variable. It is completely
    // inaccessible from outside of the class definition.
    uint32_t numberOfWheels;

public:
    // In case the object is created without defining the numberOfWheels.
    Vehicle() { numberOfWheels = 4; }
    // In case a number is given while instantiating the class.
    Vehicle(const uint32_t& rhs)
        : numberOfWheels(rhs)
    {
    }
    // In case another object is provided while instantiation.
    Vehicle(const Vehicle& rhs)
        : numberOfWheels(rhs.numberOfWheels)
    {
    }

    /**
     * @brief This method has the only-access to numberOfWheels. So, it is used
     * to gain access to the value of the member from outside the class.
     *
     * Note that this method is publicly specified, and hence accessible with
     * the help of an object outside the class.
     *
     */
    void displayWheels(void)
    {
        cout << "Number of wheels: " << numberOfWheels << endl;
    }
};

int main(void)
{
    // Uniform initialization (c++11) can also be used here.
    Vehicle car;
    Vehicle truck(8);
    Vehicle motorcycle(Vehicle(2));

    // When uncommented, the line raises the following compiler error:
    //   member "Vehicle::numberOfWheels" (declared at line 26) is inaccessible
    // car.numberOfWheels = 32;

    car.displayWheels();
    truck.displayWheels();
    motorcycle.displayWheels();

    return EXIT_SUCCESS;
}