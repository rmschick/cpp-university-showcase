#pragma once
// SimpleVector class template
#include <iostream>
#include <new>       // Needed for bad_alloc exception
using namespace std;
template <class T>
class SimpleVector
{
private:
	T *aptr;          // To point to the allocated array
	int arraySize;    // Number of elements in the array
public:
	// Default constructor
	SimpleVector()
	{
		aptr = 0; arraySize = 0;
	}
	// Constructor declaration
	SimpleVector(int);
	// Copy constructor declaration
	SimpleVector(const SimpleVector &);
	// Destructor declaration
	~SimpleVector();
	// Accessor to return the array size
	int size() const
	{
		return arraySize;
	}
	// Accessor to return a specific element
	T getElementAt(int position);
	// Overloaded [] operator declaration
	T &operator[](const int &);
	//exception classes
	class MemError
	{
	private:
		string message;
	public:
		MemError(string m) { message = m; }
		string getMessage() { return message; }
	};
	class BadSubscript
	{
	private:
		string message;
	public:
		BadSubscript(string m) { message = m; }
		string getMessage() { return message; }
	};
};
//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************
template <class T>
SimpleVector<T>::SimpleVector(int s)
{
	arraySize = s;
	// Allocate memory for the array.
	try
	{
		aptr = new T[s];
	}
	catch (bad_alloc)
	{
		throw MemError("ERROR:Cannot allocate memory.\n");
	}
	// Initialize the array.
	for (int count = 0; count < arraySize; count++)
		*(aptr + count) = 0;
}
//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
	// Copy the array size.
	arraySize = obj.arraySize;
	// Allocate memory for the array.
	aptr = new T[arraySize];
	if (aptr == 0)
		throw MemError("ERROR:Cannot allocate memory.\n");
	// Copy the elements of obj's array.
	for (int count = 0; count < arraySize; count++)
		*(aptr + count) = *(obj.aptr + count);
}
//**************************************
// Destructor for SimpleVector class.  *
//**************************************
template <class T>
SimpleVector<T>::~SimpleVector()
{
	if (arraySize > 0)
		delete[] aptr;
}
//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************
template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
	if (sub < 0 || sub >= arraySize)
		throw BadSubscript("ERROR: Subscript out of range\n");
	return aptr[sub];
}
//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************
template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
	if (sub < 0 || sub >= arraySize)
		throw BadSubscript("ERROR: Subscript out of range\n");
	return aptr[sub];
}

