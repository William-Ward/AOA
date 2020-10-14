#include "findclosestpair.h"

FindClosestPair::FindClosestPair(){}
FindClosestPair::FindClosestPair(vector<Point> p)
{
    points = p;
    sortPoints();
    getClosestPair(points);
}

double FindClosestPair::getClosestPair(vector<Point> pointsSubset)
{
    int size = int(pointsSubset.size());

    if(size == 1)
        return infinity;
    if(size == 2)
        return distance(pointsSubset.at(0), pointsSubset.at(1));

    vector<Point> left = getLeftVector(pointsSubset);
    vector<Point> right = getLeftVector(pointsSubset);

    double minDistanceLeft = getClosestPair(left);
    double minDistanceRight = getClosestPair(right);

    minDistance = min(minDistanceLeft,minDistanceRight);
    minDistance = min(minDistance, getMinAcrossSplit(left, right, minDistance));

    return minDistance;
}

double FindClosestPair::
getMinAcrossSplit(vector<Point> left, vector<Point> right, double min)
{
    Point mid = right.at(0);
    right.erase(right.begin());
    vector<Point> mergeList = getMergeList(left, right, mid, min);
    int size = int(mergeList.size());

    sort(mergeList.begin(), mergeList.end(), compareYcoord);

    for(int i = 0; i < size; i++)
        for(int j = i+1; j < size && inWindow(mergeList.at(j), mergeList.at(i),min); j++)
            if(distance(mergeList.at(j),mergeList.at(i)) < min)
                min = distance(mergeList.at(j),mergeList.at(i));

    return min;
}

bool FindClosestPair::inWindow(Point top, Point bottom, double min)
{
    return fabs(top.y - bottom.y) < min;
}

vector<Point> FindClosestPair::
getMergeList(vector<Point> left, vector<Point> right, Point mid, double min)
{ 
    vector<Point> mergeList;

    for(Point p : left)
        if(fabs(p.x - mid.x) < min)
            mergeList.push_back(p);

    for(Point p : right)
        if(fabs(p.x - mid.x) < min)
            mergeList.push_back(p);

    return mergeList; 
}

vector<Point> FindClosestPair::
getLeftVector(vector<Point> pointsSubset)
{
    int size = int(pointsSubset.size());
    vector<Point> left = pointsSubset;
    left.erase(left.begin()+size/2, left.end());
    return left;
}

vector<Point> FindClosestPair::getRightVector(vector<Point> pointsSubset)
{
    int size = int(pointsSubset.size());
    vector<Point> right = pointsSubset;
    right.erase(right.begin(), right.begin()+size/2);
    return right;
}

double FindClosestPair::min(double left, double right)
{
    if(left < right)
        return left;
    return right;
}

double FindClosestPair::distance(Point left, Point right)
{
    return sqrt(pow(left.x-right.x,2)+pow(left.y-right.y,2));
}

void FindClosestPair::sortPoints()
{
    sort(points.begin(), points.end(), compareXcoord);
}

bool compareXcoord(Point left, Point right) { return (left.x < right.x); } 
bool compareYcoord(Point left, Point right) { return (left.y < right.y); }
double FindClosestPair::getMinDistance() { return minDistance; }
