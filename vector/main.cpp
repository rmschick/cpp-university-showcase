#include "SearchableVector.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	const int SIZE = 10;
	srand(time(0));
	try
	{
		SearchableVector<int> intTable(SIZE);
		//fill array with random numbers from 1-20
		for (int i = 0; i < SIZE; i++)
			intTable[i] = rand() % 20 + 1;
		cout << "intTable unsorted: " << endl;
		for (int i = 0; i < SIZE; i++)
			cout << intTable[i] << " ";
		cout << endl << endl;
		int findVal = 10;
		cout << "Searching for " << findVal << " in intTable.\n";
		int result = intTable.sortAndSearch(findVal);
		if (result == -1)
			cout << findVal << " was not found in intTable.\n";
		else
			cout << findVal << " was found at subscript "
			<< result << " in the sorted table. " << endl;
		//output the sorted vector
		cout << "\nintTable sorted: " << endl;
		for (int i = 0; i < SIZE; i++)
			cout << intTable[i] << " ";
		cout << endl << endl;
	}
	catch (SearchableVector<int>::MemError& e)
	{
		cout << e.getMessage();
	}
	catch (SearchableVector<int>::BadSubscript& e)
	{
		cout << e.getMessage();
	}
	system("pause");
	return 0;
}