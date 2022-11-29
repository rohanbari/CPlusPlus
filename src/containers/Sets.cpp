/**
 * @file Sets.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief Sets shows characteristics on fast-lookup of contained data. The STL
 * provides the set container that can automatically sort their objects.
 *
 * @version 0.1
 * @date 2022-11-29
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>
#include <set>

using namespace std;

class Type {
    int index {};
    string value {};

public:
    Type() = default;
    Type(const int& _index, const string& _value)
        : index(_index)
        , value(_value)
    {
    }
    // Copy and move c'tors
    Type(const Type& rhs)
        : index(rhs.index)
        , value(rhs.value)
    {
    }
    Type(Type&& rhs)
        : index(rhs.index)
        , value(rhs.value)
    {
    }

    // Copy and move assignment overloads
    Type& operator=(const Type& rhs)
    {
        index = rhs.index;
        value = rhs.value;

        return *this;
    }
    Type& operator=(Type&& rhs)
    {
        index = rhs.index;
        value = rhs.value;

        return *this;
    }
    // These comparison operator overloads are used to sort the set container.
    bool operator<(const Type& rhs) const { return index < rhs.index; }
    bool operator>(const Type& rhs) const { return index > rhs.index; }

    // Getters of the class fields
    int getIndex(void) const noexcept { return index; }
    string getValue(void) const noexcept { return value; }

    ~Type() = default;
};

int main(void)
{
    set<Type, greater<int>> container {
        { 1, "Hello" },
        { 3, "How" },
        { 2, "World" },
        { 5, "You?" },
        { 4, "Are" },
    };

    for (const auto& it : container)
        cout << it.getIndex() << " -> " << it.getValue() << '\n';
    cout << flush;

    return EXIT_SUCCESS;
}