#ifndef GAME_STATS
#define GAME_STATS
#include "GameConfig.h"
#include <vector>
#include <string>


class GameStats{
public:
    GameStats();
    void initGameStats();
    void updateStats(MouseState);
    int* getMouseStats();
    void printMouseStats();
    void outputToFile(std::vector <std::vector <int> >&, int, int, std::string, int, int);

private:
    int mouseStats[TOTAL_MOUSE_STATS];
};

#endif // GAME_STATS
