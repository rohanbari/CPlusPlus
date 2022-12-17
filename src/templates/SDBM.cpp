/**
 * @file SDBM.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief The SDBM hash algorithm can be used when you need to calculate complex
 * values and would like to avoid computing them at runtime. Template
 * metaprogramming takes advantage of the C++ template compiler to calculate
 * values at compile time and save runtime performance for users.
 *
 * @version 0.1
 * @date 16-12-2022
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>

// This will be the type of the hash.
using UInt = unsigned int;

/**
 * @brief The SDBM hash system.
 *
 * @tparam length String length
 */
template <int length>
struct SDBM {
    /**
     * @brief This function calculates hash.
     *
     * @param hash  The hash
     * @param value The corresponding value
     * @return constexpr UInt Hash value
     */
    constexpr static UInt calculateHash(const char* const hash, UInt& value)
    {
        UInt ch {SDBM<length - 1>::calculateHash(hash, value)};
        value = ch + (value << 6) + (value << 16) - value;

        return hash[length - 1];
    }

    /**
     * @brief Calculate the value of the corresponding hash.
     *
     * @param hash The hash value
     * @return constexpr UInt The value represented by the hash
     */
    constexpr static UInt calculateValue(const char* const hash)
    {
        UInt value {};
        UInt ch {SDBM<length - 1>::calculateHash(hash, value)};

        value = ch + (value << 6) + (value << 16) - value;
        return value;
    }
};

// Partial specialization for SDBM when the length is unity.
template <>
struct SDBM<1> {
    constexpr static UInt calculateHash(const char* const hash, UInt& value)
    {
        return hash[0];
    }
};

int main()
{
    constexpr UInt myHash {SDBM<10>::calculateValue("Rohan Bari")};
    std::cout << myHash << std::endl;

    return EXIT_SUCCESS;
}