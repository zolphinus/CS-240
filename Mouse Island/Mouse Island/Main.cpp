#include <curses.h>
#include "GameController.h"

void testDriver();

int main()
{
    testDriver();

    //GameController ourGame("map0.txt");
    //ourGame.runGame();

    return 0;
}


void testDriver(){
    GameController test("map0.txt");
    test.initFreqMap();
    test.consoleTest();
    test.printFreqMap();
    //test.printMouse();

    //test.initFreqMap();

}
