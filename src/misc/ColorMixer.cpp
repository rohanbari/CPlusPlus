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

struct RGB {
    double R;
    double G;
    double B;

    friend RGB operator+=(const RGB& lhs, const RGB& rhs)
    {
        RGB newColor {};

        newColor.R = (lhs.R + rhs.R) / 2;
        newColor.G = (lhs.G + rhs.G) / 2;
        newColor.B = (lhs.B + rhs.B) / 2;

        return newColor;
    }
};

/**
 * @brief Color conversion functions.
 *
 */
namespace converter {

    /**
     * @brief Converts string to hex code.
     *
     * @param str String to be converted
     * @return    The hex code
     */
    int str_to_hex(const std::string str)
    {
        unsigned int x = 0;
        std::stringstream ss;

        ss << std::hex << str;
        ss >> x;

        return static_cast<int>(x);
    }

    /**
     * @brief Converts hex code to string.
     *
     * @param hex The hex code
     * @return    String
     */
    std::string hex_to_str(const unsigned int hex)
    {
        std::stringstream ss;

        ss << std::hex << hex;
        return ss.str();
    }

    /**
     * @brief Converts hex to RGB.
     *
     * @param hex The hex code
     * @return    RGB value
     */
    RGB hex_to_rgb(const unsigned int hex)
    {
        struct RGB rgbColor;

        rgbColor.R = ((hex >> 16) & 0xFF) / 255.0;
        rgbColor.G = ((hex >> 8) & 0xFF) / 255.0;
        rgbColor.B = ((hex)&0xFF) / 255.0;

        return rgbColor;
    }

    /**
     * @brief Converts RGB to hex.
     *
     * @param rgb The RGB value
     * @return    The hex code
     */
    int rgb_to_hex(const RGB& rgb)
    {
        int hexInt[] = {
            static_cast<int>(rgb.R),
            static_cast<int>(rgb.G),
            static_cast<int>(rgb.B),
        };

        unsigned int hex = ((hexInt[0] & 0xff) << 16)
            + ((hexInt[1] & 0xff) << 8) + (hexInt[2] & 0xff);
        return static_cast<int>(hex);
    }
}

namespace ns {

    /**
     * @brief Get the colors from user.
     *
     * @param pColors The colors container to be filled
     * @warning The argument will be overridden.
     */
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
    void validate_color(const Colors& pColors)
    {
        for (const auto& it : pColors) {
            // The length must be 6 letters with '0-9 a-f A-F' range.
            bool flag = it.length() == 6
                && std::all_of(it.begin(), it.end(), [](unsigned char c) {
                       return std::isxdigit(c);
                   });

            if (!flag) {
                std::cerr << "error: Hex code " << it << " is invalid.\n";
                break;
            }
        }
    }

    /**
     * @brief The color mixer's algorithm.
     *
     * @param pColors The colors container containing hex-code strings
     */
    void mix(const Colors& pColors)
    {
        RGB newColor {0.0, 0.0, 0.0};

        for (const auto& it : pColors) {
            int hex = converter::str_to_hex(it);
            RGB rgb = converter::hex_to_rgb(hex);

            newColor += rgb;
        }

        int hex = converter::rgb_to_hex(newColor);
        std::string str_newColor = converter::hex_to_str(hex);

        std::cout << "The new color is: " << str_newColor << '\n';
    }
} // namespace ns

int main()
{
    Colors colors {};

    ns::get_colors_from_user(colors);
    ns::validate_color(colors);
    ns::mix(colors);

    return EXIT_SUCCESS;
}