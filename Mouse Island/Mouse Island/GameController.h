#ifndef GAME_CONTROLLER
#define GAME_CONTROLLER

#include "GameConfig.h"
#include "MapReader.h"
#include "Mouse.h"
#include "Cat.h"

class GameController
{
public:
    GameController(std::string);
    void testPrint();
    void printMouse();

private:
    MapReader islandMap;
    Mouse Jerry;
    Cat Tom;
    bool mapIsRead;

    vector <GameObject*> myObjects;
};

#endif // GAME_CONTROLLER
