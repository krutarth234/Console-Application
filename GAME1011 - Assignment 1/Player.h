#ifndef PLAYER_H
#define PLAYER_H


#include "GameObject.h" // to use GameObject class

class Player : public GameObject
{
private:
    std::string name;
    int health;

public:
    int NormalAttack() override; // override virtual function

    virtual int SpecialAttack() = 0; // pure virtual function

    // Mutators and Accessors
    void setPlayerName(std::string);

    void setPlayerHealth(int);

    std::string getPlayerName();

    int getPlayerHealth();
};

#endif 

