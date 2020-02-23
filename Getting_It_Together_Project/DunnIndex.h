#pragma once
#include "k-means.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iterator> 
#include <map>

using namespace std;

class DunnIndex {
private:
	double interCluster;			//stores Inter KCluster distance
	double intraCluster;			//stores Intra KCluster distance
	double MaxIntra;				//stores Intra Linkage Cluster distance
	double MinInter;				//stores Inter Linkage Cluster distance
	map <int, double> KDunn;		//map for K Cluster to keep track of all trials and Dunn Index
	map <int, double> CLDunn;		//map for Centroid-Linkage to keep track of all trials and Dunn Index
	
public:
	DunnIndex();			//default constructor
	double getMaxIntra();		//return MaxIntra
	double getMinInter();		//return MinInter
	double calcDunnIndex(vector<KCluster>, int);		//returns dunn index
	double getInterCluster(vector<KCluster>, int);		//returns the Maximum distance inside the largest cluster
	double getIntraCluster(vector<KCluster>, int);		//returns the Minimum distance between two clusters
	void printAnalysis();			//prints final output
};