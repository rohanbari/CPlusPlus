/**
 * @file Find.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief The STL provides the find function to retrieve iterators to the first
 * element in a sequence that matches a supplied value. Let's use 'em!
 *
 * @warning Incomplete program.
 *
 * @version 0.1
 * @date 2022-12-02
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <algorithm>
#include <iostream>

using namespace std;

int main(void)
{
    // A sample string -- let me appreciate myself.
    string strGreat { "Rohan is one of the best programmers in the world." };
    auto countT = find(strGreat.cbegin(), strGreat.cend(), 't');

    // Iteration keep continues until the end.
    while (countT != strGreat.cend()) {
        // Display when theCount is filled.
        cout << *countT << endl;
        // ++theCount changes the iterator to the next iterator element.
        countT = find(++countT, strGreat.cend(), 't');
    }

    auto closure = [](const char& ch) {
        return (toupper(ch) >= 'T') ? ch : ' ';
    };
    auto countAfterT = find_if(strGreat.cbegin(), strGreat.cend(), closure);

    if (countAfterT != strGreat.cend()) {
        cout << *countAfterT << endl;
        countAfterT = find_if(++countAfterT, strGreat.cend(), closure);
    }

    // std::find_if, std::find_if_not, etc. can be used with a user-defined
    // predicate (comparator.)

    return EXIT_SUCCESS;
}