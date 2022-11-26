/**
 * @file Arrays.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief The major advantage of using the STL array container over C-style
 * arrays is that it allows access to STL iterators and algorithms.
 *
 * @version 0.1
 * @date 2022-11-26
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <algorithm>
#include <array>
#include <iostream>
#include <utility>

using namespace std;

const int SIZE = 5;

namespace ns {
void methodPrimary(const array<int, SIZE>& container)
{
    for (auto&& it : container)
        cout << it << ' ';
    cout << endl;
}

void methodSecondary(array<int, SIZE>&& container)
{
    for_each(container.cbegin(), container.cend(), [](auto&& value) {
        cout << value << ' ';
    });
    cout << endl;
}
};

int main(void)
{
    array<int, SIZE> container { 4, 3, 1, 6, 8 };

    // Pass-by-reference
    ns::methodPrimary(container);
    // Perfect forwarding
    ns::methodSecondary(forward<decltype(container)>(container));

    return EXIT_SUCCESS;
}