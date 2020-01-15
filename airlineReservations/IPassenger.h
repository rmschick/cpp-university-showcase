#pragma once
#include<iostream>
#include<string>
#include<iomanip>
using namespace std; 
/* The class "IPassenger" stores the details of passengers as a linked list of values. The data is passenger's name and flight name.*/
class IPassenger 
{
public:
	string Iname;
	string Iflight; 
	IPassenger *Inext; 
	IPassenger(const string Iname, string Iflight, IPassenger* p = NULL) // It takes passenger name and flight name as parameters and adds the information to linked list 
	{
		this->Iname = Iname;
		this->Iflight = Iflight;
		this->Inext = p;
	}
};