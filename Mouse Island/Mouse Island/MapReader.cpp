#include "MapReader.h"
#include "GameConfig.h"

MapReader::MapReader()
{
    //mapWindow = newwin(MAP_WINDOW_HEIGHT,MAP_WINDOW_WIDTH,0,0);//creates the window


}

MapReader::~MapReader(){
    //delwin(mapWindow);
}

bool MapReader::ReadMap(string FileName, Cat* Tom, Mouse* Jerry)
{
    ifstream mapIn;
    int getFileItem;

    int rowMarker = 0;
    char *cstr = new char[FileName.length()+1];          // converts the string into usable format for opening
    strcpy(cstr, FileName.c_str());
    mapIn.open(cstr);


    if(mapIn.good()){
        mapIn >> mapTitle;
        mapIn >> numSimulations;
        mapIn >> mapHeight;
        mapIn >> mapWidth;

        floorMap.resize(mapHeight);

        for(int i = 0; i < mapHeight; i++)
        {
            floorMap[i].resize(mapWidth);
        }
    }
    else
    {
        return false;
    }

    while (true)
    {

        if (mapIn.good())
        {
            for(int i = 0; i < mapHeight; i++)
            {
                for(int j = 0; j < mapWidth; j++)
                {
                    mapIn >> getFileItem;

                    if(mapIn.fail())
                    {
                        mapIn.clear();
                        mapIn.ignore();
                        getFileItem = 0;
                    }


                    floorMap[i][j] = getFileItem;
                    if(floorMap[i][j] <= -1)
                    {
                        floorMap[i][j] = WATER_SPACE;
                    }

                    if(floorMap[i][j] > 6 )
                    {
                        floorMap[i][j] = LAND_SPACE;
                    }

                    if(floorMap[i][j] == LAND_SPACE)
                    {
                        if( i == 0 || j == 0 ||
                            i == (mapHeight - 1) || j == (mapWidth - 1))
                        {
                            floorMap[i][j] = BRIDGE_SPACE;
                        }
                    }


                    switch(floorMap[i][j])
                    {
                    case MOUSE_SPACE:
                        if(Jerry->getMouseState() == DOES_NOT_EXIST)
                        {
                            Jerry->setYPos(i);
                            Jerry->setXPos(j);
                            Jerry->setDefaultPosition();

                            Jerry->setMouseState(ALIVE);
                            floorMap[i][j] = LAND_SPACE;
                        }
                        else
                            floorMap[i][j] = LAND_SPACE;

                        break;
                    case CAT_SPACE:
                        if(Tom->getCatState() == NOT_EXIST)
                        {
                            Tom->setYPos(i);
                            Tom->setXPos(j);
                            Tom->setDefaultPosition();
                            Tom->setIsOnMap(TRUE);

                            Tom->setCatState(HUNGRY);
                            floorMap[i][j] = LAND_SPACE;
                        }
                        else
                            floorMap[i][j] = LAND_SPACE;
                        break;
                    default:
                        break;
                    }
                }
            }

                if(Jerry->getMouseState() == DOES_NOT_EXIST
                   || Tom->getCatState() == NOT_EXIST)
                {
                std::cout << "A map requires both a cat and mouse to play!" << std::endl;
                return false;
                }

            break;
        }
        else
        {
            std::cout << cstr << "  was not found!" << std::endl;
            return false;
        }

    }
    mapIn.close();
    delete cstr;
    cstr = NULL;

    return true;
}


vector <vector <int> >& MapReader::getFloorMap(){

    return floorMap;
}

void MapReader::testPrint(Cat* Tom, Mouse* Jerry)
{
    //Y pos
    for(int i = 0; i < mapHeight; i++)
    {
        //X Pos
        for (int j = 0; j < mapWidth; j ++)
        {
            if(Jerry->getYPos() == i && Jerry->getXPos() == j)
            {
                std::cout << " M";
            }

            else if (Tom->getIsOnMap() == true &&
                     Tom->getYPos() == i && Tom->getXPos() == j)
                {
                    std::cout << " C";
                }
                else{
                    switch(floorMap[i][j])
                    {
                    case WATER_SPACE:
                        std::cout << " W";
                        break;
                    case BRIDGE_SPACE:
                        std::cout << " B";
                        break;
                    case LAND_SPACE:
                        std::cout << " L";
                        break;
                    case FOOD_SPACE:
                        std::cout << " F";
                        break;
                    case MOUSE_HOLE:
                        std::cout << " _";
                        break;
                    }

            }

        }
        std::cout << std::endl;
    }
}


std::string MapReader::getMapTitle(){
    return mapTitle;
}


/*

void MapReader::PrintWindow()
{

    init_pair(1,COLOR_CYAN,COLOR_BLACK);//----Initialize color pair
    wbkgd(mapWindow, COLOR_PAIR(1));

    for(int column=20; column<31; column ++)
    {
        for(int row=4; row<13; row++)
        {
            YHolder = startPrintY + row;
            if (YHolder >= 31){
                YHolder = 0;
            }
            if (YHolder < 0){
                YHolder = 0;
            }

            XHolder = startPrintX + column;
            if (XHolder >= 139){
                XHolder = 0;
            }

            if (XHolder < 0){
                XHolder = 0;
            }

            wmove(mapWindow, row,column);

            if(floorMap[YHolder][XHolder] == '#')
            {
                waddch(mapWindow, '#');
            }
            else{

                waddch(mapWindow, floorMap[YHolder][XHolder]);

            }


                }
        }
    }

    wrefresh(mapWindow);//Pushes changes to the screen
}

*/

int MapReader::atPosition(int yToCheck, int xToCheck)
{
    //unbounded check, logic to prevent checking outside of array will be handled
    //in the checkGameState function in GameController.cpp
    return floorMap[yToCheck][xToCheck];
}

void MapReader::setPosition(int yToSet, int xToSet, int newInt){
    floorMap[yToSet][xToSet] = newInt;
}


WINDOW* MapReader::getMapReader(){
    return mapWindow;
}

int MapReader::getMapHeight(){
    return mapHeight;
}

int MapReader::getMapWidth(){
    return mapWidth;
}


int MapReader::getNumSimulations(){
    return numSimulations;
}
