#ifndef GAME_STATS
#define GAME_STATS
#include "GameConfig.h"
#include <vector>


class GameStats{
public:
    GameStats();
    void initGameStats();
    void updateStats(MouseState);
    int* getMouseStats();
    void printMouseStats();

private:
    int mouseStats[TOTAL_MOUSE_STATS];
};

#endif // GAME_STATS
