/**
 * @file StaticMemory.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief The global variables may be called static variables as they are
 * accessible from any part of the program. However, there exist many demerits
 * compared to its advantages. Thus, it is recommended to keep the usage of
 * the global variables to a minimum.
 * 
 * This program demonstrates why.
 * 
 * Note that the C++ standards does not guarantee if the global variables will
 * be initialized in order. Therefore, in case the latter variable is dependent
 * on the former one and if it is not initialized, the result could be dire.
 * 
 * @version 0.1
 * @date 09-02-2023
 * 
 * Copyright (c) 2023 Rohan Bari <rohanbari4@gmail.com>
 * 
 */

#include <iostream>

int counter = 0;

void increment() {
    counter += 5;
    std::cout << "Global counter: " << counter << '\n';
}

int main() {
    // Next 3 lines are OK in behavior.
    counter += 10;
    std::cout << "Counter: " << counter << '\n';
    increment();

    // The anomalous behavior begins right from here!
    // The global 'counter' is masked with the local one.
    int counter = 1000;
    counter += 5;
    std::cout << "Local counter: " << counter << '\n';
    
    // Only this can access the original counter now.
    increment();

    return 0;
}