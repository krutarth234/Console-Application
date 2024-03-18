// We decided to use header guards of c++ directives instead of #pragma once

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <string>

class GameObject
{
private:
    // place for variables, we will need ahead

public:
    virtual int NormalAttack() = 0; // pure abstract function (GameObject class) and can be override by other classes
};

#endif

