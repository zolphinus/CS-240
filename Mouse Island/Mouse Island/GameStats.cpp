#include "GameStats.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

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




void GameStats::outputToFile(std::vector <std::vector <int> >& frequencyMap, int seed, int numSims, std::string mapName,
                             int mapWidth, int mapHeight)
{
    	std::ofstream outputStats("Mouse Stats.txt", std::ios::app); //saves statistics, adds to file

    int temp;
	outputStats << "Map Name: " << mapName << "\n \n";
	outputStats << "Simulation ran " << numSims << " time(s). \n \n";
	outputStats << "The seed number was " << seed << "\n \n";

	temp = mouseStats[DROWNED];
	outputStats << "Mouse drowned " << mouseStats[DROWNED] << " time(s). \n";
	outputStats << "Mouse was eaten " << mouseStats[EATEN] << " time(s). \n";
	outputStats << "Mouse starved " << mouseStats[STARVED] << " time(s). \n";
	outputStats << "Mouse escaped " << mouseStats[ESCAPED] << " time(s). \n";
	outputStats << "FREQUENCY MAP OF SQUARES MOUSE VISITED \n \n \n";

	for(int i = 0; i < mapHeight; i++)
	{
		for(int j = 0; j < mapWidth; j++)
		{
			outputStats << frequencyMap[i][j] << " ";
		}
		outputStats << "\n";
	}
	outputStats << "\n";
	outputStats << "\n";

	//Create loop that displays the frequency array here

	outputStats.close();
}
