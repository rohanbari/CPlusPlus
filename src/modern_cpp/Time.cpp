/**
 * @file Time.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief Working with chrono in C++.
 * @version 0.1
 * @date 2022-11-18
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <chrono>
#include <ctime>
#include <iostream>
#include <thread>

using namespace std;
using namespace chrono;
using namespace literals;

/**
 * @brief Get the Current Date and Time.
 *
 */
void getCurrentDateAndTime(void)
{
    auto timePoint = system_clock::now();
    auto time = system_clock::to_time_t(timePoint);
    auto timeText = ctime(&time);

    cout << timeText;
}

/**
 * @brief Time comparison using chrono library.
 *
 */
void timeComparison(void)
{
    auto startPoint = system_clock::now();

    this_thread::sleep_for(500ms);

    auto endPoint = system_clock::now();
    auto timeElapsed = duration_cast<milliseconds>(endPoint - startPoint);

    cout << "Time taken to execute syntax: " << timeElapsed.count() << endl;
}

int main(void)
{
    getCurrentDateAndTime();
    timeComparison();

    return EXIT_SUCCESS;
}