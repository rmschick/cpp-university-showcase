#include "IPassenger.h"
#include "ITicket.h"
#include <iostream>
#include <string>;

int main()
{
	ITicket t;

	while (true)
	{
		cout << "===================================" << endl;
		cout << "Airline Ticket Reservation Program" << endl;
		cout << "1. Book Ticket" << endl;
		cout << "2. Cancel Ticket" << endl;
		cout << "3. Check Ticket" << endl;
		cout << "4. Display Passengers" << endl;
		cout << "5. Quit" << endl; 
		cout << "===================================" << endl;
		cout << "Enter your choice: ";

		//Input Recieved
		int input;
		cin >> input;
		switch (input)
		{
		//Call "reverselTicket()"
		case 1:
			t.reverselTicket();
			break;
		//Call "cancellTicket()
		case 2:
			t.cancellTicket();
			break;
		//Call "checkTicket()
		case 3:
			t.checklTicket();
			break;
		//Call "display()"
		case 4:
			t.display();
			break;
		case 5:
			return 0;
		default:
			cout << "Invalid choice! Please try again" << endl;
			break;
		}

	}
	return 0;
}