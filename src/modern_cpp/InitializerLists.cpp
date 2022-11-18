/**
 * @file InitializerLists.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief A program that demonstrates the explicit declaration of an
 * initializer_list in C++.
 * @version 0.1
 * @date 2022-11-17
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <initializer_list>
#include <iostream>
#include <vector>

using namespace std;

using CVector = vector<int>;

int main(void)
{
    initializer_list<int> list { 1, 3, 5, 7, 9, 11, 13, 17, 23, 29 };
    CVector myVector(list);

    for (const auto& it : myVector)
        cout << it << endl;

    return EXIT_SUCCESS;
}