/**
 * @file TypeDeduction.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief Using type-deduction (compatible to C++11).
 * @version 0.1
 * @date 2022-11-18
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>
#include <typeinfo>

using namespace std;

/**
 * @brief Custom data-type.
 *
 */
class CustomType {
public:
    CustomType() = default;
    CustomType(const CustomType& rhs) = default;
};

/**
 * @brief Accepts any type of value and passes it to the user.
 *
 * @tparam T Type of the passed value
 * @param param The value to be returned
 * @return decltype(param) Passed parametric value
 */
template <typename T>
auto autoTypeFunction(T param) -> decltype(param)
{
    return param;
}

void primaryScenario(void)
{
    auto value = CustomType();
    cout << typeid(value).name() << endl;

    auto classValue { CustomType() };
    cout << typeid(classValue).name() << endl;
}

void secondaryScenario(void)
{
    auto value = autoTypeFunction(200);
    cout << value << endl;
}

int main(void)
{
    primaryScenario();
    secondaryScenario();

    return EXIT_SUCCESS;
}