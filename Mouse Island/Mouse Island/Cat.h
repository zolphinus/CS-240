#ifndef CAT
#define CAT

#include "GameConfig.h"
#include "GameObject.h"

class Cat : public GameObject{
public:
    Cat();
    ~Cat();

    //Stamina
    void setPatience(int);
    int getPatience();

    CatState getCatState();
    void setCatState(CatState);
    void updatePatience();
    //Game End Conditions

private:
    //Stamina
    int patience;

    //Game End Conditions
    CatState currentState;
};

#endif // CAT

