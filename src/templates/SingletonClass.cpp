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

template <typename T>
class Singleton {
    static T* data;

public:
    Singleton()
    {
        assert(data == nullptr);
        static_cast<T*>(this);
    }

    virtual ~Singleton() { data = nullptr; }

    static T& getSingleton() { return *data; }
    static T* getSingletonPtr() { return data; }
};
template <typename T>
T* Singleton<T>::data = nullptr;

class SingletonManager : public Singleton<SingletonManager> {
public:
    void display() const
    {
        std::cout << "Successful execution from Singleton.\n";
    }
};

int main()
{
    new SingletonManager();

    SingletonManager& manager = SingletonManager::getSingleton();
    manager.display();

    delete SingletonManager::getSingletonPtr();

    return EXIT_SUCCESS;
}