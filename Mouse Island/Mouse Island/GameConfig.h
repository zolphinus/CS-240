#ifndef GAME_CONFIG
#define GAME_CONFIG

const int MAP_WINDOW_WIDTH = 20;
const int MAP_WINDOW_HEIGHT = 20;

const int MAX_STAMINA = 100;
const int STARTING_PATIENCE = 125;

const int CONSOLE_SIZE = 3;

enum MouseState
{
    DOES_NOT_EXIST,
    ALIVE,
    DROWNED,
    EATEN,
    STARVED,
    ESCAPED
};

enum CatState
{
    NOT_EXIST,
    HUNGRY,
    BORED
};

enum MapTile
{
    WATER_SPACE,
    LAND_SPACE,
    BRIDGE_SPACE,
    MOUSE_SPACE,
    CAT_SPACE,
    MOUSE_HOLE,
    FOOD_SPACE
};

enum Direction
{
    NORTH,
    SOUTH,
    EAST,
    WEST,
    TOTAL_DIRECTIONS
};

#endif // GAME_CONFIG
