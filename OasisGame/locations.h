#pragma once
#ifndef LOCATIONS_H
#define LOCATIONS_H

#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include <string>
#include "menu.h"
#include "characters.h"
#include "inventory.h"
#include "items.h"


class wilderness {
private:
    enemy localEnemy1;
    enemy localEnemy2;
    enemy localBoss;
public:
    //constructors
    wilderness(){} //default constructor

    wilderness(npc localNpc1, enemy localEnemy1,
        enemy localEnemy2, enemy localBoss,
        location& upLocation, location& leftLocation,
        location& downLocation, location& rightLocation) { //wilderness constructor
        this->localNpc1 = localNpc1;
        this->localNpc2 = localNpc2;
        this->localEnemy1 = localEnemy1;
        this->localEnemy2 = localEnemy2;
        this->localBoss = localBoss;
        this->upLocation = &upLocation;
        this->leftLocation = &leftLocation;
        this->downLocation = &downLocation;
        this->rightLocation = &rightLocation;

    }
};


#endif