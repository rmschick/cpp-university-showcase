#pragma once
#include <iostream>
#include <string>
#include "ship.h"
using namespace std;

class CargoShip : public ship
{
private:
	int capacity;

public:
	CargoShip(string n, int c)
	{
		name = n;
		capacity = c;
	}

	int getCapacity()
	{
		return capacity;
	}
	
	void setCapacity(int c)
	{
		capacity = c;
	}

	void print() override
	{
		cout << "Name: " << name << "\nCargo Capacity: " << capacity << endl;
	}
};
