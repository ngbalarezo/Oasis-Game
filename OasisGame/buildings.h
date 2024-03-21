#pragma once
#ifndef BUILDINGS_H
#define BUILDINGS_H

#include <iostream>
#include <iomanip>
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
    npc shopKeeper;
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

    shop(weapon shopWeaponSlot1, weapon shopWeaponSlot2, weapon shopWeaponSlot3, armor shopArmorSlot, potion shopPotionSlot);

    shop(std::string shopName, npc shopKeeper, weapon shopWeaponSlot1, weapon shopWeaponSlot2, weapon shopWeaponSlot3, armor shopArmorSlot, potion shopPotionSlot, bool isEmpty, int shopLevel, bool wasVisited);

    //getters
    std::string getShopName();

    npc getShopKeeper();

    weapon getShopWeaponSlot1();

    weapon getShopWeaponSlot2();

    weapon getShopWeaponSlot3();

    armor getShopArmorSlot();

    potion getShopPotionSlot();

    bool getIsEmpty();

    int getShopLevel();

    bool getWasVisited();

    //setters
    void setShopName(std::string shopName);

    void setShopKeeper(npc shopKeeper);
    
    void setShopWeaponSlot1(weapon shopWeaponSlot1);

    void setShopWeaponSlot2(weapon shopWeaponSlot2);

    void setShopWeaponSlot3(weapon shopWeaponSlot3);

    void setShopArmorSlot(armor shopArmorSlot);

    void setShopPotionSlot(potion shopPotionSlot);

    void setIsEmpty(bool setIsEmpty);

    void setShopLevel(int setShopLevel);

    void setWasVisited(bool wasVisited);

    //methods
    void enterShop();

    void displayShopItems();


};

#endif