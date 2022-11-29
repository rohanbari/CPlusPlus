/**
 * @file Maps.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief The map container is very similar to the set container except for the
 * fact that the key is stored independently of the object value.
 * @version 0.1
 * @date 2022-11-29
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>
#include <map>

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

/**
 * @brief Display the hashes of the called map.
 *
 * @param m The map
 */
void display(const map<int, Object, less<int>> m)
{
    for (const auto& it : m)
        cout << it.first << " -> " << it.second.getName() << '\n';
    cout << flush;
}

int main(void)
{
    // Defining a map container.
    map<int, Object, less<int>> container {
        pair<int, Object>(1, "Hello"),
        pair<int, Object>(4, "Are"),
        pair<int, Object>(2, "World"),
        pair<int, Object>(5, "You"),
        pair<int, Object>(3, "How"),
    };
    display(container);

    cout << "---\n";
    // Emplacing new values
    // Note that these are auto-sorted.
    container.emplace(pair<int, Object>(6, "?"));
    container.emplace(pair<int, Object>(0, "Hi!"));

    display(container);

    // Finding the hash contained in 4th key
    auto it = container.find(4);
    if (it != container.end())
        cout << "Found: " << it->second.getName() << endl;

    return EXIT_SUCCESS;
}