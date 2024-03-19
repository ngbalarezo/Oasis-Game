#include <iostream>


//menu options
void returnToOverworld() {
    std::cout << "Returned to Overworld." << std::endl;
}
void enterBattle() {
    std::cout << "Entered Battle." << std::endl;
}
void manageInventory() {
    std::cout << "Inventory Opened." << std::endl;
}
void enterShop() {
    std::cout << "Entered Shop." << std::endl;
}
void chat() {
    std::cout << "You chat with an NPC." << std::endl;
}
void quitGame() {
    std::cout << "Game Quit." << std::endl;
}

//main menu
void menu() {
    int userInput;
    std::cout << "1. Return to Game" << std::endl;
    std::cout << "2. Enter Battle" << std::endl;
    std::cout << "3. Manage Inventory" << std::endl;
    std::cout << "4. Enter Shop" << std::endl;
    std::cout << "5. Talk to Someone" << std::endl;
    std::cout << "6. Quit Game" << std::endl;

    std::cin >> userInput;
    switch (userInput) {
    case 1:
        returnToOverworld();
        break;
    case 2:
        enterBattle();
        break;
    case 3:
        manageInventory();
        break;
    case 4:
        enterShop();
        break;
    case 5:
        chat();
        break;
    case 6:
        quitGame();
        break;
    default:
        std::cout << "Not an option." << std::endl;
    }
}

//WORK AREA FOR BATTLE FUNCTION

//#pragma once
//#ifndef BUILDINGS_H
//#define BUILDINGS_H
//
//#include <iostream>
//#include <array>
//#include <vector>
//#include <string>
//#include "menu.h"
//#include "characters.h"
//#include "inventory.h"
//#include "items.h"
//
//class shop {
//private:
//    //each shop will sell 3 weapons, 1 armor, and 1 potion, 
//    weapon shopWeaponSlot1;
//    weapon shopWeaponSlot2;
//    weapon shopWeaponSlot3;
//    armor shopArmorSlot;
//    potion shopPotionSlot;
//    bool isEmpty;
//    int shopLevel;
//    //!FIXME: add in scroll/book item + functionality
//
//public:
//    //constructors
//    shop();
//
//    shop(weapon shopWeaponSlot1, weapon shopWeaponSlot2, weapon shopWeaponSlot3, armor shopArmorSlot, potion shopPotionSlot, bool isEmpty, int shopLevel);
//
//    //getters
//
//    //setters
//
//    //methods
//
//};
//
//#endif


//#include "buildings.h"
//#include "items.h"
//
////SHOP CLASS DEFINITIONS
//
////constructors
//
//shop::shop() {
//    //create null item objects
//    weapon noWeapon;
//    armor noArmor;
//    potion noPotion;
//    //set defaults to null objects
//    shopWeaponSlot1 = noWeapon;
//    shopWeaponSlot2 = noWeapon;
//    shopWeaponSlot3 = noWeapon;
//    shopArmorSlot = noArmor;
//    shopPotionSlot = noPotion;
//    isEmpty = true;
//    shopLevel = 0;
//}
//
//shop::shop(weapon shopWeaponSlot1, weapon shopWeaponSlot2, weapon shopWeaponSlot3, armor shopArmorSlot, potion shopPotionSlot, bool isEmpty, int shopLevel) {
//    this->shopWeaponSlot1 = shopWeaponSlot1;
//    this->shopWeaponSlot2 = shopWeaponSlot2;
//    this->shopWeaponSlot3 = shopWeaponSlot3;
//    this->shopArmorSlot = shopArmorSlot;
//    this->shopPotionSlot = shopPotionSlot;
//    this->shopLevel = shopLevel;
//}



