#include "ITicket.h"
#include "IPassenger.h"
#include<iostream>
#include<string>
ITicket::ITicket()
{
	Ihead = Itail = NULL;
}

ITicket::~ITicket()
{
	IPassenger* p = Ihead, *q = Ihead;
	while (p != NULL)
	{
		q = Ihead->Inext;
		delete p;
		p = q;
	}
}

/* The function reverselTicket()" is defined which takes name of passenger and flight name from user and adds the information to linked list.*/
void ITicket::reverselTicket()
{
	string Iname, Iflight;
	cout << "Enter Passenger Name: ";
	cin >> Iname;
	// Receive user input 
	cout << "Enter flight Name: ";
	cin >> Iflight; /* If the linked list is empty then add passenger details to linked list's head. */
	if (Ihead == NULL)
	{
		/* Set passenger details as the first node of linked list */
		Ihead = Itail = new IPassenger(Iname, Iflight);
		// Display message 
		cout << "Successful Booking" << endl;
		return;
	}
	/* If linked list contains elements, then add passenger details as next node of linked list and set a pointer to linked list's next node. */
	else
	{
		/* Declare a pointer variable "p" and assign "Ihead" to it */
		IPassenger *p = Ihead;
		/* Set to next node of list; pointer is set to next node of linked list.*/
		while (p->Inext)
		{
			if (p->Iname == Iname)
				break;
			else
				p = p->Inext;
		}
		p->Inext = new IPassenger(Iname, Iflight, p->Inext);
		cout << "Successful" << endl;
		return;
	}
}

void ITicket::cancellTicket()
{
	string Iname, Iflight;
	cout << "Enter Passenger Name: ";
	cin >> Iname;
	cout << "Enter Flight Name: ";
	cin >> Iflight;
	IPassenger *p = Ihead, *q = Ihead;
	//If passenger name and flight name matches
	if ((p->Iname == Iname) && (p->Iflight == Iflight))
	{
		Ihead = Ihead->Inext;
		cout << "Ticket cancelled" << endl;
		delete p;
		return;
	}
	p = Ihead->Inext;
	while (p)
	{
		if ((p->Iname == Iname) && (p->Iflight == Iflight))
		{
			q->Inext = p->Inext;
			delete p;
			cout << "Successful Cancellation!" << endl;
			return;
		}
		else {
			q = p;
			p = p->Inext;

		}
	}
	cout << "No such person exists!" << endl;
}

void ITicket::checklTicket()
{
	string Iname;
	cout << "Enter Passenger Name: ";
	cin >> Iname;
	IPassenger*p = Ihead;

	//Search passenger in linked list
	while (p != NULL)
	{
		if (p->Iname == Iname)
		{
			cout << "Passenger Name: " << p->Iname << "\n" << "Flight Name: " << p->Iflight << endl;
			cout << "Successful! Reservation found!" << endl;
			return;
		}
		else
			p = p->Inext;
	}
	cout << "No such reservation exists!" << endl;
	return;
}

void ITicket::display()
{
	IPassenger* p = Ihead;
	while (p != NULL)
	{
		cout << "Passenger Name: " << p->Iname << "\n" << "Flight Name: " << p->Iflight << endl;
		p = p->Inext;
	}
}