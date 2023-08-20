// OrderedArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "OrderedArray.h"

int main()
{
    OrderedArray<int> intArray;

    intArray.push(5);
    intArray.push(2);
    intArray.push(8);
    intArray.push(-33);
    intArray.push(11);
    intArray.push(6);
    intArray.push(12);
    //intArray.push(3); 
    intArray.push(0);
    intArray.push(12);
    intArray.push(15);
    intArray.push(45);
    intArray.push(24.5);

    std::cout << "Array length: " << intArray.length() << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < intArray.length(); ++i)
    {
        std::cout << "Element at index " << i << ": " << intArray.getElement(i) << std::endl;
    }
    std::cout << std::endl;

    int indexRemove = 7;  
    bool removed = intArray.remove(indexRemove);

    if (removed) 
    {
        std::cout << "Element at index " << indexRemove << " removed" << std::endl;
    }
    else 
    {
        std::cout << "Element at index " << indexRemove << " not found or not removed" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Array length after removal: " << intArray.length() << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < intArray.length(); ++i) 
    {
        std::cout << "Element at index " << i << ": " << intArray.getElement(i) << std::endl;
    }
    std::cout << std::endl;

    int targetIndex = intArray.search(3);
    if (targetIndex >= 0)
    {
        std::cout << "Found 3 at index: " << targetIndex << std::endl;
    }
    else
    {
        std::cout << "3 not found in the array" << std::endl;
    };
    std::cout << std::endl;

    intArray.clear();

    std::cout << "Array cleared!" << std::endl;
    std::cout << std::endl;

    intArray.push(5);
    intArray.push(2);
    intArray.push(8);

    std::cout << "New Array length: " << intArray.length() << std::endl;
    std::cout << std::endl;

    return 0;
}
