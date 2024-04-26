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
    int playerChoice = 0;
    int sentinel = 0;
    //error proofing while loop
    while (sentinel != 1) {
        //execute shop lobby message, returns player's choice in the lobby
        playerChoice = execShopLobbyMenu(player, playerChoice);
        //if-else if branches determine which menu to print depending on player's lobby choice
        //if player chooses to talk with the shop keeper
        if (playerChoice == 1) {
            system("CLS"); //!FIXME: REMOVE THIS, STORE IT IN THE DIALOGUE MENU, ADD DIALOGUE MENU AND DOCUMENTATION
            std::cout << "BEGIN DIALOGUE" << std::endl << std::endl;
            system("PAUSE");
        }
        //if player chooses to check out the shop items
        else if (playerChoice == 2) {
            execShopExchangeMenu(player, playerChoice);
        }
        //if player chooses to exit shop
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

int shop::execShopLobbyMenu(player& player, int& playerChoice) {
    //reset playerChoice so that error-proofing loop may begin
    playerChoice = 0;
    //error-proofing while loop
    while ((playerChoice < 1) || (playerChoice > 3)) {
        //print enter shop menu
        system("CLS");
        std::cout << "Welcome to " << shopName << " stranger! What can I do for ya!" << std::endl << std::endl;
        std::cout << "[1] Talk with shopkeeper" << std::endl;
        std::cout << "[2] Look around the shop" << std::endl;
        std::cout << "[3] Exit" << std::endl << std::endl;
        std::cout << "Choice: ";
        std::cin >> playerChoice;
        //erroneous choice message
        if ((playerChoice < 1) && (playerChoice > 3)) {
            system("CLS");
            std::cout << "This is not an option." << std::endl << std::endl;
            system("PAUSE");
        }
    }
    return playerChoice;
}

void shop::execShopExchangeMenu(player& player, int& playerChoice) {
    //reset playerChoice so that error-proofing loop may begin
    playerChoice = 0;
    //sentinel prevents this menu from closing until uses
    int sentinel = 0;
    //error-proofing while loop
    while (((playerChoice < 1) || (playerChoice > 3)) && (sentinel != 1)) {
        //print enter shop menu
        system("CLS");
        std::cout << "What would you like to do?" << std::endl << std::endl;
        std::cout << "[1] Buy" << std::endl;
        std::cout << "[2] Sell" << std::endl;
        std::cout << "[3] Exit" << std::endl << std::endl;
        std::cout << "Choice: ";
        std::cin >> playerChoice;
        //if-else if branches determine which menu to print depending on player's shop menu choice
        //if player chooses to open shop buy menu
        if (playerChoice == 1) {
            playerChoice = execBuyMenu(player, playerChoice);
        }
        //if player chooses to open shop sell menu
        else if (playerChoice == 2) {
            playerChoice = execSellMenu(player, playerChoice);
        }
        //if player chooses to exit shop menu
        else if (playerChoice == 3) {
            system("CLS");
            std::cout << "Thanks for inquirin'!" << std::endl << std::endl;
            system("PAUSE");
            sentinel = 1;
        }
        //erroneous choice message
        else if ((playerChoice < 1) && (playerChoice > 3)) {
            system("CLS");
            std::cout << "This is not an option." << std::endl << std::endl;
            system("PAUSE");
        }
    }
}

int shop::execBuyMenu(player& player, int& playerChoice) {
    //while the user does not want to exit the buy menu
    while (playerChoice != -1) {
        //display shop items
        displayShopItems();
        //display player options
        playerChoice = displayBuyChoices(player, playerChoice);
        //check player choice
        playerChoice = checkBuyChoice(player, playerChoice);
        //sell to player unless they choose to exit or choose to look at their inventory
        if (playerChoice > 0) {
            sellTo(player, playerChoice);
        }
    }
    return playerChoice;
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

int shop::displayBuyChoices(player& player, int& playerChoice) {
    //reset playerChoice so that error-proofing loop may begin
    playerChoice = 0;
    //error-proofing while loop
    while ((playerChoice < 1) || (playerChoice > 7)) {
        //print player options
        std::cout << "You have " << player.getInventory()->getCointCount() << " coins! " << "What would you like to buy?" << std::endl << std::endl;
        std::cout << std::setw(64) << "====================================================================================" << std::endl << std::endl;
        std::cout << "[1] " << shopWeaponSlot1.getName() << std::endl;
        std::cout << "[2] " << shopWeaponSlot2.getName() << std::endl;
        std::cout << "[3] " << shopArmorSlot.getName() << std::endl;
        //!FIXME: FIX POTION COUNT FUNCTIONALITY!!!!!!
        std::cout << "[4] " << shopPotionSlot.getName() << std::endl;
        std::cout << "[5] " << shopItemSlot.getName() << std::endl;
        std::cout << "[6] Check Inventory" << std::endl;
        std::cout << "[7] Exit" << std::endl << std::endl;
        std::cout << "Choice: ";
        std::cin >> playerChoice;
        //erroneous choice message
        if ((playerChoice < 1) || (playerChoice > 7)) {
            system("CLS");
            std::cout << "This is not an option." << std::endl << std::endl;
            system("PAUSE");
            //reprint shop items
            displayShopItems();
        }
    }
    return playerChoice;
}

/*
*Name: checkBuyChoice(int& player, playerChoice& player)
*Description: Function checks if the player is trying to buy an item from an empty slot and returns this value.
*             Function returns 0 if player chooses an option other than to buy or the slot they are buying from is empty.
*             Function returns -1 if player decides to exit the buy menu.
*/
int shop::checkBuyChoice(player& player, int& playerChoice) {
    //branch to check player choices and determine outcome
    //if player chooses shop weapon slot 1
    if (playerChoice == 1) {
        //if the slot is empty
        if (shopWeaponSlot1.getName() == "empty") {
            system("CLS");
            displayShopItems();
            std::cout << "This slot is empty!" << std::endl << std::endl;
            std::cout << std::setw(64) << "====================================================================================" << std::endl << std::endl;
            system("PAUSE");
            return 0;
        }
        //if the slot is not empty
        else {
            //player coin check to validate if the user has enough coin for something
            //if user does not have enough coin
            if (shopWeaponSlot1.getCoinValue() > player.getInventory()->getCointCount()) {
                system("CLS");
                displayShopItems();
                std::cout << "You do not have enough coin for that." << std::endl << std::endl;
                std::cout << std::setw(64) << "====================================================================================" << std::endl << std::endl;
                system("PAUSE");
                return 0;
            }
            //if user has enough or more than enough coin
            else if (shopWeaponSlot1.getCoinValue() <= player.getInventory()->getCointCount()) {
                system("CLS");
                std::cout << "Comin' right up!" << std::endl << std::endl;
                system("PAUSE");
                //returns player choice
                return playerChoice;
            }
        }
    }
    //if player chooses shop weapon slot 2
    else if (playerChoice == 2) {
        //if the slot is empty
        if (shopWeaponSlot2.getName() == "empty") {
            system("CLS");
            displayShopItems();
            std::cout << "This slot is empty!" << std::endl << std::endl;
            std::cout << std::setw(64) << "====================================================================================" << std::endl << std::endl;
            system("PAUSE");
            return 0;
        }
        //if the slot is not empty
        else {
            //player coin check to validate if the user has enough coin for something
            //if user does not have enough coin
            if (shopWeaponSlot2.getCoinValue() > player.getInventory()->getCointCount()) {
                system("CLS");
                displayShopItems();
                std::cout << "You do not have enough coin for that." << std::endl << std::endl;
                std::cout << std::setw(64) << "====================================================================================" << std::endl << std::endl;
                system("PAUSE");
                return 0;
            }
            //if user has enough or more than enough coin
            else if (shopWeaponSlot2.getCoinValue() <= player.getInventory()->getCointCount()) {
                system("CLS");
                std::cout << "Comin' right up!" << std::endl << std::endl;
                system("PAUSE");
                //returns player choice
                return playerChoice;
            }
        }
    }
    //if player chooses shop armor slot
    else if (playerChoice == 3) {
        //if the slot is empty
        if (shopArmorSlot.getName() == "empty") {
            system("CLS");
            displayShopItems();
            std::cout << "This slot is empty!" << std::endl << std::endl;
            std::cout << std::setw(64) << "====================================================================================" << std::endl << std::endl;
            system("PAUSE");
            return 0;
        }
        //if the slot is not empty
        else {
            //player coin check to validate if the user has enough coin for something
            //if user does not have enough coin
            if (shopArmorSlot.getCoinValue() > player.getInventory()->getCointCount()) {
                system("CLS");
                displayShopItems();
                std::cout << "You do not have enough coin for that." << std::endl << std::endl;
                std::cout << std::setw(64) << "====================================================================================" << std::endl << std::endl;
                system("PAUSE");
                return 0;
            }
            //if user has enough or more than enough coin
            else if (shopArmorSlot.getCoinValue() <= player.getInventory()->getCointCount()) {
                system("CLS");
                std::cout << "Comin' right up!" << std::endl << std::endl;
                system("PAUSE");
                //returns player choice
                return playerChoice;
            }
        }
    }
    //if player chooses shop potion slot
    else if (playerChoice == 4) {
        //if the slot is empty
        if (shopPotionSlot.getName() == "empty") {
            system("CLS");
            displayShopItems();
            std::cout << "This slot is empty!" << std::endl << std::endl;
            std::cout << std::setw(64) << "====================================================================================" << std::endl << std::endl;
            system("PAUSE");
            return 0;
        }
        //if the slot is not empty
        else {
            //player coin check to validate if the user has enough coin for something
            //if user does not have enough coin
            if (shopPotionSlot.getCoinValue() > player.getInventory()->getCointCount()) {
                system("CLS");
                displayShopItems();
                std::cout << "You do not have enough coin for that." << std::endl << std::endl;
                std::cout << std::setw(64) << "====================================================================================" << std::endl << std::endl;
                system("PAUSE");
                return 0;
            }
            //if user has enough or more than enough coin
            else if (shopPotionSlot.getCoinValue() <= player.getInventory()->getCointCount()) {
                //!FIXME: INSERT HOW MANY POTIONS YOU WANNA BUY? MENU!!!!!
                system("CLS");
                std::cout << "Comin' right up!" << std::endl << std::endl;
                system("PAUSE");
                //returns player choice
                return playerChoice;
            }
        }
    }
    //if player chooses shop item slot
    else if (playerChoice == 5) {
        //if the slot is empty
        if (shopItemSlot.getName() == "empty") {
            system("CLS");
            displayShopItems();
            std::cout << "This slot is empty!" << std::endl << std::endl;
            std::cout << std::setw(64) << "====================================================================================" << std::endl << std::endl;
            system("PAUSE");
            return 0;
        }
        //if the slot is not empty
        else {
            //player coin check to validate if the user has enough coin for something
            //if user does not have enough coin
            if (shopItemSlot.getCoinValue() > player.getInventory()->getCointCount()) {
                system("CLS");
                displayShopItems();
                std::cout << "You do not have enough coin for that." << std::endl << std::endl;
                std::cout << std::setw(64) << "====================================================================================" << std::endl << std::endl;
                system("PAUSE");
                return 0;
            }
            //if user has enough or more than enough coin
            else if (shopItemSlot.getCoinValue() <= player.getInventory()->getCointCount()) {
                //returns player choice for later menu in sellTo which asks which item slot the player wants to store their item in
                return playerChoice;
            }
        }
    }
    //if player chooses to check their inventory
    else if (playerChoice == 6) {
        player.getInventory()->display();
        system("PAUSE");
        return 0;
    }
    //if player chooses to leave the shop buy menu
    else if (playerChoice == 7) {
        system("CLS");
        std::cout << "Dusty shelves beat angry Elves I suppose..." << std::endl << std::endl;
        system("PAUSE");
        return -1;
    }
}

/*
* Name: sellTo(player& player, int& playerChoice)
*Description: Function replaces validated shop item that the user chose to purchase with an empty item of its type.
*             Function places validated purchased item into respective player inventory item slot for use.
*/
void shop::sellTo(player& player, int& playerChoice) {
    //!FIXME: potentially create empty weapons to switch out shop weapons
    weapon noWeapon;
    armor noArmor;
    potion noPotion;
    item noItem;
    int sentinel = 0;

    //player chooses shopWeaponSlot1
    if (playerChoice == 1) {
        //subtracts gold according to weapon price from player inventory
        player.getInventory()->setCoinCount(player.getInventory()->getCointCount() - shopWeaponSlot1.getCoinValue());
        //replace players weapon with shop weapon of choice
        player.getInventory()->setWeapon(shopWeaponSlot1);
        //!FIXME: MESS WITH CONSTRUCTORS FOR THIS STEP, changes weapon to empty slot and info
        setShopWeaponSlot1(noWeapon);
    }
    //player chooses shopWeaponSlot2
    else if (playerChoice == 2) {
        //subtracts gold according to weapon price from player inventory
        player.getInventory()->setCoinCount(player.getInventory()->getCointCount() - shopWeaponSlot2.getCoinValue());
        //replace players weapon with shop weapon of choice
        player.getInventory()->setWeapon(shopWeaponSlot2);
        //!FIXME: MESS WITH CONSTRUCTORS FOR THIS STEP, changes weapon to empty slot and info
        setShopWeaponSlot2(noWeapon);
    }
    //player chooses shopArmorSlot
    else if (playerChoice == 3) {
        //subtracts gold according to weapon price from player inventory
        player.getInventory()->setCoinCount(player.getInventory()->getCointCount() - shopArmorSlot.getCoinValue());
        //replace players weapon with shop weapon of choice
        player.getInventory()->setArmor(shopArmorSlot);
        //!FIXME: MESS WITH CONSTRUCTORS FOR THIS STEP, changes weapon to empty slot and info
        setShopArmorSlot(noArmor);
    }
    //player chooses shopPotionSlot
    //!FIXME deal with potion counts
    else if (playerChoice == 4) {
        //subtracts gold according to weapon price from player inventory
        player.getInventory()->setCoinCount(player.getInventory()->getCointCount() - shopPotionSlot.getCoinValue());
        //replace players weapon with shop weapon of choice
        player.getInventory()->setPotion(shopPotionSlot);
        //!FIXME: MESS WITH CONSTRUCTORS FOR THIS STEP, changes weapon to empty slot and info
        setShopPotionSlot(noPotion);
    }
    //player chooses shopArmorSlot
    else if (playerChoice == 5) {
        //subtracts gold according to weapon price from player inventory
        player.getInventory()->setCoinCount(player.getInventory()->getCointCount() - shopItemSlot.getCoinValue());
        //replace players weapon with shop weapon of choice
        //ask player which item slot they would like to use to store item
        while (sentinel != 1) {
            system("CLS");
            std::cout << "Great! Choose an item slot to store this item." << std::endl;
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
        //places shop item that was purchased into the respective item slot of the inventory that the player chooses
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

int shop::execSellMenu(player& player, int& playerChoice) {
    //while the user does not want to exit the buy menu
    while (playerChoice != -1) {
        //print inventory sell options
        player.getInventory()->display();
        //display sell options
        displaySellChoices(player, playerChoice);
        //check player choice
        playerChoice = checkSellChoice(player, playerChoice);
        //sell to player unless they choose to exit or choose to look at their inventory
        if (playerChoice > 0) {
            buyFrom(player, playerChoice);
        }
    }
    return playerChoice;
}

int shop::displaySellChoices(player& player, int& playerChoice) {
    //reset playerChoice so that error-proofing loop may begin
    playerChoice = 0;
    //error-proofing while loop
    while ((playerChoice < 1) || (playerChoice > 7)) {
        std::cout << "What would you like to sell? You\'ve got " << player.getInventory()->getCointCount() << " coins right now." << std::endl << std::endl;
        std::cout << "================================================================" << std::endl << std::endl; //!FIXME: LEFT OFF HERE
        std::cout << "[1] " << std::setw(25) << player.getInventory()->getWeapon().getName();
        std::cout << "(" << player.getInventory()->getWeapon().getCoinValue() << " coins)" << std::endl;
        std::cout << "[2] " << std::setw(25) << player.getInventory()->getArmor().getName();
        std::cout << "(" << player.getInventory()->getArmor().getCoinValue() << " coins)" << std::endl;
        std::cout << "[3] " << std::setw(25) << player.getInventory()->getPotionDisplayString();
        std::cout << "(" << player.getInventory()->getPotion()->getCoinValue() << " coins)" << std::endl;
        std::cout << "[4] " << std::setw(25) << player.getInventory()->getItemSlot1().getName();
        std::cout << "(" << player.getInventory()->getItemSlot1().getCoinValue() << " coins)" << std::endl;
        std::cout << "[5] " << std::setw(25) << player.getInventory()->getItemSlot2().getName();
        std::cout << "(" << player.getInventory()->getItemSlot2().getCoinValue() << " coins)" << std::endl;
        std::cout << "[6] " << std::setw(25) << player.getInventory()->getItemSlot3().getName();
        std::cout << "(" << player.getInventory()->getItemSlot3().getCoinValue() << " coins)" << std::endl;
        std::cout << "[7] Exit" << std::endl << std::endl;
        std::cout << "Choice: ";
        std::cin >> playerChoice;
        //erroneous choice message
        if ((playerChoice < 1) || (playerChoice > 7)) {
            system("CLS");
            std::cout << "This is not an option." << std::endl << std::endl;
            system("PAUSE");
            //reprint inventory sell options
            player.getInventory()->display();
        }
    }
    return playerChoice;
}

int shop::checkSellChoice(player& player, int& playerChoice) {
    //branch to check player choices and determine outcome
    //if player chooses to sell their weapon
    if (playerChoice == 1) {
        //if the slot is empty
        if (player.getInventory()->getWeapon().getName() == "empty") {
            system("CLS");
            player.getInventory()->display();
            std::cout << "This slot is empty!" << std::endl << std::endl;
            std::cout << "================================================================" << std::endl << std::endl;
            system("PAUSE");
            return 0;
        }
        //if the slot is not empty
        else {
            system("CLS");
            std::cout << "Great! Here's your coin!" << std::endl << std::endl;
            system("PAUSE");
            //returns player choice
            return playerChoice;
        }
    }
    //if player chooses to sell their armor
    else if (playerChoice == 2) {
        //if the slot is empty
        if (player.getInventory()->getArmor().getName() == "empty") {
            system("CLS");
            player.getInventory()->display();
            std::cout << "This slot is empty!" << std::endl << std::endl;
            std::cout << "================================================================" << std::endl << std::endl;
            system("PAUSE");
            return 0;
        }
        //if the slot is not empty
        else {
            system("CLS");
            std::cout << "Great! Here's your coin!" << std::endl << std::endl;
            system("PAUSE");
            //returns player choice
            return playerChoice;
        }
    }
    //if player chooses to sell their potion(s)
    else if (playerChoice == 3) {
        //if the slot is empty
        //!FIXME: INSERT HOW MANY POTIONS YOU WANNA SELL? MENU!!!!!
        if (player.getInventory()->getPotion()->getName() == "empty") {
            system("CLS");
            player.getInventory()->display();
            std::cout << "This slot is empty!" << std::endl << std::endl;
            std::cout << "================================================================" << std::endl << std::endl;
            system("PAUSE");
            return 0;
        }
        //if the slot is not empty
        else {
            system("CLS");
            std::cout << "Great! Here's your coin!" << std::endl << std::endl;
            system("PAUSE");
            //returns player choice
            return playerChoice;
        }
    }
    //if player chooses to sell item 1
    else if (playerChoice == 4) {
        //if the slot is empty
        if (player.getInventory()->getItemSlot1().getName() == "empty") {
            system("CLS");
            player.getInventory()->display();
            std::cout << "This slot is empty!" << std::endl << std::endl;
            std::cout << "================================================================" << std::endl << std::endl;
            system("PAUSE");
            return 0;
        }
        //if the slot is not empty
        else {
            system("CLS");
            std::cout << "Great! Here's your coin!" << std::endl << std::endl;
            system("PAUSE");
            //returns player choice
            return playerChoice;
        }
    }
    //if player chooses to sell item 2
    else if (playerChoice == 5) {
        //if the slot is empty
        if (player.getInventory()->getItemSlot2().getName() == "empty") {
            system("CLS");
            player.getInventory()->display();
            std::cout << "This slot is empty!" << std::endl << std::endl;
            std::cout << "================================================================" << std::endl << std::endl;
            system("PAUSE");
            return 0;
        }
        //if the slot is not empty
        else {
            system("CLS");
            std::cout << "Great! Here's your coin!" << std::endl << std::endl;
            system("PAUSE");
            //returns player choice
            return playerChoice;
        }
    }
    //if player chooses to sell item 3
    else if (playerChoice == 6) {
        //if the slot is empty
        if (player.getInventory()->getItemSlot3().getName() == "empty") {
            system("CLS");
            player.getInventory()->display();
            std::cout << "This slot is empty!" << std::endl << std::endl;
            std::cout << "================================================================" << std::endl << std::endl;
            system("PAUSE");
            return 0;
        }
        //if the slot is not empty
        else {
            system("CLS");
            std::cout << "Great! Here's your coin!" << std::endl << std::endl;
            system("PAUSE");
            //returns player choice
            return playerChoice;
        }
    }
    //if player chooses to leave the shop buy menu
    else if (playerChoice == 7) {
        system("CLS");
        std::cout << "More coin for me!" << std::endl << std::endl;
        system("PAUSE");
        return -1;
    }
}

/*
* Name: buyFrom(player& player, int& playerChoice)
* Description:
* 
*/
void shop::buyFrom(player& player, int& playerChoice) {
    weapon noWeapon;
    armor noArmor;
    potion noPotion;
    item noItem;

    //player chooses to sell their weapon
    if (playerChoice == 1) {
        //increase player gold by weapon gold value
        player.getInventory()->setCoinCount(player.getInventory()->getCointCount() + player.getInventory()->getWeapon().getCoinValue());
        //set player inventory weapon to noWeapon
        player.getInventory()->setWeapon(noWeapon);
    }
    //player chooses to sell their armor
    else if (playerChoice == 2) {
        //increase player gold by weapon gold value
        player.getInventory()->setCoinCount(player.getInventory()->getCointCount() + player.getInventory()->getArmor().getCoinValue());
        //set player inventory weapon to noWeapon
        player.getInventory()->setArmor(noArmor);
    }
    //player chooses to sell their potion
    else if (playerChoice == 3) {
        //increase player gold by weapon gold value
        player.getInventory()->setCoinCount(player.getInventory()->getCointCount() + player.getInventory()->getPotion()->getCoinValue());
        //set player inventory weapon to noWeapon
        player.getInventory()->setPotion(noPotion);
    }
    //player chooses to sell item 1
    else if (playerChoice == 4) {
        //if item 1 is a quest item
        if (player.getInventory()->getItemSlot1().getIsQuestItem() == true) {
            system("CLS");
            std::cout << "You can't sell that! It is a quest item." << std::endl << std::endl;
            system("PAUSE");
        }
        //if item 1 is not a quest item
        else if (player.getInventory()->getItemSlot1().getIsQuestItem() == false) {
            //increase player gold by weapon gold value
            player.getInventory()->setCoinCount(player.getInventory()->getCointCount() + player.getInventory()->getItemSlot1().getCoinValue());
            //set player inventory weapon to noWeapon
            player.getInventory()->setItem1(noItem);
        }
    }
    //player chooses to sell item 2
    else if (playerChoice == 5) {
        //if item 2 is a quest item
        if (player.getInventory()->getItemSlot2().getIsQuestItem() == true) {
            system("CLS");
            std::cout << "You can't sell that! It is a quest item." << std::endl << std::endl;
            system("PAUSE");
        }
        //if item 2 is not a quest item
        else if (player.getInventory()->getItemSlot2().getIsQuestItem() == false) {
            //increase player gold by weapon gold value
            player.getInventory()->setCoinCount(player.getInventory()->getCointCount() + player.getInventory()->getItemSlot2().getCoinValue());
            //set player inventory weapon to noWeapon
            player.getInventory()->setItem2(noItem);
        }
    }
    //player chooses to sell item 3
    else if (playerChoice == 6) {
        //if item 3 is a quest item
        if (player.getInventory()->getItemSlot3().getIsQuestItem() == true) {
            system("CLS");
            std::cout << "You can't sell that! It is a quest item." << std::endl << std::endl;
            system("PAUSE");
        }
        //if item 3 is not a quest item
        else if (player.getInventory()->getItemSlot3().getIsQuestItem() == false) {
            //increase player gold by weapon gold value
            player.getInventory()->setCoinCount(player.getInventory()->getCointCount() + player.getInventory()->getItemSlot3().getCoinValue());
            //set player inventory weapon to noWeapon
            player.getInventory()->setItem3(noItem);
        }
    }

    //!FIXME: LEFT OFF HERE 04/24/2024 , ADD POTION FUNCTIONALITY WITH POTION.USE(), SET POTION COUNT, MOVE POTION COUNT TO POTION CLASS, SHOP MENU "HOW MANY POTIONS YOU WANNA BUY?"

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
