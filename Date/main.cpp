/*	main.cpp
	Demonstrates the use of the date class
	Ryan Schick
	9/27/2018
*/

#include "Date.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	Date cal;
	int d, m, y;
	do {								//user input for day and input validation loop
		cout << "Enter a day (1-31): ";
		cin >> d;
	} while (!cal.setDay(d));

	do {							//user input for month and input validation loop
		cout << "Enter a month (1-12): ";
		cin >> m;
	} while (!cal.setMonth(m));

	do {							//user input for year and input validation loop
		cout << "Enter a year (1900-2025): ";
		cin >> y;
	} while (!cal.setYear(y));

	cout << cal.format1() << endl;			//print out all the formats for date
	cout << cal.format2() << endl;
	cout << cal.format3()  <<endl; 
	system("pause");
}