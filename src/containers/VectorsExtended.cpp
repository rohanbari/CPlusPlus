/**
 * @file VectorsExtended.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief Welcome to the world of vectors! Let's use the most of it.
 * @version 0.1
 * @date 2022-11-26
 *
 * @warning Incomplete program.
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

using Vector = vector<int>;

namespace ns {
    /**
     * @brief Fill up the passed vector container globally.
     *
     * @param v The vector container
     */
    void fill(Vector& v)
    {
        string input {};

        cout << "Input any number of integers: ";
        getline(cin, input);

        // To learn about this idiom: see [Vectors.cpp] file.
        istringstream iss(input);

        int temp = 0;
        while (iss >> temp)
            v.emplace_back(temp);
    }
}

int main(void)
{
    Vector container {};

    // After this line, the container is modified globally.
    ns::fill(container);

    return EXIT_SUCCESS;
}