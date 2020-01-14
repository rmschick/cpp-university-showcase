#include "Storage.h"
#include "AgeHashTable.h"
#include "DisabilityHashTable.h"
#include "GeogHashTable.h"

//objects for the classes
AgeHashTable age;
DisHashTable dis;
GeogHashTable geog;	

int main()
{
	vector<string> geogVector;
	vector<string> ageVector;
	vector<string> disabilityVector;

	readInputFile(geogVector,ageVector,disabilityVector);

    cout << "Processing complete!" << endl;

	return 0;
}