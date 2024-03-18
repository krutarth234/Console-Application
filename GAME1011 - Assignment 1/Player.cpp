#include "Player.h"

int Player::NormalAttack()
{
    std::cout << getPlayerName() << " attacks!" << std::endl;
    return 25;
}

void Player::setPlayerName(std::string name)
{
    this->name = name;
}

void Player::setPlayerHealth(int health)
{
    this->health = health;
}

std::string Player::getPlayerName()
{
    return name;
}

int Player::getPlayerHealth()
{
    return health;
}
