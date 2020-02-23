#pragma once
//header file for reading in, parsing, processing, and storing the Query 
//Ryan Schick
//9/16/2019
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <map>
#include <algorithm>
#include <iterator>
#include <vector>
#include <iomanip>
using namespace std;

class Query {
private: 
	string query;
public:
	vector<string> Que;
	void setQue();		//asks user for query and stores it
	void toAllLowerCase(); // convert query to lower case			   
	
};