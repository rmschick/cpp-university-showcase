//This is the function definition file for k-means

#include "k-means.h"

//helper functions
double getDistance(Points, KCluster);
double getDistance(Points, Points);
void updateXY(const vector<Points>&, vector<KCluster>&);

//main k-means clustering function
void kmeans(vector<Points> &points, const vector<vector<int>>& startPoints, int maxK, int minK)
{
    //Declare variables
    vector<KCluster> clusters; //stores clusters for current trial
    Points *closest;           //temporarily stores the closest point to a centroid
    bool changed;              //condition variable for a while loop
    int trialNum = -1;         //keeps track of current trial number
    DunnIndex dunn;            //object to call dunn index function with

    //Main loop
    for (int k = minK; k <= maxK; k++)
    {
        changed = true;
        trialNum++; //new trial

        //Populate clusters vector
        clusters.clear();   //clear results from previous trial
        for (int clustNum = 0; clustNum < k; clustNum++)
            clusters.push_back(KCluster(clustNum, points[startPoints[trialNum][clustNum] - 1])); //add new cluster

        //Clustering loop
        while(changed) //loop until no point is reassigned
        {
            changed = false;
            for (auto &point : points) //go through every point
            {
                for (const auto &cluster : clusters) //go through every cluster
                {
                    //assign point to a cluster if it is closer to it than its current assinged cluster
                    if (point.getAssigned() != cluster.getClusterID() && getDistance(point, clusters[point.getAssigned()]) > 
                        getDistance(point, cluster))
                    {
                        point.setAssigned(cluster.getClusterID()); //update point assignment
                        changed = true;     //point got reassigned, repeat while loop
                    }
                    //in case of a tie, assign point to the cluster with the smaller ID
                    else if (point.getAssigned() != cluster.getClusterID() && getDistance(point, clusters[point.getAssigned()]) == 
                        getDistance(point, cluster) && point.getAssigned() > cluster.getClusterID())
                    {
                        point.setAssigned(cluster.getClusterID());
                        changed = true;
                    }
                }
            }
            updateXY(points, clusters); //update all of the clusters' centroids
        }

        //Populate the assigned points vector for each cluster
        for (auto &point : points)
            clusters[point.getAssigned()].addAssignedPoint(&point); //push point address to corresponding cluster

        //Calculate closest point to the centroid of each cluster
        for (auto &cluster : clusters)
        {
            closest = cluster.getAssignedPoints()[0]; //initialize the closest point
            for (const auto &point : cluster.getAssignedPoints())
            {
                if (getDistance(*point, cluster) < getDistance(*closest, cluster))
                    closest = point;    //found a closer point
            }
            cluster.setClosestPoint(closest->getID()); //store the closest point's ID
        }

        //Output results for trial
        if (trialNum == 0)
            cout << endl << "For k-means clustering: " << endl; //print heading

        cout << "For a k value of " << k << ", here is the information regarding its clusters: " << endl;
        for (const auto &cluster : clusters)
            cout << "Cluster " << cluster.getClusterID() + 1 << " contains " << cluster.getNumPoints()
                << " points and the point " << cluster.getClosestPoint() << " is the closest to its centroid." << endl;
        cout << "The Dunn index for a k of " << k << " is " << dunn.calcDunnIndex(clusters, k) << endl; //output dunn value

        if (k == maxK) //if on last trial...
            cout << endl;
    }
    //Print final dunn analysis
    dunn.printAnalysis();
}

//finds the distance between a point and a centroid using Euclidean distance
double getDistance(Points point, KCluster cluster)
{
    return sqrt(pow(point.getX() - cluster.getCentroidX(), 2) + pow(point.getY() - cluster.getCentroidY(), 2));
}

//calculates new centroid x and y positions based on changes in point assignment
void updateXY(const vector<Points> &points, vector<KCluster> &clusters)
{
    double avgX, avgY;  //stores average x and y values
    int numAssigned;    //stores number of points that are assigned to a cluster

    for (auto &cluster : clusters)
    {
        avgX = 0;
        avgY = 0;
        numAssigned = 0;
        for (const auto &point : points)
        {
            //add up all points' x and y values that are assigned to the cluster
            if (point.getAssigned() == cluster.getClusterID())
            {
                avgX += point.getX();
                avgY += point.getY();
                numAssigned++;
            }
        }
        //find average x and y
        avgX /= numAssigned;
        avgY /= numAssigned;
        cluster.setXY(avgX, avgY); //store new positions
    }
}