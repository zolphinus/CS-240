#include "MapReader.h"
#include "GameConfig.h"

MapReader::MapReader()
{
    //mapWindow = newwin(MAP_WINDOW_HEIGHT,MAP_WINDOW_WIDTH,0,0);//creates the window


}

MapReader::~MapReader(){
    //delwin(mapWindow);
}

bool MapReader::ReadMap(string FileName, Cat& Tom, Mouse& Jerry,
                        vector <GameObject*>& myObjects)
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
                    if(floorMap[i][j] < -1)
                    {
                        floorMap[i][j] = -1;
                    }

                    if(floorMap[i][j] > 4 )
                    {
                        floorMap[i][j] = 0;
                    }


                    switch(floorMap[i][j])
                    {
                    case MOUSE_SPACE:
                        if(Jerry.getMouseState() == DOES_NOT_EXIST)
                        {
                            Jerry.setYPos(i);
                            Jerry.setXPos(j);
                            Jerry.setMouseState(ALIVE);
                            floorMap[i][j] = LAND_SPACE;
                        }

                        break;
                    case CAT_SPACE:
                        if(Tom.getCatState() == NOT_EXIST)
                        {
                            Tom.setYPos(i);
                            Tom.setXPos(j);
                            Tom.setCatState(HUNGRY);
                            floorMap[i][j] = LAND_SPACE;
                        }
                        break;
                    case MOUSE_HOLE:
                        std::cout << "MOUSE HOLE" << std::endl;
                        break;
                    case FOOD_SPACE:
                        std::cout << "FOOD SPACE" << std::endl;
                        break;
                    default:
                        break;
                    }
                }
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



void MapReader::testPrint(Cat& Tom, Mouse& Jerry,
                        vector <GameObject*>& myObjects)
{
    for(int i = 0; i < mapHeight; i++)
    {
        for (int j = 0; j < mapWidth; j ++)
        {
            switch(floorMap[i][j])
            {
            case -1:
                std::cout << " W";
                break;
            case LAND_SPACE:
                std::cout << " L";
                break;
            case MOUSE_SPACE:
                std::cout << " M";
                break;

            case CAT_SPACE:
                std::cout << " C";
                break;

            case FOOD_SPACE:
                std::cout << " F";
                break;

            }
        }
        std::cout << std::endl;
    }
}




/*

void MapReader::PrintWindow(int characterPosY, int characterPosX)
{
    bool enemyLocated = false;
    int startPrintY=8, startPrintX=25, xShift, yShift;
    int YHolder, XHolder;

    startPrintX = characterPosX;
    startPrintX -= 25;

    startPrintY=characterPosY;
    startPrintY -= 8;

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

char MapReader::atPosition(int yToCheck, int xToCheck)
{
    return floorMap[yToCheck][xToCheck];
}

void MapReader::setPosition(int yToSet, int xToSet, char newChar){
    floorMap[yToSet][xToSet] = newChar;
}


WINDOW* MapReader::getMapReader(){
    return mapWindow;
}
