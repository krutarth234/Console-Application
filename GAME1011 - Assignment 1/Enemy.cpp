#include "Enemy.h"

int Enemy::NormalAttack()
{
    std::cout << "enemy attacks!" << std::endl;
    return 25;
}

void Enemy::setEnemyHealth(int health)
{
    this->health = health;
}

int Enemy::getEnemyHealth()
{
    return health;
}
