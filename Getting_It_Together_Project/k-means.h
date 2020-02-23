//This is the header file for k-means

#include <iostream>
#include <vector>
#include <cmath>
#include "DataStorage.h"
#include "KCluster.h"
#include "DunnIndex.h"

using namespace std;

#ifndef KMEANS_H
#define KMEANS_H

//function prototypes
void kmeans(vector<Points>&, const vector<vector<int>>&, int, int);

#endif