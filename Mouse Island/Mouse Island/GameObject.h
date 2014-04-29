#ifndef GAME_OBJECT
#define GAME_OBJECT

class GameObject
{
public:
    GameObject();
    ~GameObject();
    int getXPos();
    int getYPos();
    int getIsOnMap();
    void setXPos(int);
    void setYPos(int);
    void setIsOnMap(bool);
    char getMapIcon();

private:
    int xPos;
    int yPos;
    bool isOnMap;

protected:
    char mapIcon;
};

#endif // GAME_OBJECT
