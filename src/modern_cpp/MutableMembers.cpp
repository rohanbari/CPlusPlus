/**
 * @file MutableMembers.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program illustrates how mutable and immutable variables work.
 * @version 0.1
 * @date 18-11-2022
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>

using namespace std;

class Class {
    // An immutable by-default member can NOT be modified by const functions.
    int simpleMember;
    // A mutable member can be modified by const functions.
    mutable int powerMember;

public:
    Class() = default;
    Class(const int& rhs1, const int& rhs2)
        : simpleMember(rhs1)
        , powerMember(rhs2)
    {
    }

    /**
     * @brief A const function.
     *
     */
    void cannotEdit(void) const
    {
        // It will cause an error during compilation.
        // Comment the code to be able to compile and run the program.
        simpleMember++;
        // However, powerMember is a mutable variable. It will not cause the
        // compiler to throw a compilation error.
        powerMember++;
    }

    /**
     * @brief Display the value of the members.
     *
     */
    void display(void) { cout << simpleMember << endl << powerMember << endl; }
};

int main(void)
{
    Class object(10, 5);

    object.cannotEdit();
    object.display();

    return EXIT_SUCCESS;
}