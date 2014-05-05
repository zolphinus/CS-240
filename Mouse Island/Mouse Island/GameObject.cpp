#include "GameObject.h"

GameObject::GameObject(){
    xPos = 0;
    yPos = 0;
    isOnMap = false;
    mapIcon = 'd'; //dummy placeholder to avoid printing a null value
}

GameObject::~GameObject(){
}

void GameObject::setXPos(int newXPos){
    xPos = newXPos;
}

void GameObject::setYPos(int newYPos){
    yPos = newYPos;
}

void GameObject::setDefaultPosition(){
    defaultXPos = xPos;
    defaultYPos = yPos;
}

void GameObject::resetToDefault(){
    xPos = defaultXPos;
    yPos = defaultYPos;
}



void GameObject::setIsOnMap(bool isOnMap){
    this->isOnMap = isOnMap;
}

int GameObject::getXPos(){
    return xPos;
}

int GameObject::getYPos(){
    return yPos;
}

int GameObject::getIsOnMap(){
    return isOnMap;
}

char GameObject::getMapIcon(){
    return mapIcon;
}
