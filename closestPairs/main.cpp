#include <iostream>
#include "findclosestpair.h"

int main()
{
    //vector<Point> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    vector<Point> points = {{2, 3}, {12, 30}};
    FindClosestPair findPair(points);
    cout << "The minimum distance is "<< findPair.getMinDistance() << "\n";

    return 0;
}
