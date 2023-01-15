/**
 * @file FindSets.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief This is a C++ program to find the item in a set with custom
 * conditions and comparison operator-overload.
 *
 * @version 0.1
 * @date 07-12-2022
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>
#include <set>

using namespace std;

/**
 * @brief A standard item data structure.
 *
 */
struct Item {
    string name;
    string property;
    int quantity;
    double price;
};

/**
 * @brief Custom comparator function.
 *
 * @param left  Left-side value
 * @param right Right-side value
 * @return true
 * @return false
 */
bool operator<(const Item& left, const Item& right)
{
    return left.name < right.name;
}

int main()
{
    // I like to know about weapons, especially guns.
    set<Item> container {
        {"AK-47", "A very powerful but noisy rifle.", 1, 2500},
        {"MP5A3", "A smooth and silent rifle.", 5, 2350},
        {"G-17 SD", "A sidearm weapon.", 3, 900},
    };

    auto it = container.find({"MP5A3", "", 0, 0.0});
    if (it != container.end())
        cout << "This weapon is available in our stock.\n";
    else
        cout << "This weapon is not available in our stock.\n";
    cout << flush;

    return EXIT_SUCCESS;
}