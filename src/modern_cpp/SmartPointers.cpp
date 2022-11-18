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

/**
 * @brief The sample class.
 *
 */
class MyClass {
    string className;
    int member;

public:
    MyClass()
    {
        member = 15;
        cout << "Constructing MyClass" << endl;
    }
    MyClass(const string& name, const int& rhs)
        : className(name)
        , member(rhs)
    {
        cout << "Constructing MyClass with copy member" << endl;
    }
    ~MyClass()
    {
        cout << "Destructing MyClass" << endl;
    }

    string getName(void) const
    {
        return className;
    }
    int getMember(void) const
    {
        return member;
    }
};

/**
 * @brief Example describing the usage of unique_ptr.
 *
 */
void useUniquePointer(void)
{
    // Type deduction also works.
    unique_ptr<MyClass> uniquePtr = make_unique<MyClass>("MySuperClass", 10);
    // Using the pointer-like behavior.
    cout << uniquePtr->getMember() << endl;
}

/**
 * @brief Example describing the usage of shared_ptr.
 *
 */
void useSharedPointer(void)
{
    // Type deduction can work here, too.
    shared_ptr<MyClass> sharedPtr = make_shared<MyClass>("MyClass", 5);

    if (sharedPtr)
        cout << sharedPtr->getName();
}

int main(void)
{
    useUniquePointer();
    useSharedPointer();

    return EXIT_SUCCESS;
}