/**
 * @file TemplateFunctions.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief Templates are useful when the type has to be concrete at compile-time,
 * but the usage of the templated class/function is not limited to a single type
 * of data.
 *
 * @version 0.1
 * @date 15-12-2022
 *
 * @copyright Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>

namespace ns {
    /**
     * @brief A standard C++ function.
     *
     * @param p The passed number
     * @return p
     */
    int getInteger(const int& p)
    {
        return p;
    }

    /**
     * @brief A templated C++ function.
     *
     * @tparam T Template type
     * @param p  The passed value
     * @return p
     */
    template <typename T>
    T getIntegerDynamic(const T& p)
    {
        return p;
    }
}

int main()
{
    std::cout << "Standard function:  " << ns::getInteger(10) << '\n'
              << "Templated function: " << ns::getIntegerDynamic(10);

    /* Explicit template specialization can be called with the help of the
    angle brackets. For example,

        int val = ns::getIntegerDynamic<decltype(val)>(2500)

    However, ambiguous definitions when multiple types are involved will
    result in a compilation error. */

    return EXIT_SUCCESS;
}