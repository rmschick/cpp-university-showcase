#include <iostream>
#include <string>
#include "CargoShip.h"
#include "CruiseShip.h"

using namespace std;

int main() 
{
	const int NUM_SHIPS = 3;
	ship *boats[NUM_SHIPS] =
	{
		new ship("Lollipop", "1960"),
		new CruiseShip("Disney Magic", 2400),
		new CargoShip("Black Pearl", 50000)
	};
	for (int i = 0; i < NUM_SHIPS; i++)
	{
		boats[i]->print();
		cout << "----------------------------" << endl;
	}
	for  (int i = 0; i < NUM_SHIPS; i++)
	{
		delete boats[i];
	}
	system("pause");
	return 0;

}
