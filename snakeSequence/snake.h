#ifndef SNAKE_H
#define SNAKE_H
#include "snakefloor.h"
#include "lookup.h"
#include <iostream>
#include <list>

using namespace std; 

struct Point 
{ 
    int x, y; 
}; 

class SnakeSequence
{
    private: 
        LookupTable lookuptable;
        list<Point> path;
        int maxLen = 0, maxRow = 0, maxCol = 0;
        SnakeFloor snakefloor;

    public:
        SnakeSequence();
        void findPath();
        void findSnakeSequence();
        void lookAbove(int i, int j);
        void lookLeft(int i, int j);
        bool checkRow();
        bool checkCol();
        void output(); 
        void saveMaxValues(int row, int col);
}; 
#endif
