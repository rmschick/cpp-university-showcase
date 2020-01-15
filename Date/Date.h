#pragma once
//class definition file for the date class
//Ryan Schick
//9/27/2018
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;
class Date
{
private:
	int month;
	int day;
	int year;
	string convMonth();
public:
	bool setMonth(int);	 //set methods
	bool setDay(int);
	bool setYear(int);
	int getMonth()		//get methods
	{
		return month;
	}
	int getDay()
	{
		return day;
	}
	int getYear()
	{
		return month;
	}

	string format1();	//formating strings to match the output
	string format2();
	string format3();

};