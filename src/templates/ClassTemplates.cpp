/**
 * @file ClassTemplates.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief Class templates are building blocks of the STL containers. In fact,
 * STL stands for Standard 'Template' Library.
 *
 * @version 0.1
 * @date 15-12-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>

using namespace std;

/**
 * @brief A class template miniature of an actual STL container std::array.
 *
 * @tparam T
 * @tparam size
 */
template <typename T, const size_t size>
class Array {
    T data[size];

public:
    Array() = default;
    Array(const T& rhs)
        : data(rhs)
    {
    }
    Array(const Array& rhs)
        : data(rhs.data)
    {
    }
    Array(const initializer_list<T>& p)
    {
        for (size_t i = 0; i < size; i++)
            // Took me a while to find this out myself.
            // Each element => begin + 'i'th element of init_list.
            data[i] = *(p.begin() + i);
    }

    T& operator=(const T& rhs)
    {
        data = rhs.data;
        return *data;
    }
    // Subscript operator overload to access the array indices.
    T& operator[](const size_t index)
    {
        return (index < 0 || index >= size) ? data[0] : data[index];
    }

    ~Array() = default;
};

int main()
{
    Array<int, 5ULL> container {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
        cout << container[i] << endl;

    return EXIT_SUCCESS;
}