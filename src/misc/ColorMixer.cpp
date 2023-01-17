/**
 * @file ColorMixer.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program can calculate the new color obtained by the combination
 * of two or more colors using hex code.
 *
 * @version 0.1
 * @date 17-01-2023
 *
 * Copyright (c) 2023 rohanbari
 *
 */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using Colors = std::vector<std::string>;

namespace constants {

    const char VALID_HEX[] {"0123456789abcdef"};
} // namespace constants

namespace ns {

    void get_colors_from_user(Colors& pColors)
    {
        std::string input {};

        std::cout << "Enter any no. of colors in hex code below without #:\n";
        std::getline(std::cin, input);

        // String validation
        if (!std::cin) {
            std::cerr << "error: Invalid input!\n";
            exit(EXIT_FAILURE);
        }

        std::string temp {};

        // Splits and saves the colors in a vector.
        std::istringstream iss(input);
        while (iss >> temp)
            pColors.push_back(temp);

        iss.clear();
    }

    void validate_hex(Colors& colors)
    {
        bool flag = true;

        for (const auto& it : colors) {
            if (it.length() != 6) {
                std::cerr << "error: Hex code must be of length 6.\n";
                exit(EXIT_FAILURE);
            }

            for (const auto& subIt : it)
                if (subIt < '0' || subIt > '9')
                    if (subIt < 'A' || subIt > 'F') {
                        flag = false;
                        break;
                    }
        }
        if (!flag) {
            std::cerr << "error: Hex code(s) are not given correctly.\n";
            exit(EXIT_FAILURE);
        }
    }
} // namespace ns

int main()
{
    Colors colors {};

    ns::get_colors_from_user(colors);
    ns::validate_hex(colors);

    return EXIT_SUCCESS;
}