#include "findclosestpair.h"
#include "testdir/catch.hpp"

TEST_CASE("getClosestPair")
{
    vector<Point> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    FindClosestPair find;
    CHECK(find.getClosestPair(points) > 0);
}

TEST_CASE("getMinAcrossSplit")
{
    vector<Point> left  = {{1,1},{2, 3}, {12, 30}};
    vector<Point> right = {{4,2},{5, 4}, {12, 30}};
    FindClosestPair find;
    double min = 3;
    min = find.getMinAcrossSplit(left,right,min);
    CHECK(min == 3);
}

TEST_CASE("getMergeList")
{
    vector<Point> left  = {{1,1},{2, 3}, {12, 30}};
    vector<Point> right = {{4,2},{5, 4}, {12, 30}};
    Point mid = {3,6};
    FindClosestPair find;
    vector<Point> merged = find.getMergeList(left, right,mid, 3);
    CHECK(merged.size() == 4);
    CHECK(merged.at(0).x == 1);
    CHECK(merged.at(1).x == 2);
    CHECK(merged.at(2).x == 4);
    CHECK(merged.at(3).x == 5);
}

TEST_CASE("inWindow")
{
    Point top = {1,20}, bottom = {1,1};
    FindClosestPair find;
    CHECK(find.inWindow(top, bottom, 3) == false);
    CHECK(find.inWindow(bottom, top, 3) == false); 
}

TEST_CASE("get left and right vector")
{
    vector<Point> points = {{1,1},{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    FindClosestPair find;
    vector<Point> left = find.getLeftVector(points);
    vector<Point> right = find.getRightVector(points);
    CHECK(int(points.size()) == 7);
    CHECK(int(right.size()) == 4);
    CHECK(int(left.size()) == 3);
}

TEST_CASE("compare y")
{
    Point p1 = {1,10}, p2 = {10,1};
    FindClosestPair find;
    CHECK(compareYcoord(p1,p2) == false);
    CHECK(compareYcoord(p2,p1) == true);
}

TEST_CASE("compare x")
{
    Point p1 = {1,10}, p2 = {10,1};
    FindClosestPair find;
    CHECK(compareXcoord(p1,p2) == true);
    CHECK(compareXcoord(p2,p1) == false);
}

TEST_CASE("min")
{
    FindClosestPair find;
    CHECK(find.min(2,3) == 2);
    CHECK(find.min(3,2) == 2);
}

TEST_CASE("constructor")
{
    vector<Point> points = {{2, 3}, {12, 30}};
    FindClosestPair findPair(points);
}

TEST_CASE("distance")
{
    Point p1 = {1,1}, p2 = {2,2}, p3 = {3,3};
    FindClosestPair find;
    CHECK(find.distance(p1,p2) == sqrt(2));
    CHECK(find.distance(p2,p1) == sqrt(2));
    CHECK(find.distance(p1,p3) == sqrt(8));
}
