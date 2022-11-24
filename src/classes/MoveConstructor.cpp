/**
 * @file MoveConstructor.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief
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
    Demo<int> myValue { 10 };
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