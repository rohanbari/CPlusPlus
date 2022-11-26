/**
 * @file Vectors.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief The major distinction between STL vectors and arrays is the absence of
 * size. Vectors are dynamic in nature and can be resized as preferred, when
 * arrays cannot.
 *
 * @version 0.1
 * @date 2022-11-26
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(void)
{
    // Our flexible vector container.
    vector<int> container {};
    string input {};

    cout << "Input several integers: ";
    getline(cin, input);

    // Input stringstream class instantiation to perform split operation.
    istringstream iss(input);

    // On each iteration, std::istream::operator>> is called and each value
    // separated by a space is emplaced back in the container.
    int temp = 0;
    while (iss >> temp)
        container.emplace_back(temp);

    // Displaying the values stored in the dynamic container.
    for (auto&& it : container)
        cout << it << endl;

    cout << "Size of the vector: " << container.size() << endl;

    return EXIT_SUCCESS;
}