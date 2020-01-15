#include "Fraction.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

Fraction::Fraction()
{
	numerator = 0;
	denominator = 1;
}
Fraction::Fraction(int n, int d) 
{
	numerator = n;
	denominator = d;

}
int Fraction::gcd() //Finding Greatest Common Denominator
{
	int gcd = 1;
	int smallest = ( numerator < denominator) ?
		numerator : denominator;
	for (int x = 2; x<=smallest; x++)
		if (numerator % x == 0 && denominator % x == 0)
			gcd =x;
	return gcd;
	
}
void Fraction::reduce(Fraction& red) // simplify the Fraction number
{
	int tmp = gcd();
	red.numerator /= tmp;
	red.denominator /= tmp;
}
Fraction Fraction::operator-() //Making the fraction negative
{
	return Fraction(-numerator,denominator);
}

Fraction Fraction::operator+(const Fraction &a) //adding fractions
{
	Fraction ad = Fraction(this->numerator * a.denominator + this->denominator * a.numerator,
		this->denominator * a.denominator);
	ad.reduce(ad);
	return ad;
}

Fraction Fraction::operator-(const Fraction &s) //substracting fractions
{
	return Fraction(this->numerator * s.denominator - this->denominator * s.denominator,
		this->denominator * s.denominator);
}

Fraction Fraction::operator*(const Fraction &m) //multiplying fractions
{
	Fraction mult = Fraction(this->numerator * m.numerator, this->denominator * m.denominator);
	mult.reduce(mult);
	return mult;
}

Fraction Fraction::operator/(const Fraction &d) // dividing fractions
{
	Fraction div = Fraction(this->numerator * d.denominator, this->denominator * d.numerator);
	div.reduce(div);
	return div;
}

Fraction& Fraction::operator=(const Fraction &right) // setting fractions equal to eachother
{
	this->numerator = right.numerator;
	this->denominator = right.denominator;
	return *this;
}

bool Fraction::operator<(const Fraction &right) const //if the left fraction is less than the right fraction
{
	double thisVal = ((double)this->numerator / this->denominator);
	double rightVal = ((double)right.numerator / right.denominator);
	return thisVal < rightVal;
}

bool Fraction::operator<=(const Fraction &right) const //if the left fraction is less than or equal to the right fraction
{
	double thisVal = ((double)this->numerator / this->denominator);
	double rightVal = ((double)right.numerator / right.denominator);
	return thisVal <= rightVal;
}

bool Fraction::operator>(const Fraction &right) const //if the left fraction is greater than the right fraction
{
	double thisVal = ((double)this->numerator / this->denominator);
	double rightVal = ((double)right.numerator / right.denominator);
	return thisVal >rightVal;
}

bool Fraction::operator>=(const Fraction& right) const //if the left fraction is greater than or equal to the right fraction
{
	double thisVal = ((double)this->numerator / this->denominator);
	double rightVal = ((double)right.numerator / right.denominator);
	return thisVal >= rightVal;
}

bool Fraction::operator==(const Fraction &right) const
{
	return this->numerator == right.numerator && this->denominator == right.denominator;
}

bool Fraction::operator!=(const Fraction &right) const
{
	return this->numerator != right.numerator || this->denominator != right.denominator;
}

ostream& operator<<(ostream& out, const Fraction& fr)
{
	if (fr.numerator == 0)
		out << 0;
	else if (fr.denominator == 1)
		out << fr.numerator;
	else
		out << fr.numerator << '/' << fr.denominator;
	return out;
}

istream& operator>>(istream& input, Fraction& c)
{
	cout << "Numerator: ";
	input >> c.numerator;

	cout << "Denominator: ";
	input >> c.denominator;

	c.reduce(c);
	return input;
}