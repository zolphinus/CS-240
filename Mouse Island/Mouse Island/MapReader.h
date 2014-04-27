#ifndef MAPREADER_H_INCLUDED
#define MAPREADER_H_INCLUDED

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <curses.h>
#include <vector>
#include "GameConfig.h"

using namespace std;




class MapReader
{
public:
    MapReader(string);
    ~MapReader();



    void PrintWindow(int,int);
    void ReadMap(string);
    vector <vector <int> > floorMap;


    char atPosition(int,int);//(y,x) like all of curse
    void setPosition(int,int, char);
    WINDOW* getMapReader();

private:
    WINDOW *mapWindow;
    int mapWidth;
    int mapHeight;
    std::string mapTitle;
    int numSimulations;

};

#endif // MAPREADER_H_INCLUDED
