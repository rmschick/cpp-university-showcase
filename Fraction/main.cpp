#include "Fraction.h"
#include<iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	Fraction userFraction;
	Fraction start(3,5);

	cout << "*****Fraction Demonstration*****" << endl;
	cout << "We will start with the fraction " << start << endl;
	cout << "Enter a new fraction: " << endl;
	cin >> userFraction;								//asking for user input and reducing the fraction if possible
	cout << "Your simplified fraction is: " << userFraction << endl;
	cout << "********************************" <<endl;
	cout << "Demonstrating overloaded math operators: -, +, *, /" <<endl << "This will show negation of 3/5 and then our two fractions " << endl;
	cout << start << " and " << userFraction << " added, multiplied, and divided." << endl;
	cout << "-: " << -start <<endl;					//negation
	cout << "+: " << start + userFraction <<endl;	//adding
	cout << "*: " << start * userFraction << endl;	//multiplication
	cout << "/: " << start / userFraction << endl;	//division
	cout << "********************************" << endl;
	cout << "Demonstrating overloaded math operators: <, <=, >, >=, ==, !=" << endl << "by comparing " << start << " and " << userFraction <<endl;
	
	if(start.operator<(userFraction)) //if start is greater than userFraction
		cout << "<: true" << endl;
	else
		cout << "<: false" << endl;
	
	if (start.operator<=(userFraction)) //if start is greater than or equal to userFraction
		cout << "<=: true" << endl;
	else
		cout << "<=: false" << endl;
	
	if (start.operator>(userFraction)) //if start is less than userFraction
		cout << ">: true" << endl;
	else
		cout << ">: false" << endl;
	
	if (start.operator>=(userFraction)) //if start is less than or equal to userFraction
		cout << ">=: true" << endl;
	else
		cout << ">=: false" << endl;
	
	if (start.operator==(userFraction)) //if start and userFraction are equal
		cout << "==: true" << endl;
	else
		cout << "==: false" << endl;
	
	if (start.operator!=(userFraction)) //if start and userFraction are not equal
		cout << "!=: true" << endl;
	else
		cout << "!=: false" << endl;
	cout << "********************************" << endl;

	system("pause");
}
