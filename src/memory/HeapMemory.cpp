/**
 * @file HeapMemory.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief There are two types of memory in programming: stack and heap. Stack
 * memory is automatically used wherever the fundamental types are defined.
 * 
 * On the contrary, the heap memory (or, dynamic memory) needs a custom memory
 * allocation by the programmer. In short, stack memory is to local fundamental
 * variables of type(s) int, float, int[], float[], etc and heap memory is to
 * *ptr, object instances, etc.
 * 
 * Learn more about stacks and heaps:
 *   <https://opendsa-server.cs.vt.edu/ODSA/Books/CS2/html/HeapMem.html>
 * 
 * @version 0.1
 * @date 11-02-2023
 * 
 * Copyright (c) 2023 Rohan Bari <rohanbari4@gmail.com>
 * 
 */

#include <iostream>

class BoringClass {
    int boringVal{};

public:
    BoringClass() = default;
    void operator=(const int pVal) {
        boringVal = pVal;
    }


    friend std::ostream &operator<<(std::ostream &os, const BoringClass &bc) {
        return os << bc.boringVal;
    }

    ~BoringClass() {
        std::cout << "info: " << __func__ << " called!\n";
    }
};

int main() {
    // Size of the heap in bytes to be allocated on the heap memory.
    const size_t SIZE = 3;
    // Pointer to BoringClass objects on the heap memory.
    BoringClass *boringClass = new BoringClass[SIZE];

    // Why the d'tor is being called here?
    boringClass[0] = 5;
    boringClass[1] = 3;
    boringClass[2] = 1;

    for (size_t i = 0; i < SIZE; i++)
        std::cout << boringClass[i] << '\n';

    delete[] boringClass;
    boringClass = nullptr;

    return 0;
}