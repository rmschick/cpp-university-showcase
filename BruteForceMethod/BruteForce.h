#pragma once

#include <string>
#include <iostream>

using namespace std;

int high;

struct bruteTree
{
	
	bruteTree* point[27];	//declaring vars
	int head;
	int end;
	

	bruteTree(int a, int b)		
	{
		for (int i = 0; i < 27; ++i)	//populating struct
		{
			point[i] = NULL;
		}
		head = a;		//first int sent to head
		end = b;		//second int sent to end
	}
}*RootValue = NULL;

//fuction bruteForceBruteTree pass a string, tree and int as parameters
bruteTree* bruteForceBruteTree(bruteTree* Tree, string T, int ind)
{
	int s = Tree->head; //create a suffix and assign head
	while (s<=Tree->end&&T.at(s)==T.at(ind)) // compare suffiz and text values
	{
		s++;
		ind++;
	}
	//check suffix of the entire label matches the edge end
	if (s <= Tree->end)
	{
		Tree->point[T.at(ind) - 'a'] = new bruteTree(ind, high);
		if (T.at(s) == '$') //if suffix is a symbol then conclude the process
			Tree->point[26] = new bruteTree(s, Tree->end);
		else //suffix considered as alphabet
			Tree->point[T.at(s) - 'a'] = new bruteTree(s, Tree->end);
		Tree->end = s - 1;
		return Tree;
	}
	else
	{
		//matches the suffix which points to the text
		if (Tree->point[T.at(ind) - 'a'])
		{
			Tree->point[T.at(ind) - 'a'] = bruteForceBruteTree(Tree->point[T.at(ind) - 'a'], T, ind);
			return Tree;
		}
		else
		{
			Tree->point[T.at(ind) - 'a'] = new bruteTree(ind, high);
			return Tree;
		}
	}
}

//create a function to build the bruteTree
bruteTree* Build(bruteTree* RootValue, string T, int ind)
{
	if (!RootValue)
	{
		RootValue = new bruteTree(ind, high);
		return RootValue;
	}
	//checks for the symbol and assigns this at the end of the last node
	if (T.at(ind) == '$')
	{
		RootValue->point[26] = new bruteTree(ind, high);
		return RootValue;
	}
	if (!RootValue->point[T.at(ind) - 'a'])
	{
		RootValue->point[T.at(ind) - 'a'] = new bruteTree(ind, high);
		return RootValue;
	}
	RootValue->point[T.at(ind) - 'a'] = bruteForceBruteTree(RootValue->point[T.at(ind) - 'a'], T, ind);
	return RootValue;
}

void DisplayBruteForceBruteTree(bruteTree* RootValue, string T)
{
	//check rootValue
	if (!RootValue)
		return;
	if (RootValue->head != -1)
	{
		for (int i = RootValue->head; i<= RootValue->end; i++)
		{
			cout << T.at(i);
		}
		cout << "\n";
	}
	for (int i = 0; i < 27; i++)
	{
		DisplayBruteForceBruteTree(RootValue->point[i], T);
	}
}