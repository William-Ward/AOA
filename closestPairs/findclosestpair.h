#ifndef FINDCLOSESTPAIR_H
#define FINDCLOSESTPAIR_H
#include <limits>
#include <math.h>
#include <vector>
#include <algorithm>
#include "point.h"

using namespace std;

class Point
{ 
    public:
        int x, y; 
};

bool compareXcoord(Point, Point);
bool compareYcoord(Point, Point);

class FindClosestPair
{
    private: 
        vector<Point> points; 
        double infinity = numeric_limits<double>::max();
        double minDistance = infinity;
    public:
        FindClosestPair();
        FindClosestPair(vector<Point>);
        double getMinDistance();
        vector<Point> getMergeList(vector<Point> left, vector<Point> right, Point mid, double min);
        double getMinAcrossSplit(vector<Point> left, vector<Point> right, double min);
        bool inWindow(Point top, Point bottom, double min);
        double min(double left, double right);
        double distance(Point left, Point right);
        double getClosestPair(vector<Point> pointsSubset);
        vector<Point> getLeftVector(vector<Point> pointsSubset);
        vector<Point> getRightVector(vector<Point> pointsSubset);
        void sortPoints();

};
#endif
