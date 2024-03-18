#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h" // to use GameObject class

class Enemy : public GameObject
{
private:
    int health;

public:
    int NormalAttack() override;

    virtual void TauntPlayer() = 0; // pure abstract function for Enemy class

    // Mutators and Accessors
    void setEnemyHealth(int);

    int getEnemyHealth();
    
};

#endif 

