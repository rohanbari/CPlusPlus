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

/**
 * @brief This namespace should not be used in the main function directly.
 *
 */
namespace pfs {

    /**
     * @brief Validate whether the string is a valid hex code.
     *
     * @param s The passed string
     * @return true
     * @return false
     */
    bool validate_hex_notation(const std::string& s)
    {
        return s.length() == 6
            && std::all_of(s.begin(), s.end(), [](unsigned char c) {
                   return std::isxdigit(c);
               });
    }
}

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

    /**
     * @brief Validate if the hex code is a valid color.
     *
     * @param colors The colors container
     */
    void validate_hex(const Colors& pColors)
    {
        for (const auto& it : pColors) {
            bool flag = pfs::validate_hex_notation(it);
            if (!flag) {
                std::cerr << "error: Hex code " << it << " is invalid.\n";
                break;
            }
        }
    }

    /**
     * @brief The color mixer's algorithm.
     *
     * @param pColors The colors container
     */
    void mix(const Colors& pColors)
    {
        struct RGB {
            double R;
            double G;
            double B;
        };

        std::stringstream ss {};
        RGB newColor {};

        for (size_t i = 0, len = pColors.size(); i < len; i++) {
            RGB color {};
            unsigned int value = 0U;

            ss << std::hex << pColors.at(i);
            ss >> value;

            color.R = ((value >> 16) & 0xFF) / 255.0;
            color.G = ((value >> 8) & 0xFF) / 255.0;
            color.B = (value & 0xFF) / 255.0;

            newColor = {(newColor.R + color.R) / 2, (newColor.G + color.G) / 2,
                (newColor.B + color.B) / 2};

            ss.clear();
        }
    }
} // namespace ns

int main()
{
    Colors colors {};

    ns::get_colors_from_user(colors);
    ns::validate_hex(colors);
    ns::mix(colors);

    return EXIT_SUCCESS;
}