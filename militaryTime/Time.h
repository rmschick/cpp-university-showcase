#pragma once
//Time.h file from page 972 in the 9/e of the book
class Time
{
protected:
	int hour;
	int min;
	int sec;
public:
	Time()
	{
		hour = 0; min = 0; sec = 0;
	}
	Time(int h, int m, int s)
	{
		hour = h; min = m; sec = s;
	}
	int getHour() const
	{
		return hour;
	}
	int getMin() const
	{
		return min;
	}
	int getSec() const
	{
		return sec;
	}
};