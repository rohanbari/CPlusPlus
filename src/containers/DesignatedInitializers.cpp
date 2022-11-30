/**
 * @file DesignatedInitializers.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief This feature introduces a new syntax that initializes an aggregate by
 * specifying pairs of public data member designators followed by two ways to
 * initialize object properties, via direct initialization or braces.
 *
 * @note Compile with C++20 and higher standard flags.
 *
 * @version 0.1
 * @date 2022-11-30
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>
#include <vector>

using std::ostream;
using std::string;

struct Vehicle {
    int serial {};
    string model {};
};

int main(void)
{
    // Three ways to initialize. The first two of them uses designated
    // initialization method.
    std::vector<Vehicle> cars { { .serial = 420, .model = "Bugatti Chiron" },
        { .serial { 421 }, .model { "Lamborghini Centenario" } },
        { 422, "Ferrari LaFerrari" } };

    for (const auto& it : cars)
        std::cout << it.serial << " -> " << it.model << '\n';
    std::cout << std::flush;

    return EXIT_SUCCESS;
}