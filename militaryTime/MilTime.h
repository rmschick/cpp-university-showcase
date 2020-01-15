#pragma once
#include "Time.h"
#include <iostream>
#include <string>
using namespace std;
class MilTime : public Time
{
private:
	string milHours;
	int milSec;
	void convMilHr();
	void convMilMin();
public:
	MilTime(string, int);
	bool setTime(string, int);
	string getHour();
	int getStandHr();

};