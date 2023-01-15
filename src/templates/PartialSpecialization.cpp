/**
 * @file PartialSpecialization.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief In many cases, implicit or explicit template specialization does not
 * work when one of the multiple template parameters are ambiguous. In those
 * cases, partialization is needed.
 *
 * This program describes the implementation of partial template specialization.
 *
 * @version 0.1
 * @date 15-12-2022
 *
 * @copyright Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>

using namespace std;

/**
 * @brief A class template.
 *
 * @tparam T Class Type
 */
template <typename T>
class Demo {
    T data {};

public:
    Demo() = default;
    Demo(const T& rhs)
        : data(rhs)
    {
    }
    Demo(const Demo& rhs)
        : data(rhs.data)
    {
    }

    Demo& operator=(const Demo& rhs)
    {
        data = rhs.data;
        return *data;
    }
    friend ostream& operator<<(ostream& out, const Demo& rhs)
    {
        return out << rhs.data;
    }

    T getData() const { return data; }

    ~Demo() = default;
};

using demo = Demo<int>;

// This overload will not work for Demo<int> type as there are no operator
// overloads to handle '+' operator.
template <typename T>
T add(const T& a, const T& b)
{
    return a + b;
}

// To overcome the above-mentioned issue, partial specialization comes.
template <>
demo add<demo>(const demo& a, const demo& b)
{
    return add(a.getData(), b.getData());
}

int main()
{
    demo var1 {10};
    demo var2 {20};

    int other = add(10, 20); // Uses the first overload.
    demo res = add(var1, var2); // Uses the second overload.

    cout << other << '\n' << res << endl;

    return EXIT_SUCCESS;
}