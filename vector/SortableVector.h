//SortableVector.h is derived from SimpleVector.h and contains a sort and swap method
#pragma once
#include "SimpleVector.h"
template <class T>
class SortableVector : public SimpleVector<T>
{
public:
	//Default constructor
	SortableVector() : SimpleVector<T>()
	{}

	//Constructor
	SortableVector(int size) : SimpleVector<T>(size)
	{}

	//Copy constructor
	SortableVector(const SortableVector &);

	//Sorting method
	void sort(int);

	//Swap method
	void swap(int &, int &);
};
template <class T>
SortableVector<T>::SortableVector(const SortableVector &obj) :
	SimpleVector<T>(obj.size())
{
	for (int count = 0; count < this->size(); count++)
		this->operator[](count) = obj[count];
}

template <class T>
void SortableVector<T>::sort(int size)
{
	int minIndex, minValue;

	for (int start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minValue = this->operator[](start);
		for (int index = start + 1; index < size; index++)
		{
			if (this->operator[](index) < minValue)
			{
				minValue = this->operator[](index);
				minIndex = index;
			}
		}
		swap(this->operator[](minIndex), this->operator[](start));
	}
}

//**********************************************
//The swap function swaps a and b in memory    *
//**********************************************
template <class T>
void SortableVector<T>::swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}