/**
 * @file UOMaps.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief An unordered_map does not come with the difficulty of creating your
 * own hash function (like unordered_set) so long as you use a type for the key
 * that the STL can already hash.
 *
 * @version 0.1
 * @date 2022-11-29
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * @brief Object class.
 *
 */
class Object {
    string name {};

public:
    Object() = default;
    Object(string _name)
        : name(_name)
    {
    }
    Object(const Object& rhs)
        : name(rhs.name)
    {
    }

    const string getName() const noexcept { return name; }

    ~Object() = default;
};

int main(void)
{
    // An unordered container that will remain unordered.
    unordered_map<int, Object> container {
        pair<int, Object>(1, "One"),
        pair<int, Object>(4, "Four"),
        pair<int, Object>(3, "Three"),
        pair<int, Object>(5, "Five"),
        pair<int, Object>(2, "Two"),
    };

    // Displaying the unordered map as it is.
    for (const auto& it : container)
        cout << it.first << " -> " << it.second.getName() << '\n';
    cout << flush;

    // Finding the hash of key 2.
    auto it { container.find(2) };
    if (it != container.cend())
        cout << "Found: " << it->second.getName() << endl;

    return EXIT_SUCCESS;
}