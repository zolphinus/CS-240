#include <curses.h>
#include "GameController.h"

int main()
{
    GameController test("map0.txt");
    test.printMouse();
    return 0;
}
