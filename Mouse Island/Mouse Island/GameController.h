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
    void getStamAndPatience();
    void consoleTest();
    void runGame();

private:
    MapReader islandMap;
    Mouse Jerry;
    Cat Tom;
    bool mapIsRead;

    //need to obtain from mapreader
    int numTrials;

    vector <GameObject*> myObjects;
    vector <vector <int> > frequencyMap; //needs function to size and initialize to map over floorMap, as well as reset

    void moveAnimal(GameObject&);
    void clearScreen();


};

#endif // GAME_CONTROLLER
