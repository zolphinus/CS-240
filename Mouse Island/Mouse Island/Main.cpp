#include <curses.h>
#include "GameController.h"

void testDriver();

int main()
{
    testDriver();
    return 0;
}


void testDriver(){
    GameController test("map0.txt");
    test.consoleTest();
    test.printMouse();
}
