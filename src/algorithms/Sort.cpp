/**
 * @file Sort.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief std::sort sorts a given container. It takes a predicate on which the
 * sort operation will be based on. It is a useful container that eliminates
 * boilerplate code by the developer.
 *
 * @version 0.1
 * @date 07-12-2022
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

using Const = const int&;

int main()
{
    std::vector<int> container {11, -3, 5, 0, 4, 9, 8};
    // * The passed iterator must be modifiable.
    // * A lambda function with two parameters is given as a predicate.
    // * This sorts as: greatest --> lowest
    sort(container.begin(), container.end(), [](Const left, Const right) {
        return left > right;
    });

    // Displaying the contained values.
    for (const auto& it : container)
        std::cout << it << ' ';
    std::cout << std::endl;

    return EXIT_SUCCESS;
}