/**
 * @file ForEach.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief The STL provides the for_each function that takes a beginning
 * iterator, an ending iterator, and a function to call on each element between
 * the two.
 *
 * The for_each function can be passed two iterators. These iterators define the
 * beginning point and the end point in the container that should be traversed.
 * The third parameter is a function that should be called for each element. The
 * element itself is passed into the function.
 *
 * @version 0.1
 * @date 2022-12-01
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    // A vector container
    vector<int> container { 10, 12, 5, 13, 6 };
    // A closure is an unnamed function definition defined as an lvalue.
    auto closure = [](const int& value) {
        cout << value << ' ';
    };

    // Calling for_each() algorithm.
    for_each(container.cbegin(), container.cend(), closure);
    cout << endl;

    return EXIT_SUCCESS;
}