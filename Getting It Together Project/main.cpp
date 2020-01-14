#include "DataStorage.h"
#include "k-means.h"
#include "DunnIndex.h"

using namespace std;

int main()
{
	dataStorage data;	//object of dataStorage
	Points points;	//object of Points
	vector<Points> pointVector;	//creates a vector to store points
	int kmin;
	int kmax;
	string pointsfile;
	vector<vector<int>> startPoint;	//creates double vector for startpoints
	pointsfile=data.inputFile(startPoint,kmin,kmax);//function that inputs the config file
	points.inputPoints(pointVector,pointsfile);//inputs the points into the point vector
	cout << "The total number of k values to be tested is " << startPoint.size() << endl;
	cout << "The total number of points in this file is " << pointVector.size() << endl;

	//call k-means function
	kmeans(pointVector, startPoint, kmax, kmin);

	cout << "Complete!" << endl << endl;

	return 0;
}