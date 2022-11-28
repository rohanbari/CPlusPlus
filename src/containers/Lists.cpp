/**
 * @file Lists.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief std::list is a container that supports constant time insertion and
 * removal of elements from anywhere in the container. Fast random access is not
 * supported. It is usually implemented as a doubly-linked list.
 * @cite https://en.cppreference.com/w/cpp/container/list
 *
 * It costs performance when it comes to traversing the members frequently. It
 * should be used when ugly data-structures are supplied (not to access them
 * frequently).
 *
 * @version 0.1
 * @date 2022-11-28
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>
#include <list>

using namespace std;

/**
 * @brief Display the elements of the list.
 *
 * @param l The list
 */
void display(const list<int>& l)
{
    for (const auto& it : l)
        cout << it << ' ';
    cout << endl;
}

int main(void)
{
    // List containing the terms of the Fibonacci series.
    list<int> container { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 };

    container.emplace_back(89); // Available in vectors
    container.emplace_front(0); // Unavailable in vectors

    display(container);

    container.pop_back();
    container.pop_front();
    container.pop_front();

    container.remove(13);

    display(container);

    // NOTE: 1. Similar member methods exist for this container, too.
    //       2. It can be used in iterators and algorithms, too.

    return EXIT_SUCCESS;
}