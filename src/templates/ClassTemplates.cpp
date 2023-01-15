/**
 * @file ClassTemplates.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief Class templates are building blocks of the STL containers. In fact,
 * STL stands for Standard 'Template' Library.
 *
 * @version 0.1
 * @date 15-12-2022
 *
 * @copyright Copyright (c) 2022 rohanbari
 *
 */

#include <exception>
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
    size_t mainSize {};

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
        mainSize = p.size();

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
    T& operator[](const size_t index) noexcept(false)
    {
        // Throw an exception if:
        //   - index is negative
        //   - index is greater than the size of the init_list
        //   - init_list size is greater than the assigned size
        if (index < 0 || index >= mainSize || mainSize > size)
            throw out_of_range("Index went out of range.");

        return data[index]; // Appropriate data
    }

    const size_t getSize() const { return size; }

    ~Array() = default;
};

int main()
{
    Array<int, 5ULL> container {1, 2, 3, 4, 5};

    for (size_t i = 0, len = container.getSize(); i < len; i++)
        cout << container[i] << endl;

    Array<double, 3ULL> dblContainer {3.5, 1.2, 7.9, 4.32};

    for (size_t i = 0, len = dblContainer.getSize(); i < len; i++)
        cout << dblContainer[i] << endl;

    return EXIT_SUCCESS;
}