#include "Cat.h"
#include <time.h>
#include <cstdlib>

Cat::Cat(){
    setCatState(NOT_EXIST);
    mapIcon = 'C';
    patience = STARTING_PATIENCE;

}

Cat::~Cat(){
}

void Cat::setPatience(int newPatience){
    patience = newPatience;
}

int Cat::getPatience(){
    return patience;
}

void Cat::updatePatience(){
    int boredom = std::rand() % 3;
    int excitement = rand() % 3;

    if(patience > 0){
            //Cats sometimes lose or gain interest at random...just like real life
            currentState = HUNGRY;
            patience -= boredom;
            patience += excitement;

            //Cats will eventually grow bored
            patience--;
    }

    if(patience <= 0){
        currentState = BORED;
    }
}

void Cat::setCatState(CatState newState)
{
    currentState = newState;
}

CatState Cat::getCatState(){
    return currentState;
}
