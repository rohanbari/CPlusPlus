/**
 * @file TimeDate.cpp
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
#include <functional>
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
 * @brief Get the time elapsed between an occurring event.
 *
 * @param pFunc A function to execute
 * @return      int64_t
 */
int64_t timeComparison(function<void()> pFunc)
{
    auto startPoint = system_clock::now();

    pFunc();

    auto endPoint = system_clock::now();
    auto timeElapsed = duration_cast<milliseconds>(endPoint - startPoint);

    return timeElapsed.count();
}

int main(void)
{
    getCurrentDateAndTime();

    auto testFunc = []() {
        this_thread::sleep_for(500ms);
    };
    int64_t t = timeComparison(testFunc);
    cout << t << endl;

    return EXIT_SUCCESS;
}