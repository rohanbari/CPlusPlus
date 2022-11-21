/**
 * @file SpaceshipOp.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief The operator <=> is called the spaceship operator due to the fact that
 * it looks like an old-style ASCII spaceship from various early computer games.
 * It is designed to be used in classes, structs, and functions only.
 *
 * When it is used, the compiler generates automatically all of the comparison
 * operators you have just used, so your code will be much more streamlined
 * given that it fits your needs.
 *
 * This program shows the implementation of the "spaceship" operator.
 *
 * @note This program should be compiled with `-std=c++20` or higher flag.
 *
 * @version 0.1
 * @date 2022-11-21
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <compare>
#include <iostream>

using namespace std;

struct number {
    int value;
};

/**
 * @brief Compare between two integral values contained in the number structure.
 *
 * Features of weak_ordering:
 *   - does not allow incomparable values;
 *   - does not imply substitutability;
 *   - equivalent values may be indistinguishable;
 *   - less, equivalent, and greater are member constants.
 *
 */
constexpr weak_ordering operator<=>(const number& lhs, const number& rhs)
{
    return lhs.value <=> rhs.value;
}

/**
 * @brief Compare with the help of the spaceship operator-generated conditions.
 *
 * @param value Spaceship operation
 */
void compare(weak_ordering value)
{
    if (value == 0)
        cout << "Equal." << endl;
    else if (value > 0)
        cout << "Greater." << endl;
    else if (value < 0)
        cout << "Lesser." << endl;
    else
        cout << "Never-occurring condition." << endl;
}

int main(void)
{
    number n1 { 10 };
    number n2 { 15 };

    compare(n1 <=> n2);

    return EXIT_SUCCESS;
}