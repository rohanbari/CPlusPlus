/**
 * @file UOSets.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief Using an unordered_set to store class objects requires some difficult
 * to understand code.
 * Partial specialization for the hash template allows us to create a function
 * that is capable of creating a hash value for the Object class.
 *
 * @version 0.1
 * @date 2022-11-29
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>
#include <unordered_set>

using namespace std;

// Forward declaration
class Object;

// Implementation of the specialized template
template <>
class std::hash<Object> {
public:
    template <typename... Args>
    size_t operator()(Args&&... object) const
    {
        return hash<string>()((forward<Args...>(object...)).getName());
    }
};

/**
 * @brief Object class for the set container.
 *
 */
class Object {
    string name {};
    size_t hash {};

public:
    Object() = default;
    Object(const string& _name)
        : name(_name)
        , hash(std::hash<Object>()(*this))
    {
    }
    Object(const Object& rhs)
        : name(rhs.name)
        , hash(rhs.hash)
    {
    }

    // Getters for the member field
    const string& getName() const noexcept { return name; }
    const size_t& getHash() const noexcept { return hash; }

    // .operator== overload to compare two hashes
    bool operator==(const Object& rhs) const noexcept
    {
        return hash == rhs.hash;
    }

    ~Object() = default;
};

int main(void)
{
    // An unordered set
    unordered_set<Object> container { { "One" }, { "Three" }, { "Five" },
        { "Four" }, { "Two" } };

    cout << showbase << hex;
    // Displaying the unordered set
    for (const auto& it : container)
        cout << it.getName() << " -> " << it.getHash() << '\n';
    cout << flush;

    auto it = container.find({ "Three" });
    if (it != container.cend())
        cout << it->getName() << " -> " << it->getHash() << endl;

    return EXIT_SUCCESS;
}