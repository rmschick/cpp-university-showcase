//date.cpp
//method definition file for date.h
//Ryan Schick
// 9/27/2018

#include "Date.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

string Date::convMonth()		//makes the word representation of the month 
{
	string wordMonth = "";
	if (month == 1)
		wordMonth = "JANUARY";
	else if (month == 2)
		wordMonth = "FEBRUARY";
	else if (month == 3)
		wordMonth = "MARCH";
	else if (month == 4)
		wordMonth = "APRIL";
	else if (month == 5)
		wordMonth = "MAY";
	else if (month == 6)
		wordMonth = "JUNE";
	else if (month == 7)
		wordMonth = "JULY";
	else if (month == 8)
		wordMonth = "AUGUST";
	else if (month == 9)
		wordMonth = "SEPTEMBER";
	else if (month == 10)
		wordMonth = "OCTOBER";
	else if (month == 11)
		wordMonth = "NOVEMBER";
	else
		wordMonth = "DECEMBER";

	return wordMonth;
}

bool Date::setMonth(int m)		//input validation for month 
{
	bool retValue = false;
	if (m >= 1 && m <= 12)
	{
		month = m;
		retValue = true;
	}
	return retValue;
}

bool Date::setDay(int d)	//input validation for day
{
	bool retValue = false;
	if (d >= 1 && d <= 31)
	{
		day = d;
		retValue = true;
	}
	return retValue;
}

bool Date::setYear(int y)	//input validation for year
{
	bool retValue = false;
	if (y >= 1900 && y <= 2025)
	{
		year = y;
		retValue = true;
	}
	return retValue;
}

string Date::format1()	//formating to "MONTH/DAY/YEAR"
{
	string display1 = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
	return display1;
}

string Date::format2()	//formating to "DAY MONTH YEAR"
{
	string display2 = to_string(day) + " " + convMonth() + " " + to_string(year);
	return display2;
}

string Date::format3()	//formating to "MONTH DAY, YEAR"
{
	string display3 = convMonth() + " " + to_string(day) + ", " + to_string(year);
	return display3;
}