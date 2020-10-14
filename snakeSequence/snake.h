#ifndef SNAKE_CPP
#define SNAKE_CPP
#include <iostream>
#include <list>
#include <stdio.h>

using namespace std; 

#define ROWSIZE 4 
#define COLSIZE 4 

struct Point 
{ 
    int x, y; 
}; 

class SnakeSequence
{
    private: 
        int lookup[ROWSIZE][COLSIZE] = {0}; 
        list<Point> path;
        int maxLen = 0, maxRow = 0, maxCol = 0;
        int mat[ROWSIZE][COLSIZE] = 
        { 
            {9, 6, 5, 2}, 
            {8, 7, 6, 5}, 
            {7, 3, 1, 6}, 
            {1, 1, 1, 7}, 
        }; 

    public:
        SnakeSequence();
        void findPath();
        void findSnakeSequence();
        void lookAbove(int i, int j);
        void lookLeft(int i, int j);
        bool checkRow();
        bool checkCol();
        void output(); 
}; 
#endif
