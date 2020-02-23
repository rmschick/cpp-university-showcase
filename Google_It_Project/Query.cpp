//class definition file for the Query 
//Ryan Schick
//9/16/2019
#include "Query.h"
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <map>
#include <algorithm>

void Query::setQue()
{
	cout << "Please enter a query to find related documents: ";
	getline(cin,query);		//storing input into private query
	string word = "";
	toAllLowerCase();
	for (auto x : query)	//loop to discard all spaces and add words to Que vector
	{
		if (x == (' '))
		{
			Que.push_back(word);
			word = "";
		}
		else
		{
			word = word + x;
		}
	}
	Que.push_back(word);
	sort(Que.begin(), Que.end()); //sort query in alphabetical order from a-z
}

void Query::toAllLowerCase()	//makes words in query all lowercase
{
	for_each(query.begin(), query.end(), [](char & c) {
		c = tolower(c);
	});
}

