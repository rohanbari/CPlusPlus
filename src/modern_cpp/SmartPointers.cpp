/**
 * @file SmartPointers.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief Working with smart pointers that automatically manages allocation and
 * deallocation that helps optimize the code and increase maintainability.
 * @version 0.1
 * @date 2022-11-18
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>
#include <memory>

using namespace std;

class MyClass {
    int member;

public:
    MyClass()
    {
        member = 15;
        cout << "Constructing MyClass" << endl;
    }
    MyClass(const int& rhs)
        : member(rhs)
    {
        cout << "Constructing MyClass with copy member" << endl;
    }
    ~MyClass()
    {
        cout << "Destructing MyClass" << endl;
    }

    int getMember(void) const
    {
        return member;
    }
};

int main(void)
{
    // Type deduction also works.
    unique_ptr<MyClass> uniquePtr = make_unique<MyClass>();
    // Using the pointer-like behavior.
    cout << uniquePtr->getMember() << endl;

    return EXIT_SUCCESS;
}