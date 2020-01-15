#include "MilTime.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

MilTime::MilTime(string hours, int sec)
{
	setTime(hours, sec);
}

bool MilTime::setTime(string hr, int Msec)
{
	bool retValue = false;
	int tempHr = stoi(hr);
	if ((tempHr < 2400 && tempHr>=0) && (Msec < 60 && Msec>=0)) //Checking for input validation
	{
		milHours = hr;	//Military Hours set to the string parameter
		milSec = Msec;	// Military Seconds set to the int parameter
		convMilHr();	
		convMilMin();	//Two private methods that converts MilitaryHours to the Standard form of Hours and Minutes
		sec = Msec;		//Standard seconds set to the int parameter
		retValue = true;
	}
	return retValue;


}
int MilTime::getStandHr()
{
	convMilHr();
	return hour;
}

string MilTime::getHour()
{ 
	return milHours;
}

void MilTime::convMilHr() //Convert Military Hours to Hours
{
	hour = stoi(milHours);
	if (hour > 1259)		
	{
		hour -= 1200;
		hour /= 100;
	}
	else if (hour <100)
		hour = 12;
	else
	{
		hour /= 100;
	}
		
}

void MilTime::convMilMin() //Convert Military Minutes to Minutes
{
	min = stoi(milHours);
		min %=100;

}