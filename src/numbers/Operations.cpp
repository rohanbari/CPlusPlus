/**
 * @file Operations.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief One can perform several mathematical operations on integers.
 *
 * @version 0.1
 * @date 2022-11-20
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>

using namespace std;

/**
 * @brief Print the value of the passed integer.
 *
 * @param name  Name of the variable
 * @param value Value to be displayed
 */
void printResult(const string name, const int value)
{
    cout << name << ": " << value << endl;
}

int main(void)
{
    int firstValue { 100 };
    printResult("firstValue", firstValue);

    int secondValue { firstValue + 25 };
    printResult("secondValue", secondValue);

    int thirdValue { secondValue - 15 };
    printResult("thirdValue", thirdValue);

    int fourthValue { firstValue * thirdValue };
    printResult("fourthValue", fourthValue);

    int fifthValue { fourthValue / secondValue };
    printResult("fifthValue", fifthValue);

    int sixthValue { fifthValue % 4 };
    printResult("sixthValue", sixthValue);

    return EXIT_SUCCESS;
}