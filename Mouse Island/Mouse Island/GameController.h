#ifndef GAME_CONTROLLER
#define GAME_CONTROLLER

#include "GameConfig.h"
#include "MapReader.h"
#include "Mouse.h"
#include "Cat.h"
#include "GameStats.h"

class GameController
{
public:
    GameController(std::string);
    ~GameController();

    void testPrint();
    void printMouse();
    void getStamAndPatience();
    void consoleTest();
    void runGame();
    void initFreqMap();
    void printFreqMap();


private:
    MapReader islandMap;
    std::string mapName;
    GameStats stats;


    Mouse* Jerry;
    Cat* Tom;
    int seed;
    bool mapIsRead;
    bool isPlaying;

    //need to obtain from mapreader
    int numTrials;

    vector <vector <int> > frequencyMap; //needs function to size and initialize to map over floorMap, as well as reset

    void moveAnimal(GameObject*);
    void clearScreen();
    void resetGame();
    void checkGameState();
    void wait(int);



};

#endif // GAME_CONTROLLER
