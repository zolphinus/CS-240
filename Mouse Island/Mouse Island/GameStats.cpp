#include "GameStats.h"
#include <iostream>

GameStats::GameStats(){
    initGameStats();
}

void GameStats::initGameStats(){

    for(int i = 0; i < TOTAL_MOUSE_STATS; i++){
        mouseStats[i] = 0;
    }
}

void GameStats::updateStats(MouseState newState){
    if(newState <= TOTAL_MOUSE_STATS){
        mouseStats[newState]++;
    }
}

int* GameStats::getMouseStats(){
    return mouseStats;
}

void GameStats::printMouseStats(){
    for(int i = 0; i <TOTAL_MOUSE_STATS; i++){
        std::cout << mouseStats[i] << std::endl ;
    }
}
