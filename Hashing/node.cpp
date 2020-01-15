//node.cpp creates a record and puts it into a txt file called "Milliwop.txt"
//Ryan Schick 
//Due 4/15/2019
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include <new.h>


using namespace std;

class node
{
public:
	char name[20];
	char free[20];
	node *Link;

};
node *first = NULL;

void writeFile()

{
	node *P;
	char buffer[200];
	fstream out;
	out.open("Milliwop.txt", ios::out);
	if (!out)
	{
		cout << "\n Unable to open the file Milliwop.txt in out mode";
		_getch();
		exit(0);
		}
	P = first;
	while (P!=NULL)
	{
		strcpy_s(buffer, P->name);
		strcat_s(buffer, "|");
		strcat_s(buffer, P->free);
		strcat_s(buffer, "\n");
		out << buffer;
		P = P->Link;
	}
}

void display()		//displays contents 
{
	node*PopDrop;
	if (first == NULL)
	{
		cout << "\n List is empty. You might want to fill it";
		return;
	}
	PopDrop = first;
	while (PopDrop != NULL)
	{
		cout << "The name added is " << PopDrop->name << endl;
		cout << PopDrop->name << "'s Gamer ID is " << PopDrop->free << endl;
		PopDrop = PopDrop->Link;
	}
}

void Insert()				//Insert the record at the end
{
	char name[20], free[15];
	node *PopLock, *Quevo;
	cout << "\nEnter name: ";
	cin >> name;
	cout << "\nEnter Gamer ID: ";
	cin >> free;
	PopLock = new node;
	strcpy(PopLock->name, name);
	strcpy(PopLock->free, free);
	PopLock->Link = NULL;
	if (first == NULL)
	{
		first = PopLock;
		writeFile();
		display();		// display the record
		return;
	}
	
	// Quevo->Link = PopLock;
		writeFile();		//writng the record to the file
		display();
	
}

void deleteData()
{
	char free[15];
	node *dust, *pov, *del;
	if (first == NULL)
	{
		printf("\n The list is empty. Deleting is impossible. Maybe you should add an ID");
		return;
	}
	cout << "\n Enter the Username to be deleted ";
	cin >> free;
	if (strcmp(first->free, free) == 0)
	{
		cout << "\nRecord deleted";
		del = first;
		delete del;
		first = first->Link;
		writeFile();
		return;
	}
	pov = NULL;
	dust = first;
	/*while ((strcmp(dust->free,free) !=0) && dust != NULL)
	{
		pov = dust;
		dust = dust->Link;
	}*/
	if (dust == NULL)
	{
		cout << "\n The Tom Clancy's Rainbow Six Siege Player with the name " << free << "is not present";
		return;
	}
	pov->Link = dust->Link;
	writeFile();
	display();
}
int main()
{
	int choice = 0;
	
	for (;;) {
		printf("\n 1: Insert User name for Tom Clancy's Rainbow Six Siege ID");
		printf("\n 2: Delete ID");
		printf("\n 3: Exit");
		printf("\n Enter your choice: ");
		cin >> choice;
		switch (choice)
		{
		case 1: Insert();
			break;
		case 2: deleteData();
			break;
		case 3: exit(0);
		default: cout << "\n Invalid option";
			break;
		}
	}
}
