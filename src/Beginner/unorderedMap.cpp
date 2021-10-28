/**
 * @file unorderedMap.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This C++ file enlightens the correct situation to use a pair of two
 * distinct typed variables simultaneously to simplify the program.
 * @version 0.1
 * @date 2021-10-28
 * 
 * @copyright Copyright (c) 2021 Rohan Bari
 * 
 */

#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * @brief Structure for Car object.
 */
struct Car {
    string modelName;
    int code;
};

int main(void)
{
    unordered_map<string, int> cars;
    Car temp;

    static int count;
    char ask;

    do {
        cout << "Enter the car's name [" << ++count << "]: ";
        getline(cin, temp.modelName);

        cout << "Car Code: ";

        // Abort if the code given is non-assignable.
        if (!(cin >> temp.code)) {
            cerr << "error: Invalid integer code.\n";
            return EXIT_FAILURE;
        }

        // Assignment of the pair.
        cars[temp.modelName] = temp.code;

        cout << "Add another? (Y/N) ";

        if (!(cin >> ask)) {
            cerr << "error: Only Y and N are supported letters.\n";
            return EXIT_FAILURE;
        }

        // Flushing the input stream.
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (ask == 'Y' || ask == 'y');

    // Display the collected results.
    for (auto it : cars)
        cout << it.first << " is registered with " << it.second << endl;

    return EXIT_SUCCESS;
}