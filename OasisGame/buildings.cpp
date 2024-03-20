
#include "buildings.h"
#include "items.h"

//SHOP CLASS DEFINITIONS

//constructors

shop::shop() {
    //create null item objects
    weapon noWeapon;
    armor noArmor;
    potion noPotion;
    //set defaults to null objects
    shopName = "null";
    shopWeaponSlot1 = noWeapon;
    shopWeaponSlot2 = noWeapon;
    shopWeaponSlot3 = noWeapon;
    shopArmorSlot = noArmor;
    shopPotionSlot = noPotion;
    isEmpty = true;
    shopLevel = 0;
}

shop::shop(std::string shopName, weapon shopWeaponSlot1, weapon shopWeaponSlot2, weapon shopWeaponSlot3, armor shopArmorSlot, potion shopPotionSlot, bool isEmpty, int shopLevel) {
    this->shopName = shopName;
    this->shopWeaponSlot1 = shopWeaponSlot1;
    this->shopWeaponSlot2 = shopWeaponSlot2;
    this->shopWeaponSlot3 = shopWeaponSlot3;
    this->shopArmorSlot = shopArmorSlot;
    this->shopPotionSlot = shopPotionSlot;
    this->shopLevel = shopLevel;
}
