/**
 * @file MoveSemantics.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief Move constructors can be utilized to cut down on the complexity of a
 * copy constructor. This program demonstrates how.
 * @version 0.1
 * @date 2022-11-18
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>

using namespace std;

class MyClass {
    static int counter;
    int* member { &counter };

public:
    MyClass()
    {
        (*member)++;
        cout << "Constructing " << getMember() << endl;
    }
    ~MyClass()
    {
        (*member)--;
        member = nullptr;
        cout << "Destructing " << counter << endl;
    }

    /**
     * @brief Copy construct a new MyClass object.
     *
     * @param rhs
     */
    MyClass(const MyClass& rhs)
        : member { rhs.member }
    {
        ++(*member);
        cout << "Copying: " << getMember() << endl;
    }

    int getMember(void) const
    {
        return *member;
    }
};
int MyClass::counter { 0 };

MyClass copyClass(MyClass myClass)
{
    return myClass;
}

int main(void)
{
    auto object1 = MyClass();
    {
        auto object2 = MyClass();
    }
    auto object3 = MyClass();
    auto object4 = copyClass(object3);

    return EXIT_SUCCESS;
}