#ifndef MAPREADER_H_INCLUDED
#define MAPREADER_H_INCLUDED

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <curses.h>
#include <vector>
#include "GameConfig.h"
#include "Mouse.h"
#include "GameObject.h"
#include "Cat.h"

using namespace std;




class MapReader
{
public:
    MapReader();
    ~MapReader();

    void testPrint(Cat*, Mouse*);

    void PrintWindow(int,int);


    bool ReadMap(string, Cat*, Mouse*);
    vector <vector <int> > floorMap;

    //Need functions to return mapWidth/Height

    int atPosition(int,int);//(y,x) like all of curse
    void setPosition(int,int, int);
    int getMapWidth();
    int getMapHeight();

    int getNumSimulations();

    WINDOW* getMapReader();

private:
    WINDOW *mapWindow;
    int mapWidth;
    int mapHeight;
    std::string mapTitle;

    int numSimulations;
    bool mapIsRead;

};

#endif // MAPREADER_H_INCLUDED
