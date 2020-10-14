#include "snake.h"

SnakeSequence::SnakeSequence()
{
    findSnakeSequence();
    output();
} 

void SnakeSequence::findPath() 
{ 
    Point point = {maxRow, maxCol}; 
    path.push_front(point); 
  
    while (lookup[maxRow][maxCol] != 0) 
    { 
        if(checkRow())
            maxRow--; 
        else if(checkCol())
            maxCol--;
    } 
} 

bool SnakeSequence::checkRow()
{
    if (maxRow > 0 && lookup[maxRow][maxCol] - 1 == lookup[maxRow - 1][maxCol]) 
    { 
        Point point = {maxRow - 1, maxCol}; 
        path.push_front(point); 
        return true;
    } 
    return false;
}

bool SnakeSequence::checkCol()
{
    if (maxCol > 0 && lookup[maxRow][maxCol] - 1 == lookup[maxRow][maxCol - 1]) 
    { 
        Point point = {maxRow, maxCol - 1}; 
        path.push_front(point); 
        return true;
    } 
    return false;
}

void SnakeSequence::findSnakeSequence()
{
    for (int i = 0; i < ROWSIZE; i++) 
    { 
        for (int j = 0; j < COLSIZE; j++) 
        { 
            if (i || j) // do except for (0, 0) cell 
            { 
                lookAbove(i,j);
                lookLeft(i,j); 
            } 
        } 
    } 
} 

void SnakeSequence::lookAbove(int i, int j)
{
    if (i > 0 && abs(mat[i - 1][j] - mat[i][j]) == 1) 
    { 
        lookup[i][j] = max(lookup[i][j], lookup[i - 1][j] + 1); 
        if (maxLen < lookup[i][j]) 
        { 
            maxLen = lookup[i][j]; 
            maxRow = i, maxCol = j; 
        } 
    } 
}

void SnakeSequence::lookLeft(int i, int j)
{
    if (j > 0 && abs(mat[i][j - 1] - mat[i][j]) == 1) 
    { 
        lookup[i][j] = max(lookup[i][j], lookup[i][j - 1] + 1); 
        if (maxLen < lookup[i][j]) 
        { 
            maxLen = lookup[i][j]; 
            maxRow = i, maxCol = j; 
        } 
    } 
}


void SnakeSequence::output()
{ 
    cout << "Maximum length of Snake sequence is: "
         << maxLen << endl; 

    findPath(); 

    cout << "Snake sequence is:"; 
    for (auto it = path.begin(); it != path.end(); it++) 
        cout << endl << mat[it->x][it->y] << " ("
             << it->x << ", " << it->y << ")" ; 
}
