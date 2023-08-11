#pragma once

template <typename T>
class OrderedArray 
{
private:
    T* array; 
    int size; 
    int capacity; 
    int grow_size; 

public:
    OrderedArray(int grow_size = 10);

    ~OrderedArray();

    void push(const T& newElement);

    int length();

    T getElement(int index);

    bool remove(int index);

    int search(const T& target);

    void clear();
};

