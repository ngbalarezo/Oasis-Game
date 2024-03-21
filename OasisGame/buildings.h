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
    bool wasVisited;
    //!FIXME: add in scroll/book item + functionality

public:
    //constructors
    shop();

    shop(std::string shopName, weapon shopWeaponSlot1, weapon shopWeaponSlot2, weapon shopWeaponSlot3, armor shopArmorSlot, potion shopPotionSlot, bool isEmpty, int shopLevel, bool wasVisted);

    //getters
    weapon getShopWeaponSlot1();

    weapon getShopWeaponSlot2();

    weapon getShopWeaponSlot3();

    armor getShopArmorSlot();

    potion getShopPotionSlot();

    bool getIsEmpty();

    int getShopLevel();

    bool getWasVisited();

    //setters
    void setShopWeaponSlot1(weapon shopWeaponSlot1);

    void setShopWeaponSlot2(weapon shopWeaponSlot2);

    void setShopWeaponSlot3(weapon shopWeaponSlot3);

    void setShopArmorSlot(armor shopArmorSlot);

    void setShopPotionSlot(potion shopPotionSlot);

    void setIsEmpty(bool setIsEmpty);

    void setShopLevel(int setShopLevel);

    void setWasVisited(bool wasVisited);

    //methods
   

};

#endif