#pragma once

template <typename T>
class OrderedArray
{
private:
    T* array;
    int size;
    int capacity;
    int growSize;

public:
    OrderedArray(int grow_size);
    OrderedArray(); 
    ~OrderedArray();

    void push(const T& newElement);
    int length() const;  
    T getElement(int index) const;
    bool remove(int index);
    int search(const T& target) const;
    void clear();

    template <typename T>
    OrderedArray<T>::OrderedArray(int grow_size) 
    {
        
    }

    template <typename T>
    OrderedArray<T>::OrderedArray()
    {
        
    }

    template <typename T>
    OrderedArray<T>::~OrderedArray()
    {
        delete[] this->array;
    }

    template <typename T>
    void OrderedArray<T>::push(const T& newElement)
    {
      
    }

    template <typename T>
    int OrderedArray<T>::length() const
    {

    }

    template <typename T>
    T OrderedArray<T>::getElement(int index) const
    {

    }

    template <typename T>
    bool OrderedArray<T>::remove(int index) 
    {

    }

    template <typename T>
    int OrderedArray<T>::search(const T& target) const 
    {

    }
n
    template <typename T>
    void OrderedArray<T>::clear()
    {

    }
};
