#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

void readInputFile(vector<string> &geogVector, vector<string> &ageVector, vector<string> &disabilityVector);	//function that takes in all everything from the input file
void csvFileReader(string File);	//function to output what is in the csv files
void geogStorage(vector<string> &geogVector,string File);	//stores geography data into geography vector
void ageStorage(vector<string> &ageVector, string File);		//stores age data into age vector
void disabilityStorage(vector<string> &disabilityVector, string File);	//stores disability data into vector
void queryReader(string query);		//reads in the query and calls designated functions from designated hash tables
void fileSorter(string File,vector<string> &geogVector, vector<string> &ageVector, vector<string> &disabilityVector);	//sorts files so correct csv filename is stored
string topicSorter(string topic);	//sorts topics so they match the csv filename
void insertAge(vector<string> &ageVector);	//inserts vector into hashtable
void insertGeog(vector<string> &geogVector);	//inserts vector into hashtable
void insertDisability(vector<string> &disabilityVector);	//inserts vector into hashtable