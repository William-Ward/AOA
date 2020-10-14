#include "snake.h"

SnakeSequence::SnakeSequence()
{
    findSnakeSequence();
    findPath(); 
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
    for (int row = 0; row < ROWSIZE; row++) 
    { 
        for (int col = 0; col < COLSIZE; col++) 
        { 
            if (row || col) // do except for (0, 0) cell 
            { 
                lookAbove(row,col);
                lookLeft(row,col); 
            } 
        } 
    } 
} 


void SnakeSequence::lookAbove(int row, int col)
{
    if (snakefloor.canStepAbove(row,col)) 
    { 
        lookup[row][col] = max(lookup[row][col], lookup[row - 1][col] + 1); 
        if (maxLen < lookup[row][col]) 
        { 
            maxLen = lookup[row][col]; 
            maxRow = row, maxCol = col; 
        } 
    } 
}

void SnakeSequence::lookLeft(int row, int col)
{
    if (snakefloor.canStepLeft(row,col)) 
    { 
        lookup[row][col] = max(lookup[row][col], lookup[row][col - 1] + 1); 
        if (maxLen < lookup[row][col]) 
        { 
            maxLen = lookup[row][col]; 
            maxRow = row, maxCol = col; 
        } 
    } 
} 

void SnakeSequence::output()
{ 
    cout << "Maximum length of Snake sequence is: "
         << maxLen << endl; 

    cout << "Snake sequence is:"; 
    for (auto it = path.begin(); it != path.end(); it++) 
        cout << endl << snakefloor.getLocation(it->x, it->y) << " ("
             << it->x << ", " << it->y << ")" ; 
    cout << "\n";
}

bool SnakeFloor::canStepLeft(int row, int col)
{
    return (abs(mat[row][col-1] - mat[row][col]) == 1 && col > 0);
}

bool SnakeFloor::canStepAbove(int row, int col)
{
    return (abs(mat[row-1][col] - mat[row][col]) == 1 && row > 0);
}

int SnakeFloor::getLocation(int row, int col)
{
    return mat[row][col];
}
