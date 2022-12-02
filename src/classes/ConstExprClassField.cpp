/**
 * @file ConstExprClassField.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief In this program, I have attempted to initialize a class field of type
 * const int& at runtime with the help of a constexpr c'tor.
 *
 * @warning This is an experimental program.
 *
 * @version 0.1
 * @date 2022-11-22
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>

using namespace std;

template <typename T>
class Demo {
    const T& member;

public:
    Demo() = default;
    constexpr Demo(const T& rhs)
        : member(rhs)
    {
    }
    constexpr Demo(const Demo& rhs)
        : member(rhs.member)
    {
    }

    friend ostream& operator<<(ostream& out, const Demo& rhs)
    {
        out << rhs.member;
        return out;
    }
};

int main(void)
{
    int input = 0;

    cout << "Enter the value of a: ";
    cin >> input;

    if (!cin) {
        cerr << "error: Invalid input.\n";
        return EXIT_FAILURE;
    }

    const int& test = input;
    Demo<decltype(test)> demo { test };

    cout << "member: " << demo << endl;

    return EXIT_SUCCESS;
}