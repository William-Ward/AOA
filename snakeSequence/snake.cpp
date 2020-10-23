#include "snake.h"

SnakeSequence::SnakeSequence()
{
    findSnakeSequence();
    findPath(); 
    output();
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
        lookuptable.setMaxAbove(row, col); 
        saveMaxValues(row, col);
    } 
}

void SnakeSequence::lookLeft(int row, int col)
{
    if (snakefloor.canStepLeft(row,col)) 
    { 
        lookuptable.setMaxLeft(row, col);
        saveMaxValues(row, col);
    } 
} 

void SnakeSequence::saveMaxValues(int row, int col)
{
    if (maxLen < lookuptable.at(row,col)) 
    { 
        maxLen = lookuptable.at(row,col); 
        maxRow = row;
        maxCol = col; 
    } 
}

void SnakeSequence::findPath() 
{ 
    Point point = {maxRow, maxCol}; 
    path.push_front(point); 
  
    while (lookuptable.at(maxRow,maxCol) != 0) 
    { 
        if(checkRow())
            maxRow--; 
        else if(checkCol())
            maxCol--;
    } 
} 

bool SnakeSequence::checkRow()
{
    if (maxRow > 0 && lookuptable.at(maxRow,maxCol) - 1 ==  lookuptable.at(maxRow-1,maxCol) ) 
    { 
        Point point = {maxRow - 1, maxCol}; 
        path.push_front(point); 
        return true;
    } 
    return false;
}

bool SnakeSequence::checkCol()
{
    if (maxCol > 0 && lookuptable.at(maxRow,maxCol) - 1 ==  lookuptable.at(maxRow,maxCol-1)) 
    { 
        Point point = {maxRow, maxCol - 1}; 
        path.push_front(point); 
        return true;
    } 
    return false;
}


void SnakeSequence::output()
{ 
    cout << "Maximum length of Snake sequence is: "
         << maxLen << endl; 

    cout << "Snake sequence is:"; 
    for (auto it = path.begin(); it != path.end(); it++) 
        cout << endl << snakefloor.at(it->x, it->y) << " ("
             << it->x << ", " << it->y << ")" ; 
    cout << "\n";
}
