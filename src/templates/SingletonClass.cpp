/**
 * @file SingletonClass.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief Singleton classes are used when one only wants to create a single
 * instance of the class which is being accessed from other parts of the
 * application.
 *
 * We can use a class template to create a Singleton base and manager classes.
 *
 * @version 0.1
 * @date 16-12-2022
 *
 * @copyright Copyright (c) 2022 rohanbari
 *
 */

#include <cassert>
#include <iostream>

/**
 * @brief Singleton base class.
 *
 * @tparam T Type
 */
template <typename T>
class Singleton {
    static T* data;

public:
    Singleton()
    {
        assert(data == nullptr); // Assertion of nullability condition
        data = static_cast<T*>(this); // Assignment of 'this' cast to data
    }

    // Contributes to make this class an abstract class and nullifies the static
    // instance when the SingletonManager object goes out of scope.
    virtual ~Singleton() { data = nullptr; }

    /* Accessors */
    static T& getSingleton() { return *data; }
    static T* getSingletonPtr() { return data; }
};
// Initializing the static member of the class.
template <typename T>
T* Singleton<T>::data = nullptr;

/**
 * @brief Singleton manager class.
 * This kind of derivation is known as CRTP (Curiously Recursive Template
 * Pattern.)
 *
 */
class SingletonManager : public Singleton<SingletonManager> {
public:
    void display() const
    {
        std::cout << "Successful execution from Singleton.\n";
    }
};

int main()
{
    // The main function creates a SingletonManager using the new keyword. The
    // SingletonManager is not stored as a reference or pointer to the class.
    new SingletonManager();

    // Statically accessing the singleton dereferenced data.
    SingletonManager& manager = SingletonManager::getSingleton();
    manager.display();

    // Freeing the instance.
    delete SingletonManager::getSingletonPtr();

    return EXIT_SUCCESS;
}