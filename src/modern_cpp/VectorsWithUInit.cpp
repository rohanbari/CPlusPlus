/**
 * @file VectorsWithUInit.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief Initializing vectors with uniform initialization.
 * @version 0.1
 * @date 2022-11-17
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> vecA(1); // Number of vector elements to be initialized.
    vector<int> vecB(1, 5); // Number of vector elements to be initialized with
                            // the given common value.
    vector<int> vecC { 1, 5 }; // Elements 1 and 5 are to be pushed back.

    cout << vecA.size() << endl;
    cout << vecB.size() << ' ' << vecB.at(0) << endl;
    cout << vecC.size() << ' ' << vecC.at(1) << endl;

    return EXIT_SUCCESS;
}