#include "DataStorage.h"


dataStorage::dataStorage()//constructor
{
}

Points::Points()//constructor
{
}
Points::Points(int id, float x, float y, int assign)	//constructor
{
	ID = id; X = x; Y = y; assigned = assign;
}

int Points::getID() const { return ID; }	//get functions
float Points::getX() const { return X; }
float Points::getY() const { return Y; }
int Points::getAssigned() const { return assigned; }

void Points::setID(int id) { ID = id; }	//set functions
void Points::setX(float x) { X = x; }
void Points::setY(float y) { Y = y; }
void Points::setAssigned(int assign) { assigned = assign; }

void Points::inputPoints(vector<Points>& pointVector,string pointsfile)	//inputs the points into the points vector
{
	ifstream inFile;
	inFile.open(pointsfile);	//opens file
	int id;	//declares temp variables
	float x;
	float y;
	int i = 0;
	Points *temp= new Points(ID, X, Y,0); //assigns *temp as an object of Points class
	while (!inFile.eof())
	{
			inFile >> id;
			temp->setID(id);	//sets id to the Points object
			inFile >> x;
			temp->setX(x);		//sets X value to the Points object
			inFile >> y;
			temp->setY(y);		//sets Y value to the Points object
			pointVector.push_back(*temp);	//pushes back the temp object to the point vector
			++i;
			
	}
	pointVector.pop_back();
	/*for (int i = 0; i < pointVector.size(); ++i) {
		cout << pointVector[i].ID;
		cout << " " << pointVector[i].X;
		cout << " " << pointVector[i].Y;
		cout << endl;
	}*/
	
}

string dataStorage::inputFile(vector<vector<int>> &startPoint,int &kmin,int &kmax) 	//function that inputs the config file with kmeans max and min, and
{
	bool run = false;
	char config[20];	
	string pointsfile;
	ifstream inFile;
	while (!run)
	{
		cout << "Please enter the name of the configuration file:" << endl;
		cin.getline(config, 20);	//getting the name of the file from user
		inFile.open(config);//"config1.txt");	//opening file
		if (inFile.fail())	//checks if the file was able to open
		{
			cout << "Config file not found. Please try again" << endl;
		}
		else
		{
			run = true;
		}
	}
	inFile >> pointsfile;	//reads in the points file name
	for (int i = 0; i < 6; ++i)
	{
		pointsfile.erase(pointsfile.begin());	//erases unnecessary beginning of filename
	}

	string kMeanMin;
	string kMeanMax;
	string temp;
	getline(inFile, temp);	//reads in blank space
	getline(inFile,kMeanMin);	//reads in the kmeanmin
	getline(inFile, kMeanMax);	//reads in the kmeanmax
	dataStorage::extractIntWords(kMeanMin);	//extracts the number from the string
	dataStorage::extractIntWords(kMeanMax);
	stringstream g(kMeanMin);	//converts kmeanmin to an int
	stringstream h(kMeanMax);
	g >> kmin;	//assigns the int value to kmin
	h >> kmax;	//assigns the int value to kmax
	int i = -1;
	while (!inFile.eof())	//unable to put in seperate function.
	{
		string num;
		int passVar;
		inFile >> num;
		if (num.length() >= 1 && num[num.length() - 1] == ':')	//checks if there is a colon in the string
		{
			++i;
			startPoint.resize(i + 1);	//resizes the vector
		}
		else	//if there is no colon...
		{
			stringstream g(num);
			g >> passVar;
			//cout << passVar << endl;
			startPoint[i].push_back(passVar);	//pushback the number into the vector
		}
	}
	startPoint[i].pop_back();//popback last repeating value in vector
	inFile.close();	//closes config 
	return pointsfile;	//returns the pointsfile name
}

void dataStorage::extractIntWords(string &str)	//extracts the numbers from the string
{
	string num;
	for (int i = 0; i < str.size(); ++i)
	{
		if (isdigit(str[i]))	//if there is a digit in the string, it adds it to the num var
		{
			num += str[i];
		}
	}
	str = num;
}