#include "GameController.h"
#include "MapReader.h"


GameController::GameController(std::string mapFile)
{

    mapIsRead = islandMap.ReadMap(mapFile, Tom, Jerry, myObjects);

    if(mapIsRead == true)
    {
        islandMap.testPrint(Tom, Jerry, myObjects);
    }
    else{
        std::cout << "Unable to load map, exiting program" << std::endl;
    printMouse();
}
}


void GameController::testPrint()
{
    islandMap.testPrint(Tom, Jerry, myObjects);
}


void GameController::printMouse(){
    std::cout << "Mouse Y " << Jerry.getYPos() << " X " << Jerry.getXPos() << std::endl;
}
