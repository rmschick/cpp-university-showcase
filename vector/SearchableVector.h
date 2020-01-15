//SearchableVector.h is derived from SortableVector.h and contains the findItem and sortAndSearch Method
#pragma once
#include "SortableVector.h"

template <class T>
class SearchableVector : public SortableVector<T>
{
public:
	//Default constructor
	SearchableVector() : SortableVector<T>()
	{}

	//Constructor
	SearchableVector(int size) : SortableVector<T>(size)
	{}

	//Copy constructor
	SearchableVector(const SearchableVector &);

	//Accessor to find an item
	int findItem(const T);

	//Sorting and Searching method
	int sortAndSearch(const T);
};

template<class T>
SearchableVector<T>::SearchableVector(const SearchableVector &obj) : 
					SimpleVector<T>(obj.size())
{
	for (int count = 0; count < this->size(); count++)
		this->operator[](count) = obj[count];
}

//*******************************************************
//findItem function                                     *
//This function searches for item. If item is found     *
//the subscript is returned. Otherwise -1 is returned.  *
//*******************************************************

template<class T>
int SearchableVector<T>::findItem(const T item)
{
	int first = 0;
	int last = (this->size() - 1);
	int middle;
	int position = -1;
	bool found = false;

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (this->operator[](middle) == item)
		{
			found = true;
			position = middle;
		}
		else if (this->operator[](middle) > item) //If value is in lower half
			last = middle - 1;
		else first = middle + 1; // If value is in upper half
	}
	return position;
}

template <class T>
int SearchableVector<T>::sortAndSearch(const T value)
{
	this->sort(this->size());
	return this->findItem(value);
}