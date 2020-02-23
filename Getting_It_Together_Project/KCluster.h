//This is the header file for the KCluster class

#include <vector>
#include "DataStorage.h"

using namespace std;

#ifndef KCLUSTER_H
#define KCLUSTER_H

class KCluster
{
    private:
        int ID;                      //stores ID of cluster
        int closestPoint;            //stores closest point to the centroid
        double centroidX, centroidY; //stores the centroid x and y positions
        vector<Points*> assignedPoints; //vector of Point pointers, this will point to the original Points vector from step 1

    public:
        //constructor
        KCluster(int, Points);
        //set functions
        void setXY(double, double);
        void setClosestPoint(int);
        void addAssignedPoint(Points*);
        //get functions
        vector<Points*> getAssignedPoints() const;
        int getClosestPoint() const;
        int getNumPoints() const;
        int getClusterID() const;
        double getPointX(int) const;
        double getPointY(int) const;
        double getCentroidX() const;
        double getCentroidY() const;
};

#endif