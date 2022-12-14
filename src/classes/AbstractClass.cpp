/**
 * @file AbstractClass.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief An abstract class is a class that is designed to be specifically used
 * as a base class. An abstract class needs to have at least one pure virtual
 * function declared.
 *
 * You cannot use an abstract class as a parameter type, a function return type,
 * or the type of an explicit conversion, nor can you declare an object of an
 * abstract class. You can, however, declare pointers and references to an
 * abstract class.
 *
 * @version 0.1
 * @date 2022-11-25
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>

using namespace std;

class Demo {
    int member {};

public:
    Demo() = default;
    Demo(const int& rhs)
        : member(rhs)
    {
    }
    Demo(const Demo& rhs)
        : member(rhs.member)
    {
    }
    Demo(Demo&& rhs)
        : member(rhs.member)
    {
        rhs.member = 0;
    }

    Demo& operator=(const Demo& rhs)
    {
        member = rhs.member;
        return *this;
    }
    Demo& operator=(Demo&& rhs)
    {
        member = rhs.member;
        rhs.member = 0;

        return *this;
    }

    virtual void func() = 0;
    virtual ~Demo() = 0;
};
// Default pure virtual destructor
Demo::~Demo() = default;

class DerivedDemo : Demo {
public:
    DerivedDemo() = default;

    inline void func() override { cout << "Virtual function called." << endl; }
};

int main(void)
{
    DerivedDemo myDemo {};
    myDemo.func();

    return EXIT_SUCCESS;
}