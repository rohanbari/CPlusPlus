/**
 * @file Compile.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief C++ compiler pre-defined command executor.
 * @version 0.1
 * @date 2022-11-25
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>

using namespace std;

const int MAX_ARGS = 2;

/**
 * @brief Validate the number of passed arguments.
 *
 * @param argc Number of passed argument
 * @param p    Name of the executable
 */
void validate_args(const int argc, const char* p)
{
    if (MAX_ARGS != argc) {
        cerr << "Usage: " << p << " <prog.cpp>" << endl;
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief Compile the passed program.
 *
 * @param prog
 */
void execute(const char* prog)
{
    string cmd = "g++.exe ";
    cmd.append(prog);

    if (system(cmd.c_str()) != EXIT_SUCCESS) {
        cerr << "error: Failed to successfully execute system()." << endl;
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char** argv)
{
    validate_args(argc, argv[0]);
    execute(argv[1]);

    return EXIT_SUCCESS;
}