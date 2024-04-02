#include <iostream>
#include <iomanip>
#include "buildings.h"
#include "items.h"

//SHOP CLASS DEFINITIONS

//constructors

shop::shop() {
    //create null item objects
    npc noShopKeeper;
    weapon noWeapon;
    armor noArmor;
    potion noPotion;
    item noItem;
    //set defaults to null objects
    shopName = "null";
    shopKeeper = noShopKeeper;
    shopWeaponSlot1 = noWeapon;
    shopWeaponSlot2 = noWeapon;
    shopArmorSlot = noArmor;
    shopPotionSlot = noPotion;
    shopItemSlot = noItem;
    isEmpty = true;
    shopLevel = 0;
    wasVisited = false;
}

shop::shop(weapon shopWeaponSlot1, weapon shopWeaponSlot2, armor shopArmorSlot, potion shopPotionSlot, item shopItemSlot) {
    //create null item objects
    npc noShopKeeper;
    weapon noWeapon;
    armor noArmor;
    potion noPotion;
    //set defaults
    shopName = "null";
    shopKeeper = noShopKeeper;
    this->shopWeaponSlot1 = shopWeaponSlot1;
    this->shopWeaponSlot2 = shopWeaponSlot2;
    this->shopArmorSlot = shopArmorSlot;
    this->shopPotionSlot = shopPotionSlot;
    this->shopItemSlot = shopItemSlot;
    shopPotionSlot = noPotion;
    isEmpty = true;
    shopLevel = 0;
    wasVisited = false;
}

shop::shop(std::string shopName, npc shopKeeper, weapon shopWeaponSlot1, weapon shopWeaponSlot2, armor shopArmorSlot, potion shopPotionSlot, item shopItemSlot, bool isEmpty, int shopLevel, bool wasVisited) {
    this->shopName = shopName;
    this->shopKeeper = shopKeeper;
    this->shopWeaponSlot1 = shopWeaponSlot1;
    this->shopWeaponSlot2 = shopWeaponSlot2;
    this->shopArmorSlot = shopArmorSlot;
    this->shopPotionSlot = shopPotionSlot;
    this->shopItemSlot = shopItemSlot;
    this->isEmpty = isEmpty;
    this->shopLevel = shopLevel;
    this->wasVisited = wasVisited;
}

//getters
std::string shop::getShopName() { return shopName; }

npc shop::getShopKeeper() { return shopKeeper; }

weapon shop::getShopWeaponSlot1() { return shopWeaponSlot1; }

weapon shop::getShopWeaponSlot2() { return shopWeaponSlot2; }

armor shop::getShopArmorSlot() { return shopArmorSlot; }

potion shop::getShopPotionSlot() { return shopPotionSlot; }

item shop::getShopItemSlot() { return shopItemSlot; }

bool shop::getIsEmpty() { return isEmpty; }

int shop::getShopLevel() { return shopLevel; }

bool shop::getWasVisited() { return wasVisited; }

//setters
void shop::setShopName(std::string shopName) { this->shopName = shopName; }

void shop::setShopKeeper(npc shopKeeper) { this->shopKeeper = shopKeeper; }

void shop::setShopWeaponSlot1(weapon shopWeaponSlot1) { this->shopWeaponSlot1 = shopWeaponSlot1; }

void shop::setShopWeaponSlot2(weapon shopWeaponSlot2) { this->shopWeaponSlot2 = shopWeaponSlot2; }

void shop::setShopArmorSlot(armor shopArmorSlot) { this->shopArmorSlot = shopArmorSlot; }

void shop::setShopPotionSlot(potion shopPotionSlot) { this->shopPotionSlot = shopPotionSlot; }

void shop::setShopItemSlot(item shopItemSlot) { this->shopItemSlot = shopItemSlot; }

void shop::setIsEmpty(bool isEmpty) { this->isEmpty = isEmpty; }

void shop::setShopLevel(int setShopLevel) { this->shopLevel = shopLevel; }

void shop::setWasVisited(bool wasVisited) { this->wasVisited = wasVisited; }

//methods
void shop::enterShop() {
    //declare variables
    int playerChoice;

    //!FIXME: add in dialogue tree and display shop items if player chooses to take a look at the shelves "I would like to take a look at your shelves."
    
    //add buy/sell options for npc dialogue tree

    //displays shop items
    displayShopItems();

    //displays choice options so that the player can buy, etc.
    playerChoice = displayBuyOptions();
}

void shop::displayShopItems() {
    //iomanip stream manipulations
    std::cout << std::setiosflags(std::ios::left); //left aligns setw()
    //display spacing header
    std::cout << std::setw(15) << "Item Type" << std::setw(15) << "Name" << std::setw(15) << "Weight" << std::setw(15) << "Price" << std::endl;
    std::cout << std::setw(51) << "================================================================" << std::endl << std::endl;
    //display items in order
    std::cout << std::setw(15) << "Weapon 1: " << std::setw(15) << shopWeaponSlot1.getName() << std::setw(15) << shopWeaponSlot1.getWeight() << std::setw(15) << shopWeaponSlot1.getCoinValue() << std::endl << std::endl;
    std::cout << std::setw(15) << "Weapon 2: " << std::setw(15) << shopWeaponSlot2.getName() << std::setw(15) << shopWeaponSlot2.getWeight() << std::setw(15) << shopWeaponSlot2.getCoinValue() << std::endl << std::endl;
    std::cout << std::setw(15) << "Armor: " << std::setw(15) << shopArmorSlot.getName() << std::setw(15) << shopArmorSlot.getWeight() << std::setw(15) << shopArmorSlot.getCoinValue() << std::endl << std::endl;
    std::cout << std::setw(15) << "Potion: " << std::setw(15) << shopPotionSlot.getName() << std::setw(15) << "n/a" << std::setw(15) << shopPotionSlot.getCoinValue() << std::endl << std::endl;
    std::cout << std::setw(15) << "Item: " << std::setw(15) << shopItemSlot.getName() << std::setw(15) << shopItemSlot.getWeight() << std::setw(15) << shopItemSlot.getCoinValue() << std::endl << std::endl;
    std::cout << std::setw(64) << "================================================================" << std::endl << std::endl;
    std::cout << std::endl;
}

int shop::displayBuyOptions() {
    int playerChoice;
    std::cout << "What would you like to buy?"<<std::endl;
    std::cout << "[1] " << shopWeaponSlot1.getName() << std::endl;
    std::cout << "[2] " << shopWeaponSlot2.getName() << std::endl;
    std::cout << "[3] " << shopArmorSlot.getName() << std::endl;
    std::cout << "[4] " << shopPotionSlot.getName() << std::endl;
    std::cout << "[5] " << shopItemSlot.getName() << std::endl;
    std::cout << "[6] I'm done shopping." << std::endl;

    std::cin >> playerChoice;

    return playerChoice;
}

void shop::sellTo(player& player) {

}

