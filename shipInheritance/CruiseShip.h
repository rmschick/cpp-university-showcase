#pragma once
#include <iostream>
#include <string>
#include "ship.h"
using namespace std;

class CruiseShip : public ship
{
private: 
	int passengers;
public:
	CruiseShip(string n, int p)
	{
		name = n;
		passengers = p;
	}
	void setYear(int p)
	{
		passengers = p;
	}

	int getPassengers()
	{
		return passengers;
	}

	void print() override
	{
		cout << "Name: " << name << "\nMaximum Number of Passengers: " << passengers << endl;
	}
};

