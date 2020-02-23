#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "docStorage.h"
using namespace std;

void docStorage::storeDocs(vector<docStorage> &docVector)	//function that stores every document
{
	bool run = false;
	char filename[20];	//dont think using a string for file name works
	ifstream inFile;
	while (!run)	//Code I used from 1030 that makes sure the correct file is entered
	{

		cout << "Enter the document name:" << endl;
		cin.getline(filename, 20);	//getting the name of the file from user
		inFile.open(filename);	//opening file
		if (inFile.fail())
		{
			cout << "Document can not be opened." << endl;

		}
		else
		{
			run = true;
		}
	}
	string word = "";
	string str;
	inFile >> str;
	docStorage *temp = new docStorage(ID, Title, Author, Abstract);	//creates temporary object to push into vector

		while (!inFile.eof())
		{	
			if (str == ".I")//Uses .I to switch to using ID vector
			{
				inFile >> str;
				while (str != ".T")//uses word to store ID number into the vector
				{
					for (auto x : str)//gets ID number by combining each number
					{
						word = word + x;

					}
					inFile >> str;
				}
				temp->ID.push_back(word);//Inserts the ID into the vector
				word = "";	//sets word back to null
				if (str == ".T")	//Uses .T to switch to using Title vector
				{
					inFile >> str;
					while (str != ".A" && !inFile.eof()) //adds word to itself to build the sentences one word at a time
					{

						temp->Title.push_back(str);//Inserts the Abstract into the vector
						inFile >> str;

					}
					temp->Title.push_back(word);//Inserts the Title into the vector
					word = "";//sets word back to null
					if (str == ".A")	//Uses .A to switch to using Author vector
					{
						inFile >> str;
						while (str != ".W")//adds word to itself to build the sentences one word at a time
						{
							for (auto x : str)//stores each letter into word and combines them to create 1 word
							{
								word = word + x;

							}
							word = word + " ";//adds spaces in between each word
							inFile >> str;
						}
						temp->Author.push_back(word);//Inserts the Author into the vector
						word = "";//sets word back to null
						if (str == ".W")//Uses .W to switch to using Abstract vector
						{
							inFile >> str;
							while (str != ".I" && !inFile.eof()) //adds word to itself to build the sentences one word at a time
							{
								
								temp->Abstract.push_back(str);//Inserts the Abstract into the vector
								inFile >> str;
								
							}
							
							word = "";//sets word back to null
						}
					}
				}
			}
			docVector.push_back(*temp);	//inserting all info for temp into vector
			temp = new docStorage(ID, Title, Author, Abstract);	//resets temp
		}
		inFile.close();	//closing file
}

void docStorage::stopWordDocs(vector<string> &Stopwords)//inputs the stopwords into a vector
{
	bool run = false;
	char filename[20];
	ifstream inFile;
	while (!run)	//Code I used from 1030 that makes sure the correct file is entered
	{
		cout << "Enter the stopword document name:" << endl;
		cin.getline(filename, 20);	//getting the name of the file from user
		inFile.open(filename);	//opening file
		if (inFile.fail())
		{
			cout << "Document can not be opened." << endl;

		}
		else
		{
			run = true;
		}
	}
	string str;
	while (!inFile.eof())
	{
		inFile >> str;	//reads in each word
		Stopwords.push_back(str);	//inserts each word into the Stopwords vector
	}
	inFile.close();	//closing file
	cout << endl;
}
void docStorage::printStopWords(vector<string> &Stopwords)	//function that prints out the list of stopwords and the # of stopwords in the stopwords file. The list is not necessary but there for testing purposes
{
	int i = 0;
	cout << endl<<endl;	//formatting
	for (i; i < Stopwords.size(); ++i)
	{
		//cout<<Stopwords[i];	//prints out the list of stopwords if necessary
	}
	cout << "There are currently " << i-1 << " known stopwords." << endl;	//outputs the # of stopwords
	cout << endl;
}

void docStorage::printDocs(vector<docStorage> docVector)//prints out all the documents
{
		for (int j = 0; j < docVector[0].ID.size(); ++j)
		{
			cout <<"ID: "<< docVector[0].ID[j];	//outputs the ID
		}
		cout << " Title: ";
		for (int j = 0; j < docVector[0].Title.size(); ++j)
		{
			cout << docVector[0].Title[j]<< " ";	//outputs the Title
		}
		cout << endl;
		for (int j = 0; j < docVector[0].Author.size(); ++j)
		{
			cout <<" Author: "<< docVector[0].Author[j];	//outputs the Author
		}
		cout << endl << "  ";
		for (int j = 0; j < docVector[0].Abstract.size(); ++j)
		{
			cout << docVector[0].Abstract[j]<<" ";	//outputs the Abstract
		}
}

void docStorage::vectorCompare(vector<string> &Stopwords, vector<string> &Abstract)	//function that removes the stopwords from the abstract
{
	for (int i = 0; i < Abstract.size(); ++i)
	{
		for (int j = 0; j < Stopwords.size(); ++j)
		{
			if (Abstract[i] == Stopwords[j])	//checks if the abstract word matches any stopwords
			{
				Abstract.erase(Abstract.begin() + i);	//deletes the stopword from the abstract
			}

		}
	}
}

void docStorage::remPunct(vector<string> &Abstract)	//function that removes punctuation from the abstract
{

	for (int i = 0; i < Abstract.size(); i++)
	{
		string str = Abstract[i]; //sets str to the abstract

		for (int j = 0, len = str.size(); j < len; j++)
		{
			if (ispunct(str[j]) && str[j] != '-' || (str[j] >= 47 && str[j] <= 58))// checks whether parsing character is punctuation or not 
			{
				str.erase(j--, 1);//erases punctuation
				len = str.size();
			}
		}
		if (str == "-")//if str is just a hyphen
			str = "";//set to empty string

		Abstract[i] = str;	//sets abstract to the modified string
			
	}
}

void docStorage::remTitle(vector<string>& Abstract, vector<string>& Title)	//function that removes the title from the abstract
{
	for (int i = 0; i < Title.size()-1; ++i)
	{
		Abstract.erase(Abstract.begin());	//erases the title from the abstract
	}
}