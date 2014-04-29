#ifndef MOUSE
#define MOUSE

#include "GameConfig.h"
#include "GameObject.h"

class Mouse : public GameObject{
public:
    Mouse();
    ~Mouse();

    //Stamina
    void setCurrentStam(int);
    void setMaxStam(int);
    int getCurrentStam();
    int getMaxStam();

    MouseState getMouseState();
    void setMouseState(MouseState);
    //Game End Conditions

private:
    //Stamina
    int currentStam;
    int maxStam;

    //Game End Conditions
    MouseState currentState;
};

#endif // MOUSE
