#pragma once 

template <class T>
class OrderedArray
{
	T* array;
	int size;
	int capacity;
	int growSize;

public:
	OrderedArray(int grow_size);
	OrderedArray();
	~OrderedArray();

	void push(const T& newElement);
	int length();
	T getEliment(int index);
	bool remove(int index);
	int search(const T& target);
	void clear();

};

template <class T>
OrderedArray<T>::OrderedArray(int grow_size)
{
	array = new T[grow_size];
	capacity = grow_size;
	size = 0;

	array = new T[capacity];
}

template <class T>
OrderedArray<T>::OrderedArray()
{

}

template <class T>
OrderedArray<T>::~OrderedArray()
{
	delete[]array;
}


template <class T>
void OrderedArray<T>::push(const T& newElement)
{
	if (size == capacity)
	{
		return false;
	}
	else
	{
		array[size] = newElement;
		size++;
	}
}

template<class T>
int OrderedArray<T>::length()
{
	return size;
}

template <class T>
T OrderedArray<T>::getEliment(int index)
{
	if (size > 0)
	{
		return array[size - 1];
	}
	return 0;
}

template <class T>
bool OrderedArray<T> ::remove(int index)
{

}


template <typename T>
int OrderedArray<T>::search(const T& target)
{

}

template<class T>
void OrderedArray<T> ::clear()
{
	delete[]array;
	array = nullptr;

}
