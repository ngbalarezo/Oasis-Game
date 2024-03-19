#pragma once
#ifndef BUILDINGS_H
#define BUILDINGS_H

#include <iostream>
#include <array>
#include <vector>
#include <string>
#include "menu.h"
#include "characters.h"
#include "inventory.h"
#include "items.h"

class shop {
private:
    //each shop will sell 3 weapons, 1 armor, and 1 potion, 
    weapon sWeaponSlot1;
    weapon sWeaponSlot2;
    weapon sWeaponSlot3;
    armor sArmorSlot;
    potion sPotionSlot;
    bool isEmpty;
    int shopLevel;
    //!FIXME: add in scroll/book item + functionality

public:
    //constructors
    shop();

    shop(weapon sWeaponSlot1, weapon sWeaponSlot2, weapon sWeaponSlot3, armor sArmorSlot, potion sPotionSlot, bool isEmpty, int shopLevel);

    //getters

    //setters

    //methods

};

#endif