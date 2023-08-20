#pragma once

#include "OrderedArray.h"

template <class T>
class MySet
{
private:
	OrderedArray<T> elements;

public:
	MySet() = default;
	void add(const T& element)
	{
		elements.push(element);
	}

	MySet operator| (const MySet& other) const
	{
		MySet result;
		for (int i = 0; i < elements.length(); ++i)
		{
			result.add(elements.getElement(i));
		}
		for (int i = 0; i < other.elements.length(); ++i)
		{
			result.add(other.elements.getElement(i));
		}
		return result;
	}

	MySet operator&(const MySet& other) const
	{
		MySet result;
		for (int i = 0; i < elements.length(); i++)
		{
			if (other.elements.search(elements.getElement(i)) >= 0)
			{
				result.add(elements.getElement(i));
			}
		}
		return result;
	}
};

