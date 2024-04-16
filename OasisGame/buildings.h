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
    armor shopArmorSlot;
    potion shopPotionSlot;
    item shopItemSlot;
    bool isEmpty;
    int shopLevel;
    bool wasVisited;
    //!FIXME: add in scroll/book item + functionality

public:
    //constructors
    shop();

    shop(weapon shopWeaponSlot1, weapon shopWeaponSlot2, armor shopArmorSlot, potion shopPotionSlot, item shopItemSlot);

    shop(std::string shopName, npc shopKeeper, weapon shopWeaponSlot1, weapon shopWeaponSlot2, armor shopArmorSlot,
        potion shopPotionSlot, item shopItemSlot, bool isEmpty, int shopLevel, bool wasVisited);

    //getters
    std::string getShopName();

    npc getShopKeeper();

    weapon getShopWeaponSlot1();

    weapon getShopWeaponSlot2();

    armor getShopArmorSlot();

    potion getShopPotionSlot();

    item getShopItemSlot();

    bool getIsEmpty();

    int getShopLevel();

    bool getWasVisited();

    //setters
    void setShopName(std::string shopName);

    void setShopKeeper(npc shopKeeper);

    void setShopWeaponSlot1(weapon shopWeaponSlot1);

    void setShopWeaponSlot2(weapon shopWeaponSlot2);

    void setShopArmorSlot(armor shopArmorSlot);

    void setShopPotionSlot(potion shopPotionSlot);

    void setShopItemSlot(item shopItemSlot);

    void setIsEmpty(bool setIsEmpty);

    void setShopLevel(int setShopLevel);

    void setWasVisited(bool wasVisited);

    //methods
    void enterShop(player& player);

    void displayShopItems();

    int displayBuyOptions(player& player);

    void sellTo(player& player, int playerChoice);

};

class Church {

};

class recCenter {

};

#endif