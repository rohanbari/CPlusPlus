/**
 * @file MoveConstructor.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief std::move() does not move anything, indeed.
 *
 * Move constructor moves the resources in the heap, i.e., unlike copy
 * constructors that copies the data of the existing object and assigns it to
 * the new object. Move c'tor makes the pointer of the declared object to point
 * to the data of a temporary object and nullifies the pointer of the temporary
 * objects.
 *
 * Thus, move constructor prevents unnecessarily copying data in the memory.
 *
 * @version 0.1
 * @date 2022-11-24
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>

using namespace std;

/**
 * @brief This beautiful class is an ideal example of the rule-of-five.
 *
 * @tparam T Type of the specialization
 */
template <typename T>
class Demo {
    T member {};

public:
    Demo() = default;
    Demo(const T& rhs)
        : member(rhs)
    {
    }
    Demo(const Demo& rhs)
        : member(rhs.member)
    {
    }
    // Invoked when type<T> lvalue = move(...) is called.
    Demo(Demo&& rhs)
        : member(rhs.member)
    {
        rhs.member = 0;
    }

    // Copy assignment operator= overload
    Demo& operator=(const Demo& rhs)
    {
        member = rhs.member;
        return *this;
    }
    // Invoked when lvalue = move(...) is called.
    Demo& operator=(Demo&& rhs)
    {
        member = rhs.member;
        rhs.member = 0;

        return *this;
    }

    // operator<< overload
    friend ostream& operator<<(ostream& out, const Demo& rhs)
    {
        return out << rhs.member;
    }

    ~Demo() = default;
};

int main(void)
{
    // Instantiation of myValue object.
    Demo<int> myValue {10};
    // Invocation of the overridden move constructor.
    // A famous note: "std::move() does not really move anything."
    Demo<int> myMovedValue = move(myValue);
    Demo<int> anotherMovedValue {};
    // Invocation of the overridden move assignment operator.
    anotherMovedValue = move(myMovedValue);

    cout << "myValue: " << myValue << endl
         << "myMovedValue: " << myMovedValue << endl
         << "anotherMovedValue: " << anotherMovedValue << endl;

    return EXIT_SUCCESS;
}