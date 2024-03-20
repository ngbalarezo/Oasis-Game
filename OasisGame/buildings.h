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
    std::string shopName;
    weapon shopWeaponSlot1;
    weapon shopWeaponSlot2;
    weapon shopWeaponSlot3;
    armor shopArmorSlot;
    potion shopPotionSlot;
    bool isEmpty;
    int shopLevel;
    //!FIXME: add in scroll/book item + functionality

public:
    //constructors
    shop();

    shop(std::string shopName, weapon shopWeaponSlot1, weapon shopWeaponSlot2, weapon shopWeaponSlot3, armor shopArmorSlot, potion shopPotionSlot, bool isEmpty, int shopLevel);

    //getters

    //setters

    //methods

};

#endif