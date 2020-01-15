//main.cpp is the tester for the Time.h and MilTime.h headers
//It demonstrates the setting and conversion of military time

#include "MilTime.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	MilTime m1("0012", 3);
	bool isValid;
	int mSeconds;
	string mHours;
	cout << "A military time of " << m1.getHour() << ":" << m1.getSec() << " = " << m1.getStandHr() << ":" << m1.getMin() << ":" << m1.getSec() << endl;
	m1.setTime("1145", 5);
	cout << "A military time of " << m1.getHour() << ":" << m1.getSec() << " = " << m1.getStandHr() << ":" << m1.getMin() << ":" << m1.getSec() << endl;
	m1.setTime("1419", 34);
	cout << "A military time of " << m1.getHour() << ":" << m1.getSec() << " = " << m1.getStandHr() << ":" << m1.getMin() << ":" << m1.getSec() << endl;
	cout << endl << "Enter a number of military hours in the format #### followed by a space and then a number of seconds: ";
	cin >> mHours;
	cin >> mSeconds;
	isValid = m1.setTime(mHours, mSeconds);
	while (!isValid)
	{
		cout << "Sorry, that wasn't a valid time.  Try again.";
		cout << endl << "Enter a number of military hours in the format #### followed by a space and then a number of seconds: ";
		cin >> mHours >> mSeconds;
		isValid = m1.setTime(mHours, mSeconds);
	}
	cout << "A military time of " << m1.getHour() << ":" << m1.getSec() << " = " << m1.getStandHr() << ":" << m1.getMin() << ":" << m1.getSec() << endl;

	system("pause");
	return 0;

}