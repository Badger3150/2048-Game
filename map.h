#pragma once
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <conio.h>

#include "windows.h"

#define ROW 4
#define COL 4

using namespace std;



class Map {
private:
    int gameArr[ROW][COL];
    int highestNum = 4;
    map<int, int> findColor = {{2, 14}, {4, 2}, {6, 3}, {8, 4}, {16, 5},
                                {32, 6}, {64, 7}, {128, 8}, {256, 9},
                                {512, 10}, {1024, 11}, {2048, 12}};
public:
    Map();
    int score;
    bool moveOnce = true;
    void printColor(int num);
    void showMap();
    void gameTip();
    void showScroe();
    bool hasSpace();
    void generateNewNum();
    bool winGame();
    void moveleft();
    void moveUp();
    void moveRight();
    void moveDown();
};
