#include "GameController.h"
#include "MapReader.h"
#include <time.h>
#include <cstdlib>
#include <ctime>


GameController::GameController(std::string mapFile)
{
    srand(time(NULL));

    mapIsRead = islandMap.ReadMap(mapFile, Tom, Jerry, myObjects);

    if(mapIsRead != true)
    {
        std::cout << "Unable to load map, exiting program" << std::endl;
        for(int i = 0; i < 10; i++){

        islandMap.testPrint(Tom, Jerry, myObjects);
        moveAnimal(Jerry);
        moveAnimal(Tom);
        clearScreen();
        }
    }
    else{

}
}


void GameController::testPrint()
{
    islandMap.testPrint(Tom, Jerry, myObjects);
}


void GameController::printMouse(){
    std::cout << "Mouse Y " << Jerry.getYPos() << " X " << Jerry.getXPos() << std::endl;
}


void GameController::moveAnimal(GameObject& currentAnimal)
{

    int moveDirection = rand() % TOTAL_DIRECTIONS;
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

    //if it's the mouse, moves unrestricted
    if(currentAnimal.getYPos() == Jerry.getYPos()
       && currentAnimal.getXPos() == Jerry.getXPos()){
            currentAnimal.setYPos(currentAnimal.getYPos() + yModifier);
            currentAnimal.setXPos(currentAnimal.getXPos() + xModifier);
            Jerry.setCurrentStam(Jerry.getCurrentStam() - 1);
       }
    if(currentAnimal.getYPos() == Tom.getYPos()
       && currentAnimal.getXPos() == Tom.getXPos()){
           if(islandMap.atPosition(Tom.getYPos() + yModifier, Tom.getXPos() + xModifier) == WATER_SPACE)
           {
               //If the cat's next move would be water, it does nothing instead
               Tom.updatePatience();
           }
           else
           {
            currentAnimal.setYPos(currentAnimal.getYPos() + yModifier);
            currentAnimal.setXPos(currentAnimal.getXPos() + xModifier);
            Tom.updatePatience();
           }
       }


}


void GameController::clearScreen()
{
    cout << string( CONSOLE_SIZE, '\n' );
}


void GameController::getStamAndPatience(){
    std::cout << "Mouse stamina is " << Jerry.getCurrentStam() << "/" << Jerry.getMaxStam() << std::endl;
    std::cout << "Cat Patience is " << Tom.getPatience() << std::endl;

}

void GameController::consoleTest()
{
    for(int i = 0; i < 10; i++){

        islandMap.testPrint(Tom, Jerry, myObjects);
        getStamAndPatience();
        moveAnimal(Jerry);
        moveAnimal(Tom);
        clearScreen();
    }
}

void GameController::runGame()
{

}
