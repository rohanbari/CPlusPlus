/**
 * @file MinMax.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief The STL provides algorithms that allow you to find both the largest
 * and smallest values in an STL container. These are the min_element and
 * max_element functions.
 *
 * @version 0.1
 * @date 2022-12-01
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

namespace ns {
    /**
     * @brief A demo class with a custom comparator as .operator=() overload.
     *
     * NOTE: See classes directory to learn about classes, its special member
     * functions, and other advanced things.
     */
    class Demo {
        int member {};

    public:
        Demo() = default;
        Demo(const int& _member)
            : member(_member)
        {
        }
        Demo(const Demo& rhs) = default;
        Demo(Demo&& rhs) noexcept = default;

        Demo& operator=(const Demo& rhs) = default;
        Demo& operator=(Demo&& rhs) noexcept = default;
        bool operator<(const Demo& rhs) const noexcept
        {
            return member < rhs.member;
        }

        const int getMember() const { return member; }

        friend std::ostream& operator<<(std::ostream& out, const Demo& rhs)
        {
            return out << rhs.member;
        }

        ~Demo() = default;
    };

    /**
     * @brief First scenario.
     *
     */
    void scenarioFirst(void)
    {
        // A vector container
        std::vector<int> container {2, -4, 4, 3, 0, 1, 5};

        // min_element and max_element functions have complexity of O(n).
        auto min = std::min_element(container.begin(), container.end());
        auto max = std::max_element(container.begin(), container.end());

        std::cout << "Minimum: " << *min << '\n'
                  << "Maximum: " << *max << std::endl;
    }

    /**
     * @brief Second scenario.
     *
     */
    void scenarioSecond(void)
    {
        std::vector<Demo> container {3, 5, -1, 8, 4, -5, 0};
        // Custom comparator
        auto comp = [](const Demo& lhs, const Demo& rhs) {
            return lhs.getMember() < rhs.getMember();
        };
        // Using the user-defined comparator defined as lambda.
        auto min = std::min_element(container.begin(), container.end(), comp);
        auto max = std::max_element(container.begin(), container.end(), comp);

        std::cout << "Minimum: " << *min << '\n'
                  << "Maximum: " << *max << std::endl;
    }
}

int main(void)
{
    ns::scenarioFirst();
    ns::scenarioSecond();

    return EXIT_SUCCESS;
}