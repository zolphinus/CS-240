#include "GameController.h"
#include "MapReader.h"
#include <time.h>
#include <cstdlib>
#include <ctime>


GameController::GameController(std::string mapFile)
{
    seed = time(NULL);
    srand(seed);


    Jerry = new Mouse();
    Tom = new Cat();
    srand(time(NULL));
    mapName = mapFile;

    mapIsRead = islandMap.ReadMap(mapName, Tom, Jerry);



    if(mapIsRead != true)
    {
        std::cout << "Unable to load map, exiting program" << std::endl;
        isPlaying == false;
    }
    else
    {
        isPlaying = true;
        numTrials = 0;
        initFreqMap();
    }
}

GameController::~GameController(){
    delete Jerry;
    Jerry = NULL;
    delete Tom;
    Tom = NULL;
}


void GameController::testPrint()
{
    islandMap.testPrint(Tom, Jerry);
}


void GameController::printMouse(){
    std::cout << "Mouse Y " << Jerry->getYPos() << " X " << Jerry->getXPos() << std::endl;
}


void GameController::moveAnimal(GameObject* currentAnimal)
{

    int moveDirection = rand() % TOTAL_DIRECTIONS;
    bool legalMove = true;
    int yModifier = 0;
    int xModifier = 0;

    switch(moveDirection)
    {
    case NORTH:
        yModifier--;
        break;
    case SOUTH:
        yModifier++;
        break;
    case EAST:
        xModifier++;
        break;
    case WEST:
        xModifier--;
        break;
    }


    //checks for legal x/y coordinates before moving
    if( (currentAnimal->getXPos() + xModifier) < 0 ||
       (currentAnimal->getXPos() + xModifier) > (islandMap.getMapWidth() - 1)){
           legalMove = false;
       }

    if( (currentAnimal->getYPos() + yModifier) < 0 ||
       (currentAnimal->getYPos() + yModifier) > (islandMap.getMapHeight() - 1)){
           legalMove = false;
       }


       //Overload Game Objects to compare X/Y values automatically
    if(legalMove == true)
    {
        //if it's the mouse, moves unrestricted
        if(currentAnimal == Jerry){
                currentAnimal->setYPos(currentAnimal->getYPos() + yModifier);
                currentAnimal->setXPos(currentAnimal->getXPos() + xModifier);
                Jerry->setCurrentStam(Jerry->getCurrentStam() - 1);
                frequencyMap[currentAnimal->getYPos()][currentAnimal->getXPos()]++;
           }
        if(currentAnimal == Tom && Tom->getIsOnMap() == TRUE){
               if(islandMap.atPosition(Tom->getYPos() + yModifier, Tom->getXPos() + xModifier) == WATER_SPACE)
               {
                   //If the cat's next move would be water, it does nothing instead
                   Tom->updatePatience();
               }
               else
               {
                currentAnimal->setYPos(currentAnimal->getYPos() + yModifier);
                currentAnimal->setXPos(currentAnimal->getXPos() + xModifier);
                Tom->updatePatience();
               }
           }
    }



}


void GameController::clearScreen()
{
    cout << string( CONSOLE_SIZE, '\n' );
}


void GameController::getStamAndPatience(){
    std::cout << "Mouse stamina is " << Jerry->getCurrentStam() << "/" << Jerry->getMaxStam() << std::endl;
    std::cout << "Cat Patience is " << Tom->getPatience() << std::endl;

}

void GameController::consoleTest()
{
    for(int i = 0; i < 1000000; i++){
        //
        islandMap.testPrint(Tom, Jerry);
        getStamAndPatience();
        moveAnimal(Jerry);
        moveAnimal(Tom);
        checkGameState();
        clearScreen();
    }
}

void GameController::runGame()
{
    if(isPlaying = true)
    {
    while(numTrials < islandMap.getNumSimulations()){
            isPlaying = true;
            std::cout << "GAME " << numTrials + 1 << std::endl;
        while(isPlaying == true){
            checkGameState();
            islandMap.testPrint(Tom, Jerry);
            moveAnimal(Jerry);
            moveAnimal(Tom);
            clearScreen();
            wait(1);
        }

        //Output information to file here
        wait(3);
        resetGame();
    }

    stats.outputToFile(frequencyMap, seed, islandMap.getNumSimulations(), islandMap.getMapTitle(),
                       islandMap.getMapWidth(), islandMap.getMapHeight());
    }
    else
        std::cout << "AN ERROR HAS OCCURED" << std::endl;
}

void GameController::checkGameState(){

    int tempTile;
    //check Jerry first

    tempTile = islandMap.atPosition(Jerry->getYPos(), Jerry->getXPos());


    switch(tempTile){
    case WATER_SPACE :
        //Drowns
        Jerry->setMouseState(DROWNED);
        std::cout << std::endl << "The mouse has drowned." << std::endl;
        isPlaying = false;
        stats.updateStats(DROWNED);

        break;
    case FOOD_SPACE:
        //Eats food
        Jerry->setMouseState(ALIVE);
        Jerry->setCurrentStam(Jerry->getMaxStam());
        islandMap.setPosition(Jerry->getYPos(), Jerry->getXPos(), LAND_SPACE);
        break;
    case MOUSE_HOLE:
        Jerry->setMouseState(IN_HOLE);
        break;
    case BRIDGE_SPACE:
        if(Tom->getIsOnMap() == false){
            Jerry->setMouseState(ESCAPED);
            std::cout << std::endl << "The mouse has escaped." << std::endl;
            isPlaying = false;
            stats.updateStats(ESCAPED);
        }
        break;

    case LAND_SPACE:
        Jerry->setMouseState(ALIVE);
        break;
    }

    if(Jerry->getCurrentStam() <= 0){
        std::cout << "The mouse starved." << std::endl;
        Jerry->setMouseState(STARVED);
        stats.updateStats(STARVED);

        isPlaying == false;
    }

    //Tom
    tempTile = islandMap.atPosition(Tom->getYPos(), Tom->getXPos());


    switch(tempTile){
    case WATER_SPACE :
        std::cout << "ERROR CAT IN WATER!!!" << std::endl;
        isPlaying == false;
        break;
    case BRIDGE_SPACE:
        if(Tom->getPatience() <= 0 && Tom->getIsOnMap() == TRUE)
        {
            std::cout << "The cat got bored and left the island..." << std::endl;
            Tom->setIsOnMap(FALSE);
        }
        break;
    }

    if(Tom->getIsOnMap() == TRUE
       && Tom->getXPos() == Jerry->getXPos()
       && Tom->getYPos() == Jerry->getYPos()){
        std::cout << "The cat ate the mouse..." << std::endl;
        Jerry->setMouseState(EATEN);
        stats.updateStats(EATEN);
        isPlaying = false;
       }




       if(isPlaying == false)
       {
           //record stats and reset

        numTrials++;
        Jerry->setMouseState(DOES_NOT_EXIST);
        Tom->setCatState(NOT_EXIST);
       }

}


void GameController::resetGame(){
    bool mapIsRead = islandMap.ReadMap(mapName, Tom, Jerry);

    if(mapIsRead == false)
    {
        std::cout << "ERROR LOADING MAP" << std::endl;
        //if there is an error loading map, skips this trial
        isPlaying = false;
    }
    else{
        Jerry->setCurrentStam(Jerry->getMaxStam());
        Jerry->setMouseState(ALIVE);
        Tom->setPatience(STARTING_PATIENCE);

        //std::cout << "Reset Game : " << Tom->getPatience() << std::endl;

        Tom->setCatState(HUNGRY);
    }
}


void GameController::initFreqMap(){

    this->frequencyMap.resize(islandMap.getMapHeight());

        for(int i = 0; i < islandMap.getMapHeight(); i++)
        {
            this->frequencyMap[i].resize(islandMap.getMapWidth(), 0);
        }

    for(int j = 0; j < islandMap.getMapHeight(); j++){

        for(int k = 0; k < islandMap.getMapWidth(); k++){
            this->frequencyMap[j][k] = 0;
        }
    }

}

void GameController::printFreqMap(){
    for(int j = 0; j < islandMap.getMapHeight(); j++){

        for(int k = 0; k < islandMap.getMapWidth(); k++){
            std::cout << " " << frequencyMap[j][k];
        }
        std::cout << std::endl;
    }
}

void GameController::wait(int sec) //credit to http://www.cplusplus.com/forum/beginner/74239/
{
 clock_t endwait;
 endwait = clock() + sec * CLK_TCK;
 while (clock() < endwait) {}
}
