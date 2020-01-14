#pragma once
#include "linked_list.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

class AgeEntry
{
public:
	string ID;
	string child; //key value
	string teen;
	string elder;
	bool tombstone;

	AgeEntry(string, string, string, string);
	AgeEntry();
};

class AgeHashTable
{
public:
	AgeHashTable();
	vector<vector<AgeEntry>> data; //stores the data of the table
	
	LinkedList<AgeEntry> list;

	AgeEntry SEPERATE(string);
	void INSERT(string, string); //add new table AgeEntry
	void SELECT(string, string); //find an AgeEntry by population
	void UPDATE(string, string);
	void DELETE(string, string);
	void DISPLAY();
	int key(AgeEntry);	//modulo Hashing
};