#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include <iostream>
#include <vector>
using namespace std;

class Points	
{
private:	//holds private variables
	int ID;
	float X;
	float Y;
	int assigned;
public:
	Points();
	Points(int id, float x, float y, int assign);
	int getID() const;
	float getX() const;
	float getY() const;
	int getAssigned() const;
	void setID(int);
	void setX(float);
	void setY(float);
	void setAssigned(int);
	void inputPoints(vector<Points> &pointVector,string pointsfile);	//inputs the points into the pointVector
};

class dataStorage
{
public:
	dataStorage();
	string inputFile(vector<vector<int>> &startPoint, int &kmin, int &kmax);	//inputs the config file and the kmean values
	void extractIntWords(string &str);	//extracts the numbers from the string
};

