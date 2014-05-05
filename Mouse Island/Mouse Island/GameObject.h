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

    void setDefaultPosition();
    void resetToDefault();

    void setIsOnMap(bool);
    char getMapIcon();

private:
    int xPos;
    int yPos;

    int defaultXPos;
    int defaultYPos;

    bool isOnMap;

protected:
    char mapIcon;
};

#endif // GAME_OBJECT
