//This is the function definition file for the KCluster class

#include "KCluster.h"

//constructor for KCluster
KCluster::KCluster(int setID, Points startPoint)
{
    ID = setID;
    centroidX = startPoint.getX();
    centroidY = startPoint.getY();
}

//set new centroid x and y
void KCluster::setXY(double newX, double newY)
{
    centroidX = newX;
    centroidY = newY;
}

//set closest point
void KCluster::setClosestPoint(int pointID)
{
    closestPoint = pointID;
}

//add a point to the assigned points vector
void KCluster::addAssignedPoint(Points *pointAddress)
{
    assignedPoints.push_back(pointAddress);
}

//gets the assigned points address vector
vector<Points*> KCluster::getAssignedPoints() const
{
    return assignedPoints;
}

//gets the ID of the closest point
int KCluster::getClosestPoint() const
{
    return closestPoint;
}

//get the number of points assinged to the cluster
int KCluster::getNumPoints() const
{
    return assignedPoints.size();
}

//get the ID of a cluster
int KCluster::getClusterID() const
{
    return ID;
}

//get individual point's x value
double KCluster::getPointX(int i) const
{
    return assignedPoints[i]->getX();
}

//get individual point's y value
double KCluster::getPointY(int i) const
{
    return assignedPoints[i]->getY();
}

//get cluster centroid's x value
double KCluster::getCentroidX() const
{
    return centroidX;
}

//get cluster centroid's y value
double KCluster::getCentroidY() const
{
    return centroidY;
}