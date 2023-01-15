/**
 * @file Counter.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief Using std::count() with STL iterators effectively.
 *
 * @version 0.1
 * @date 07-12-2022
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace ns {
    using std::cout;
    using std::endl;

    class Demo {
        int member {};

    public:
        Demo() = default;
        Demo(const int& _member)
            : member(_member)
        {
        }
        Demo(const Demo& rhs) = default;

        Demo& operator=(const Demo& rhs) = default;
        bool operator==(const Demo& rhs) const noexcept
        {
            return member == rhs.member;
        }

        ~Demo() = default;
    };

    /**
     * @brief First scenario.
     *
     */
    void firstScenario()
    {
        vector<int> container {3, -5, 2, 9, 6, 4, 5, 6, 5, 6};
        auto count = std::count(container.cbegin(), container.cend(), 6);

        cout << "Occurrences of 6s: " << count << endl;
    }

    /**
     * @brief Second scenario.
     *
     */
    void secondScenario()
    {
        // A sample string container
        string line = "Today, a quick brown fox jumps over 2 lazy dogs!";

        auto countUpper = count_if(line.cbegin(), line.cend(), [](auto&& ch) {
            return static_cast<bool>(isupper(ch));
        });
        auto countLower = count_if(line.cbegin(), line.cend(), [](auto&& ch) {
            return static_cast<bool>(islower(ch));
        });
        auto countNumeric = count_if(line.cbegin(), line.cend(), [](auto&& ch) {
            return static_cast<bool>(isdigit(ch));
        });
        auto countPunct = count_if(line.cbegin(), line.cend(), [](auto&& ch) {
            return static_cast<bool>(ispunct(ch));
        });

        cout << "Capital letters: " << countUpper << endl
             << "Small letters: " << countLower << endl
             << "Numeric letters: " << countNumeric << endl
             << "Punctuation letters: " << countPunct << endl;
    }

    /**
     * @brief Third scenario.
     *
     */
    void thirdScenario()
    {
        vector<Demo> container {5, -3, 2, 3, 5, 3, 5, 1};
        auto countFive
            = std::count(container.cbegin(), container.cend(), Demo(5));

        cout << "Occurrences of 5s: " << countFive << endl;
    }
};

int main(void)
{
    ns::firstScenario();
    cout << "---" << endl;
    ns::secondScenario();
    cout << "---" << endl;
    ns::thirdScenario();

    return EXIT_SUCCESS;
}