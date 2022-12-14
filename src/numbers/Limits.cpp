/**
 * @file Limits.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief In Variations.cpp, we have defined several variations of an integer.
 * But, we are not sure about the minimum and maximum values supported for each
 * of the given type.
 *
 * So, it is also necessary to understand how to obtain these important values
 * in an efficient and reliable way.
 *
 * @version 0.1
 * @date 2022-11-20
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>
#include <limits>

using namespace std;

int main(void)
{
    cout << "Minimum values of the integral types:" << endl;

    cout << "short int: " << numeric_limits<short int>::min() << endl;
    cout << "int: " << numeric_limits<int>::min() << endl;
    cout << "long int: " << numeric_limits<long int>::min() << endl;
    cout << "long long int: " << numeric_limits<long long int>::min() << endl;

    cout << endl << "Maximum values of the integral types:" << endl;

    cout << "short int: " << numeric_limits<short int>::max() << endl;
    cout << "int: " << numeric_limits<int>::max() << endl;
    cout << "long int: " << numeric_limits<long int>::max() << endl;
    cout << "long long int: " << numeric_limits<long long int>::max() << endl;

    return EXIT_SUCCESS;
}