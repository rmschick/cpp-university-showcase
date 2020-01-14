#include "DunnIndex.h"

DunnIndex::DunnIndex() {		//default constructor
	MaxIntra = 0;
	MinInter = 10000000;
}

double DunnIndex::getMaxIntra()	//returns MaxIntra
{
	return MaxIntra;
}

double DunnIndex::getMinInter()	//returns MinInter
{	
	return MinInter;
}

double DunnIndex::calcDunnIndex(vector<KCluster> clust, int trial)	//calls InterCLuster and Intra Cluster to return the Dunn Index of a group of Clusters
{	
	double inter = getInterCluster(clust, trial);
	double intra = getIntraCluster(clust, trial);
	double DI = (inter / intra);		//calculate the dunn index
	KDunn.insert({ trial, DI });		//making a map that uses the trial number as the key and the dunn index as the element
	return DI;
	
}

double DunnIndex::getInterCluster(vector<KCluster> group, int trial)	//Finds the smallest distance between two clusters 
{
	MinInter = 10000000;			//Initialize all variables used in function outside of forloop
	double CurX = 0;
	double CurY = 0;
	double CompX = 0;
	double CompY = 0;
	double result = 0;
	for (int i = 0; i < group.size(); i++)
	{
		for (int j = 0; j < group[i].getNumPoints(); j++)
		{
			if (group[i].getNumPoints() > 1) {		//check if the number of points  in a cluster is greater than 1
				for (int k = i + 1; k < group.size(); k++)
				{
					for (int z = 0; z < group[k].getNumPoints(); z++)	//loops through one cluster and all its points and compares it to every other point in every cluster
					{
						CurX = group[i].getPointX(j);
						CurY = group[i].getPointY(j);
						CompX = group[k].getPointX(z);
						CompY = group[k].getPointY(z);
						result = (pow((CompX - CurX), 2) + (pow((CompY - CurY), 2)));
						result = sqrt(result);
						if (result < MinInter) //if the distnace is shorter than the current stored distance, then set the MinInter to the shorter distance
							MinInter = result;
					}
				}
			}
			else
				break;
		}
	}
	return MinInter; //returns the shortest distance between clusters
}

double DunnIndex::getIntraCluster(vector<KCluster> group, int trial)	//Finds the largest distance inside a single cluster out of a group of clusters
{
	MaxIntra = 0;			//initialize all variables used outside of the for loop
	double CurX = 0;
	double CurY = 0;
	double CompX = 0;
	double CompY = 0;
	double result = 0;
	for(int i= 0; i<group.size(); i++)
	{
		for(int j = 0; j <group[i].getNumPoints(); j++)
		{
			if (group[i].getNumPoints() > 1)	//check if the number of points  in a cluster is greater than 1
			{
				for (int k = j + 1; k < group[i].getNumPoints(); k++)	//loops through a single cluster and compares all the points to find the largest distance
				{
					CurX = group[i].getPointX(j);
					CurY = group[i].getPointY(j);
					CompX = group[i].getPointX(k);
					CompY = group[i].getPointY(k);
					result = (pow((CompX - CurX), 2) + (pow((CompY - CurY), 2)));
					result = sqrt(result);
					if (result > MaxIntra)
						MaxIntra = result;
				}
			}
			else
				break;
		}
	}
	return MaxIntra;		//returns the largest distance 
}

void DunnIndex::printAnalysis()		//prints final output that displays highest dunn index
{
	map<int, double>::iterator itr;
	int trial = KDunn.begin()->first;		//initialize the first comparios
	double dunn = KDunn.begin()->second;
	for (itr = KDunn.begin(); itr != KDunn.end(); ++itr) {
		if (dunn < itr->second)		//compare the current max dunn index to the next trial dunn index
		{
			trial = itr->first;
			dunn = itr->second;
		}
	}
	cout << "The final analysis shows that:\n" <<
		"For k-means, a k value of " << trial << " had the highest Dunn index of " << dunn << endl;		//final output 
}
