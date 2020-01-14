#pragma once
#include "linked_list.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class DisEntry
{
public:
	string geo;	//key values
	string hearing;
	string vision;
	string cognitive;
	string ambulatory;
	string selfCare;
	string independentLiving;
	bool tombstone;

	DisEntry(string, string, string, string, string, string, string);
	DisEntry();
};

class DisHashTable
{
public:
	DisHashTable();
	vector<DisEntry> data; //stores the data of the table
	LinkedList<DisEntry> list;

	DisEntry SEPERATE(string);

	void INSERT(string, string); //add new table entry
	void SELECT(string, string); //find an entry by population
	void UPDATE(string, string);
	void DELETE(string, string);
	void DISPLAY();
	int key(DisEntry); //Direct hashing using the length of Geo
};