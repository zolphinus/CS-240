#include "Mouse.h"

Mouse::Mouse(){
    setMouseState(DOES_NOT_EXIST);
    mapIcon = 'M';
    maxStam = MAX_STAMINA;
    currentStam = maxStam;

}

Mouse::~Mouse(){
}

void Mouse::setCurrentStam(int newStam){
    currentStam = newStam;
}

void Mouse::setMaxStam(int newMaxStam){
    maxStam = newMaxStam;
}

int Mouse::getCurrentStam(){
    return currentStam;
}

int Mouse::getMaxStam(){
    return maxStam;
}

void Mouse::setMouseState(MouseState newState)
{
    currentState = newState;
}

MouseState Mouse::getMouseState(){
    return currentState;
}
