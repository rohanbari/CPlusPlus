/**
 * @file STLIterators.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief The STL provides iterators that work with all containers and can be
 * used to denote the beginning and end of a sequence within a container.
 * The STL algorithms all work with iterators.
 *
 * @version 0.1
 * @date 2022-11-30
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    // A vector container
    vector<int> container { 10, 12, 8, 5, 2, 0, 1 };

    // vector<int>::const_iterator
    auto it = container.cbegin();
    while (it != container.cend()) {
        cout << *it << ' ';
        it++;
    }
    cout << endl;

    // NOTE: All the STL containers follow the same convention to define and
    //       traverse among the container elements.

    return EXIT_SUCCESS;
}