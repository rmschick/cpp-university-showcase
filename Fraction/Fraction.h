#pragma once
#include<iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;
class Fraction {
private:
	int numerator;
	int denominator;
	int gcd();
public:
	Fraction();
	Fraction(int, int);
	void reduce(Fraction&);
	Fraction operator-();
	Fraction operator+(const Fraction&);
	Fraction operator-(const Fraction&);
	Fraction operator*(const Fraction&);
	Fraction operator/(const Fraction&);
	Fraction& operator=(const Fraction&);
	bool operator<(const Fraction&) const;
	bool operator<=(const Fraction&) const;
	bool operator>(const Fraction&) const;
	bool operator>=(const Fraction&) const;
	bool operator==(const Fraction&) const;
	bool operator!=(const Fraction&) const;
	friend ostream& 
		operator<<(ostream&, const Fraction&);
	friend istream&
		operator>>(istream&, Fraction&);
};
