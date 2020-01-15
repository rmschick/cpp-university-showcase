#pragma once
#include <iostream>
#include <string>
using namespace std;

class ship {
private:
	string year;
protected:
	string name;
public:
	ship()
	{
		name = ""; 
		year = "";
	}

	ship(string n, string y)
	{
		name = n;
		year = y;
	}

	void setName(string n)
	{
		name = n;
	}

	void setYear(string y)
	{
		year = y;
	}

	string getName()
	{
		return name;
	}

	string getYear()
	{
		return year;
	}

	virtual void print()
	{
		cout << "Name: " << name << "\nYear Built: " << year << endl;
	}
};
