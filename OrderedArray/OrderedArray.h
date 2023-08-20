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
	int length() const; 
	T getElement(int index) const;
	bool remove(int index);
	int search(const T& target) const; 
	void clear();

};

template <class T>
OrderedArray<T>::OrderedArray(int grow_size)
{
	capacity = grow_size;
	size = 0;
	growSize = grow_size;

	array = new T[capacity];
}

template <class T>
OrderedArray<T>::OrderedArray()
{
	int defaultGrowSize = 10;
	growSize = defaultGrowSize;
	capacity = defaultGrowSize;
	size = 0;

	array = new T[capacity];
}

template <class T>
OrderedArray<T>::~OrderedArray()
{
	delete[] array;
}

template <class T>
void OrderedArray<T>::push(const T& newElement)
{
	if (size == capacity)
	{
		int newCapacity = capacity + growSize;
		T* newArray = new T[newCapacity];
		for (int i = 0; i < size; ++i)
		{
			newArray[i] = array[i];
		}
		delete[] array;
		capacity = newCapacity;
		array = newArray;
	}

	int insertIndex = 0;
	while (insertIndex < size && array[insertIndex] < newElement)
	{
		++insertIndex;
	}
	for (int i = size - 1; i >= insertIndex; --i)
	{
		array[i + 1] = array[i];
	}
	array[insertIndex] = newElement;
	++size;
}

template<class T>
int OrderedArray<T>::length() const
{
	return size;
}

template <class T>
T OrderedArray<T>::getElement(int index) const
{
	if (index >= 0 && index < size)
	{
		return array[index];
	}
	else
	{
		return T();
	}
}

template <class T>
bool OrderedArray<T>::remove(int index)
{
	if (index >= 0 && index < size)
	{
		for (int i = index; i < size - 1; ++i)
		{
			array[i] = array[i + 1];
		}
		--size;
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
int OrderedArray<T>::search(const T& target) const
{
	for (int i = 0; i < size; ++i)
	{
		if (array[i] == target)
		{
			return i;
		}
	}
	return -1;
}

template<class T>
void OrderedArray<T>::clear()
{
	delete[] array;
	size = 0;
	capacity = growSize;
	array = new T[capacity];
}
