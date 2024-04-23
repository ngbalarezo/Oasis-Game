#include <iostream>
#include <iomanip>
#include "menu.h"
#include "map.h"
#include "locations.h"
#include "buildings.h"
#include "characters.h"
#include "inventory.h"
#include "items.h"
#include "DialogueTree.h"

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
    shopName = "Null Shop";
    shopType = "null shop";
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

shop::shop(std::string shopName, std::string shopType, npc shopKeeper, weapon shopWeaponSlot1, weapon shopWeaponSlot2, armor shopArmorSlot, potion shopPotionSlot, item shopItemSlot) {
    //create null item objects
    weapon noWeapon;
    armor noArmor;
    potion noPotion;
    //set defaults
    this->shopName = shopName;
    this->shopType = shopType;
    this->shopKeeper = shopKeeper;
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

shop::shop(std::string shopName, std::string shopType, npc shopKeeper, weapon shopWeaponSlot1, weapon shopWeaponSlot2, armor shopArmorSlot, potion shopPotionSlot, item shopItemSlot, bool isEmpty, int shopLevel, bool wasVisited) {
    this->shopName = shopName;
    this->shopType = shopType;
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

std::string shop::getShopType() { return shopType; }

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

void shop::setShopType(std::string shopName) { this->shopType = shopType; }

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
void shop::enterShop(player& player) {
    //declare variables
    int playerChoice;
    int sentinel = 0;
    //error proofing while loop
    while (sentinel != 1) {
        //print enter shop menu
        system("CLS");
        std::cout << "Welcome to " << shopName << " stranger! What can I do for ya!" << std::endl << std::endl;
        std::cout << "[1] Talk with shopkeeper" << std::endl;
        std::cout << "[2] Look around the shop" << std::endl;
        std::cout << "[3] Exit" << std::endl;
        std::cout << "Choice: ";
        std::cin >> playerChoice;
        //if user chooses to talk with the shop keeper
        if (playerChoice == 1) {
            system("CLS");
            std::cout << "BEGIN DIALOGUE" << std::endl << std::endl;
            system("PAUSE");
        }
        //if user chooses to check out the shop items
        else if (playerChoice == 2) {
            //clear console
            displayShopOptions(player);
        }
        //if user chooses to exit shop
        else if (playerChoice == 3) {
            system("CLS");
            std::cout << "Thanks for stopping by!" << std::endl << std::endl;
            system("PAUSE");
            sentinel = 1;
        }
        else {
            system("CLS");
            std::cout << "That is not an option." << std::endl << std::endl;
            system("PAUSE");
        }
    } 
}

void shop::displayShopItems() {
    //clear console
    system("CLS");
    //iomanip stream manipulations
    std::cout << std::setiosflags(std::ios::left); //left aligns setw()
    //display spacing header
    std::cout << std::setw(15) << "Item Type" << std::setw(25) << "Item Name" << std::setw(15) << "Weight" << std::setw(15) << "Price" << std::setw(15) << "Stats" << std::endl;
    std::cout << std::setw(51) << "====================================================================================" << std::endl << std::endl;
    //display items in order
    std::cout << std::setw(15) << "Weapon 1: " << std::setw(25) << shopWeaponSlot1.getName() << std::setw(15) << shopWeaponSlot1.getWeight() << std::setw(15) << shopWeaponSlot1.getCoinValue();
    std::cout << "Atk: " << shopWeaponSlot1.getAtk() << std::endl << std::endl;
    std::cout << std::setw(15) << "Weapon 2: " << std::setw(25) << shopWeaponSlot2.getName() << std::setw(15) << shopWeaponSlot2.getWeight() << std::setw(15) << shopWeaponSlot2.getCoinValue();
    std::cout << "Atk: " << shopWeaponSlot2.getAtk() << std::endl << std::endl;
    std::cout << std::setw(15) << "Armor: " << std::setw(25) << shopArmorSlot.getName() << std::setw(15) << shopArmorSlot.getWeight() << std::setw(15) << shopArmorSlot.getCoinValue();
    std::cout << "Def: " << shopArmorSlot.getDef() << std::endl << std::endl;
    std::cout << std::setw(15) << "Potion: " << std::setw(25) << shopPotionSlot.getName() << std::setw(15) << "n/a" << std::setw(15) << shopPotionSlot.getCoinValue();
    std::cout << "HP +" << shopPotionSlot.getHealValue() << "/SP +" << shopPotionSlot.getStaminaValue() << std::endl << std::endl;
    std::cout << std::setw(15) << "Item: " << std::setw(25) << shopItemSlot.getName() << std::setw(15) << shopItemSlot.getWeight() << std::setw(15) << shopItemSlot.getCoinValue() << std::endl << std::endl;
    std::cout << std::setw(64) << "====================================================================================" << std::endl << std::endl;
}

void shop::displayShopOptions(player& player) {
    int playerChoice = 0;
    int sentinel = 0;
    while (sentinel != 1) {
        system("CLS");
        std::cout << "What would you like to do?" << std::endl << std::endl;
        std::cout << "[1] Buy" << std::endl;
        std::cout << "[2] Sell" << std::endl;
        std::cout << "[3] Check inventory" << std::endl;
        std::cout << "[4] Exit" << std::endl;
        std::cout << "Choice: ";
        std::cin >> playerChoice;
        if (playerChoice == 1) {
            while (playerChoice != 7) {
                //display shop items
                displayShopItems();
                //display choice options so that the player can buy, etc.
                playerChoice = displayBuyOptions(player);
                //run sellTo menu
                sellTo(player, playerChoice);
            }
        }
        else if (playerChoice == 2) {
            buyFrom(player);
        }
        else if (playerChoice == 3) {
            player.getInventory()->display();
        }
        else if (playerChoice == 4) {
            sentinel = 1;
        }
        else {
            system("CLS");
            std::cout << "That is not an option." << std::endl << std::endl;
            system("PAUSE");
        }
    }
}

int shop::displayBuyOptions(player& player) {
    //declare/intialize variables
    int playerChoice;
    int sentinel = 0;
    //while loop prevents erroneous choice
    while (sentinel != 1) {
        //clear console
        system("CLS");
         //displays shop items before each menu list
        if (sentinel == 0) {
            displayShopItems();
        }
        //print options and prompt user for input
        std::cout << "You have " << player.getInventory()->getCointCount() << " coins! " << "What would you like to buy?" << std::endl << std::endl;
        std::cout << std::setw(64) << "====================================================================================" << std::endl << std::endl;
        std::cout << "[1] " << shopWeaponSlot1.getName() << std::endl;
        std::cout << "[2] " << shopWeaponSlot2.getName() << std::endl;
        std::cout << "[3] " << shopArmorSlot.getName() << std::endl;
        //!FIXME: FIX POTION COUNT FUNCTIONALITY!!!!!!
        std::cout << "[4] " << shopPotionSlot.getName() << std::endl;
        std::cout << "[5] " << shopItemSlot.getName() << std::endl;
        std::cout << "[6] Let me check my inventory" << std::endl;
        std::cout << "[7] I'm done shopping" << std::endl << std::endl;
        std::cout << "Choice: ";
        std::cin >> playerChoice;
        //switch handles error proofing for empty slots and non-menu choices, maintains menu screen until user picks a valid option.
        switch (playerChoice)
        {
            //Weapon Slot 1 
        case 1:
            if (shopWeaponSlot1.getName() == "empty") {
                system("CLS");
                displayShopItems();
                std::cout << "This slot is empty!" << std::endl << std::endl;
                std::cout << std::setw(64) << "====================================================================================" << std::endl << std::endl;
                system("PAUSE");
            }
            else {
                system("CLS");
                std::cout << "Comin' right up!" << std::endl << std::endl;
                system("PAUSE");
                //returns user choice
                return playerChoice;
            }
            break;
            //Weapon Slot 2 
        case 2:
            if (shopWeaponSlot2.getName() == "empty") {
                system("CLS");
                displayShopItems();
                std::cout << "This slot is empty!" << std::endl << std::endl;
                std::cout << std::setw(64) << "====================================================================================" << std::endl << std::endl;
                system("PAUSE");
            }
            else {
                system("CLS");
                std::cout << "Comin' right up!" << std::endl << std::endl;
                system("PAUSE");
                //returns user choice
                return playerChoice;
            }
            break;
            //Armor Slot
        case 3:
            if (shopArmorSlot.getName() == "empty") {
                system("CLS");
                displayShopItems();
                std::cout << "This slot is empty!" << std::endl << std::endl;
                std::cout << std::setw(64) << "====================================================================================" << std::endl << std::endl;
                system("PAUSE");
            }
            else {
                system("CLS");
                std::cout << "Comin' right up!" << std::endl << std::endl;
                system("PAUSE");
                //returns user choice
                return playerChoice;
            }
            break;
            //Potion Slot
        case 4:
            if (shopPotionSlot.getName() == "empty") {
                system("CLS");
                displayShopItems();
                std::cout << "This slot is empty!" << std::endl << std::endl;
                std::cout << std::setw(64) << "====================================================================================" << std::endl << std::endl;
                system("PAUSE");
            }
            else {
                system("CLS");
                std::cout << "Comin' right up!" << std::endl << std::endl;
                system("PAUSE");
                //returns user choice
                return playerChoice;
            }
            break;
            //Item Slot
        case 5:
            if (shopItemSlot.getName() == "empty") {
                system("CLS");
                displayShopItems();
                std::cout << "This slot is empty!" << std::endl << std::endl;
                std::cout << std::setw(64) << "====================================================================================" << std::endl << std::endl;
                system("PAUSE");
            }
            else {
                system("CLS");
                std::cout << "Comin' right up!" << std::endl<<std::endl;
                system("PAUSE");
                //returns user choice
                return playerChoice;
            }
            break;
            //Check inventory
        case 6:
            system("CLS");
            player.getInventory()->display();
            system("PAUSE");
            break;
        case 7:
            system("CLS");
            std::cout << "Dusty shelves beat angry Elves I suppose..." << std::endl<<std::endl;
            system("PAUSE");
            sentinel = 1;
            //returns user choice
            return playerChoice;
            break;
        default:
            system("CLS");
            displayShopItems();
            std::cout << "This is not an option!" << std::endl << std::endl;
            std::cout << std::setw(64) << "====================================================================================" << std::endl << std::endl;
            system("PAUSE");
            break;
        }
    }
}

void shop::sellTo(player& player, int playerChoice) {
    //!FIXME: potentially create empty weapons to switch out shop weapons
    weapon noWeapon;
    armor noArmor;
    potion noPotion;
    item noItem;
    int sentinel = 0;

    //user chooses shopWeaponSlot1
    if (playerChoice == 1) {
        //subtracts gold according to weapon price from player inventory
        player.getInventory()->setCoinCount(player.getInventory()->getCointCount() - shopWeaponSlot1.getCoinValue());
        //replace players weapon with shop weapon of choice
        player.getInventory()->setWeapon(shopWeaponSlot1);
        //!FIXME: MESS WITH CONSTRUCTORS FOR THIS STEP, changes weapon to empty slot and info
        setShopWeaponSlot1(noWeapon);
    }
    //user chooses shopWeaponSlot2
    else if (playerChoice == 2) {
        //subtracts gold according to weapon price from player inventory
        player.getInventory()->setCoinCount(player.getInventory()->getCointCount() - shopWeaponSlot2.getCoinValue());
        //replace players weapon with shop weapon of choice
        player.getInventory()->setWeapon(shopWeaponSlot2);
        //!FIXME: MESS WITH CONSTRUCTORS FOR THIS STEP, changes weapon to empty slot and info
        setShopWeaponSlot2(noWeapon);
    }
    //user chooses shopArmorSlot
    else if (playerChoice == 3) {
        //subtracts gold according to weapon price from player inventory
        player.getInventory()->setCoinCount(player.getInventory()->getCointCount() - shopArmorSlot.getCoinValue());
        //replace players weapon with shop weapon of choice
        player.getInventory()->setArmor(shopArmorSlot);
        //!FIXME: MESS WITH CONSTRUCTORS FOR THIS STEP, changes weapon to empty slot and info
        setShopArmorSlot(noArmor);
    }
    //user chooses shopPotionSlot
    //!FIXME deal with potion counts
    else if (playerChoice == 4) {
        //subtracts gold according to weapon price from player inventory
        player.getInventory()->setCoinCount(player.getInventory()->getCointCount() - shopPotionSlot.getCoinValue());
        //replace players weapon with shop weapon of choice
        player.getInventory()->setPotion(shopPotionSlot);
        //!FIXME: MESS WITH CONSTRUCTORS FOR THIS STEP, changes weapon to empty slot and info
        setShopPotionSlot(noPotion);
    }
    //user chooses shopArmorSlot
    else if (playerChoice == 5) {
        //subtracts gold according to weapon price from player inventory
        player.getInventory()->setCoinCount(player.getInventory()->getCointCount() - shopItemSlot.getCoinValue());
        //replace players weapon with shop weapon of choice
        //ask user which item slot they would like to use to store item
        while (sentinel != 1) {
            std::cout << "Choose an item slot to store this item." << std::endl;
            std::cout << "[1] Item Slot 1" << std::endl;
            std::cout << "[2] Item Slot 2" << std::endl;
            std::cout << "[3] Item Slot 3" << std::endl;
            std::cout << "Choice: ";
            std::cin >> playerChoice;
            //prints error menu if choice is erroneous
            if ((playerChoice < 1) || (playerChoice > 3)) {
                system("CLS");
                std::cout << "This is not an option!" << std::endl;
                system("PAUSE");
                system("CLS");
            }
            else if ((playerChoice >= 1) && (playerChoice <= 3)) {
                sentinel = 1;
            }
        }
        //places shop item that was purchased into the respective item slot of the inventory that the user chooses
        if (playerChoice == 1) {
            player.getInventory()->setItem1(shopItemSlot);
            //!FIXME: MESS WITH CONSTRUCTORS FOR THIS STEP, changes weapon to empty slot and info
            setShopItemSlot(noItem);
        }
        else if (playerChoice == 2) {
            player.getInventory()->setItem2(shopItemSlot);
            //!FIXME: MESS WITH CONSTRUCTORS FOR THIS STEP, changes weapon to empty slot and info
            setShopItemSlot(noItem);
        }
        else if (playerChoice == 3) {
            player.getInventory()->setItem3(shopItemSlot);
            //!FIXME: MESS WITH CONSTRUCTORS FOR THIS STEP, changes weapon to empty slot and info
            setShopItemSlot(noItem);
        }
    }
}

void shop::buyFrom(player& player) {
    //!FIXME: LEFT OFF HERE 04/22/2024
    int userChoice;
    player.getInventory()->display();
    std::cout << "What would you like to sell?" << std::endl << std::endl;
    std::cout << "================================================================" << std::endl << std::endl; //!FIXME: LEFT OFF HERE
    std::cout << std::setw(15) << "[1] " << std::setw(25) << player.getInventory()->getWeapon().getName();
    std::cout << "(" << player.getInventory()->getWeapon().getCoinValue() << "coins)" << std::endl;
    std::cout << std::setw(15) << "[2] " << std::setw(25) << player.getInventory()->getArmor().getName();
    std::cout << "(" << player.getInventory()->getArmor().getCoinValue() << "coins)" << std::endl;
    std::cout << std::setw(15) << "[3] " << std::setw(25) << player.getInventory()->getPotion().getName();
    std::cout << "(" << player.getInventory()->getPotion().getCoinValue() << "coins)" << std::endl;
    std::cout << std::setw(15) << "[4] " << std::setw(25) << player.getInventory()->getItemSlot1().getName();
    std::cout << "(" << player.getInventory()->getItemSlot1().getCoinValue() << "coins)" << std::endl;
    std::cout << std::setw(15) << "[5] " << std::setw(25) << player.getInventory()->getItemSlot2().getName();
    std::cout << "(" << player.getInventory()->getItemSlot2().getCoinValue() << "coins)" << std::endl;
    std::cout << std::setw(15) << "[6] " << std::setw(25) << player.getInventory()->getItemSlot3().getName();
    std::cout << "(" << player.getInventory()->getItemSlot3().getCoinValue() << "coins)" << std::endl << std::endl;
    std::cout << "Choice: ";
    std::cin >> userChoice;

    //!FIXME: FIND ALL PLACES WHERE INVENTORY MENU IS PAUSED
    //!FIXME: ADD IN POTION FUNCTIONALITY NEXT
}

//CHURCH CLASS DEFINITIONS
//constructers
//default constructor
Church::Church() {
    churchName = "Null Church";
    churchType = "Null Church";
    hpToHeal = 0;
    //!FIXME: ADD NPC PRIEST AND OPTIONS TO SPEAK WITH PRIEST, OFFER SACRIFICE ON THE ALTAR, ETC.
}

//initialize object with all custom parameters
Church::Church(std::string churchName, std::string churchType, int hpToHeal) {
    this->churchName = churchName;
    this->churchType = churchType;
    this->hpToHeal = hpToHeal;
}

//getters
std::string Church::getChurchName() { return churchName; }

std::string Church::getChurchType() { return churchType; }

int Church::getHpToHeal() { return hpToHeal; }


//setters
void Church::setChurchName(std::string churchName) { this->churchName = churchName; }

void Church::setChurchType(std::string churchType) { this->churchName = churchType; }

void Church::setHpToHeal(int hpToHeal) { this->hpToHeal = hpToHeal; }

//methods
void Church::enterChurch(player& player) {
    //clear console
    system("CLS");
    //!FIXME: MODEL THIS AFTER ENTERSHOP() FUNCTION
    //! TEST MESSAGE
    std::cout << "TEST: Church entered." << std::endl << std::endl;
    system("PAUSE");

}

void Church::churchWelcome(player& player) {
    int choice = 0;
    std::cout << "Welcome to the " << churchName << ". You feel the presence of grace." << std::endl;
    std::cout << "[1] Pray" << std::endl;
    std::cout << "[2] Leave" << std::endl;
    std::cin >> choice;
    if (choice == 1) {
        pray(player);
    }
    else if (choice==2) {
        //!FIXME: ADD CONTENT
    }

}

void Church::pray(player& player) {
    system("CLS");
    std::cout << "Your prayers have been answered and you feel at peace with the help of grace." << std::endl;
    std::cout << hpToHeal << " has been added. HP: " << player.getHp() + hpToHeal;
    player.setHp(player.getHp() + hpToHeal);
}

//LOUNGE CLASS DEFINITIONS
