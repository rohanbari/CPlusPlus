/**
 * @file VectorsExtended.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief Welcome to the world of vectors! Let's use the most of it.
 * @version 0.1
 * @date 2022-11-26
 *
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

    /**
     * @brief Display the contents of the vector.
     *
     * @param v The vector
     */
    void display(const Vector& v)
    {
        for (const auto& it : v)
            cout << it << '\n';
        cout << endl;
    }

    /**
     * @brief Information about the vector.
     *
     * @param v The vector
     */
    void info(const Vector& v)
    {
        size_t size = v.size();
        size_t capacity = v.capacity();

        cout << "Size: " << size << endl << "Capacity: " << capacity << endl;
    }
} // namespace ns

int main(void)
{
    Vector container {};

    // On the next line, the container is modified globally.
    ns::fill(container);
    ns::display(container);
    ns::info(container);

    // NOTE: Iterators and algorithms can be used with containers.
    //       This is the main advantage.

    return EXIT_SUCCESS;
}