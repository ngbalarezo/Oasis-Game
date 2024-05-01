#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include <string>
#include <random>
#include <windows.h>
#include <stdlib.h>
#include "menu.h"
#include "map.h"
#include "locations.h"
#include "buildings.h"
#include "characters.h"
#include "inventory.h"
#include "items.h"
#include "resource.h"

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

std::string shop::getPotionDisplayString() {
    //return only potion name if the potionSlot is empty
    if (shopPotionSlot.getPotionCount() == 0) {
        //will return "empty"
        return shopPotionSlot.getName(); //!FIXME: MAKE SURE THAT IF POTION COUNT IS 0 THEN NAME CHANGES TO EMPTY/NOPOTION BECOMES POTIONSLOT
    }
    //return 
    else if (shopPotionSlot.getPotionCount() > 0) {
        return shopPotionSlot.getName() + " x" + std::to_string(shopPotionSlot.getPotionCount());
    }
}

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
    std::cout << std::setw(15) << "Potion: " << std::setw(25) << getPotionDisplayString() << std::setw(15) << "n/a" << std::setw(15) << shopPotionSlot.getCoinValue();
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
            //enters secondary potion menu in sellTo function
            return playerChoice;
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
        //changes weapon to empty slot and info
        setShopWeaponSlot1(noWeapon);
    }
    //player chooses shopWeaponSlot2
    else if (playerChoice == 2) {
        //subtracts gold according to weapon price from player inventory
        player.getInventory()->setCoinCount(player.getInventory()->getCointCount() - shopWeaponSlot2.getCoinValue());
        //replace players weapon with shop weapon of choice
        player.getInventory()->setWeapon(shopWeaponSlot2);
        //changes weapon to empty slot and info
        setShopWeaponSlot2(noWeapon);
    }
    //player chooses shopArmorSlot
    else if (playerChoice == 3) {
        //subtracts gold according to armor price from player inventory
        player.getInventory()->setCoinCount(player.getInventory()->getCointCount() - shopArmorSlot.getCoinValue());
        //replace players armor with shop armor of choice
        player.getInventory()->setArmor(shopArmorSlot);
        //changes armor to empty slot and info
        setShopArmorSlot(noArmor);
    }
    //player chooses shopPotionSlot
    else if (playerChoice == 4) {
        int sentinel = 0;
        int desiredPotionCount = 0;
        //calculate and store potion individual price as determined by object constructor passed value
        int potionIndividualPrice = shopPotionSlot.getCoinValue() / shopPotionSlot.getPotionCount();
        //prompt user to decide how many potions they'd like to buy
        while (sentinel != 1) {
            system("CLS");
            displayShopItems();
            std::cout << "How many potions would you like to buy? We've got " << shopPotionSlot.getPotionCount() << "!" << std::endl << std::endl;
            std::cout << std::setw(64) << "====================================================================================" << std::endl << std::endl;
            std::cout << "Insert count: ";
            std::cin >> desiredPotionCount;
            //prints error menu if choice is erroneous
            if ((desiredPotionCount < 1) || (desiredPotionCount > shopPotionSlot.getPotionCount())) {
                system("CLS");
                std::cout << "This is not an option!" << std::endl << std::endl;
                system("PAUSE");
                system("CLS");
            }
            else if ((desiredPotionCount >= 1) && (desiredPotionCount <= shopPotionSlot.getPotionCount())) {
                sentinel = 1;
            }
        }
        //player coin check to validate if the user has enough coin for something, take desired count and multiply by the potionIndividual price for validation boundaries
        //if user does not have enough coin
        if ((potionIndividualPrice * desiredPotionCount) > (player.getInventory()->getCointCount())) {
            system("CLS");
            displayShopItems();
            std::cout << "You do not have enough coin for that." << std::endl << std::endl;
            std::cout << std::setw(64) << "====================================================================================" << std::endl << std::endl;
            system("PAUSE");
        }
        //if user has enough or more than enough coin
        else if ((potionIndividualPrice * desiredPotionCount) <= (player.getInventory()->getCointCount())) {
            //success message
            system("CLS");
            std::cout << "Comin' right up!" << std::endl << std::endl;
            system("PAUSE");
            //subtracts gold according to potion price from player inventory
            player.getInventory()->setCoinCount(player.getInventory()->getCointCount() - (potionIndividualPrice * desiredPotionCount));
            //replace players potion with shop potion of choice
            player.getInventory()->setPotion(shopPotionSlot);
            //set proper potion count and value in player inventory
            player.getInventory()->getPotion()->setPotionCount(desiredPotionCount);
            player.getInventory()->getPotion()->setCoinValue((potionIndividualPrice * desiredPotionCount));
            //if the player does not buy all the potions in the shop
            if (desiredPotionCount < shopPotionSlot.getPotionCount()) {
                //set the number and value of potions in the shop appropriately
                shopPotionSlot.setPotionCount(shopPotionSlot.getPotionCount() - desiredPotionCount);
                shopPotionSlot.setCoinValue(shopPotionSlot.getPotionCount() * potionIndividualPrice);
            }
            else if (desiredPotionCount == shopPotionSlot.getPotionCount()) {
                //changes potion to empty slot and info
                setShopPotionSlot(noPotion);
            }
        }
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
                std::cout << "This is not an option!" << std::endl << std::endl;
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
            //changes item to empty slot and info
            setShopItemSlot(noItem);
        }
        else if (playerChoice == 2) {
            player.getInventory()->setItem2(shopItemSlot);
            //changes item to empty slot and info
            setShopItemSlot(noItem);
        }
        else if (playerChoice == 3) {
            player.getInventory()->setItem3(shopItemSlot);
            //changes item to empty slot and info
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
    std::cout << "[2] Offer Weapon" << std::endl;
    std::cout << "[3] Leave" << std::endl;
    std::cin >> choice;
    if (choice == 1) {
        pray(player);
    }
    else if (choice==2) {
        offerWeapon(player);
    }
}

void Church::pray(player& player) {
    system("CLS");
    std::cout << "Your prayers have been answered and you feel at peace with the help of grace." << std::endl;
    std::cout << hpToHeal << " has been added. HP: " << player.getHp() + hpToHeal << std::endl << std::endl;
    player.setHp(player.getHp() + hpToHeal);
    system("PAUSE");
    system("CLS");
}

void Church::offerWeapon(player& player) {
    int playerChoice = 0;
    system("CLS");
    player.getInventory()->churchDisplay();
    std::cout << "What item would you like to offer?";
    std::cin >> playerChoice;
    std::cout << std::endl << std::endl;
    system("CLS");
    if (playerChoice == 1) {
        player.getInventory()->getWeapon().setAtk((player.getInventory()->getWeapon().getAtk()) + 5);
    }
    if (playerChoice == 2) {
        player.getInventory()->getArmor().setDef((player.getInventory()->getArmor().getDef()) + 5);
    }
    player.getInventory()->churchDisplay();
    system("PAUSE");
    system("CLS");

};


//LOUNGE CLASS DEFINITIONS
//constructers
//default constructor
lounge::lounge() {
    
    //create objects
    npc noBartender;
    npc noPlotDriver;
    npc noWisdomDriver;
    drink noDrink;
    
    
    

    //create null item objects
    loungeName = "Null lounge";
    loungeType = "Null lounge";
    bartender = noBartender;
    wisdomDriver = noWisdomDriver;
    plotDriver = noPlotDriver;
    drinkSlot1 = noDrink;
    drinkSlot2 = noDrink;
   
    
    //!FIXME: ADD NPC PRIEST AND OPTIONS TO SPEAK WITH PRIEST, OFFER SACRIFICE ON THE ALTAR, ETC.
}

//initialize object with all custom parameters
lounge::lounge(std::string loungeName, std::string loungeType, npc bartender, npc plotDriver, npc wisdomDriver, drink drinkSlot1, drink drinkkSlot2) {
    this->loungeName = loungeName;
    this->loungeType = loungeType;
    this->bartender = bartender;
    this->plotDriver = plotDriver;
    this->wisdomDriver = wisdomDriver;
    this->drinkSlot1 = drinkSlot1;
    this->drinkSlot2 = drinkSlot2;
}

//getters
std::string lounge::getLoungeName() { return loungeName; }

std::string lounge::getLoungeType() { return loungeType; }

npc lounge::getBartender() { return bartender; }

npc lounge::getWisdomDriver() { return wisdomDriver; }

npc lounge::getPlotDriver() { return plotDriver; }

drink lounge::getDrinkSlot1() { return drinkSlot1; }

drink lounge::getDrinkSlot2() { return drinkSlot2; }

std::string lounge::getDrinkDisplayString() {
    //return only drink name if the drinkSlot is empty
    if (drinkSlot1.getDrinkCount() == 0) {
        //will return "empty"
        return drinkSlot1.getDrinkName(); //!FIXME: MAKE SURE THAT IF POTION COUNT IS 0 THEN NAME CHANGES TO EMPTY/NOPOTION BECOMES POTIONSLOT
    }
    //return 
    else if (drinkSlot1.getDrinkCount() > 0) {
        return drinkSlot1.getDrinkName() + " x" + std::to_string(drinkSlot1.getDrinkCount());
    }
}




//setters
void lounge::setLoungeName(std::string churchName) { this->loungeName = loungeName; }

void lounge::setLoungeType(std::string loungeType) { this->loungeType = loungeType; }

void lounge::setBartender(npc bartender) { this->bartender = bartender; }

void lounge::setWisdomDriver(npc wisdomDriver) { this->wisdomDriver = wisdomDriver; }

void lounge::setPlotDriver(npc plotDriver) { this->plotDriver = plotDriver; }

void lounge::setDrinkSlot1(drink drinkSlot1) { this->drinkSlot1 = drinkSlot1; }

void lounge::setDrinkSlot2(drink drinkSlot2) { this->drinkSlot2 = drinkSlot2; }

//methods

void lounge::enterLounge(player& player) {
    
    //declare variables
    int playerChoice = 0;
    int sentinel = 0;
    //error proofing while loop
    while (sentinel != 1) {
        //execute lounge lobby message, returns player's choice in the lobby
        playerChoice = execLoungeLobbyMenu(player, playerChoice);

        //if-else if branches determine which menu to print depending on player's lobby choice
        
        //if player chooses to talk to shadowy man
        if (playerChoice == 1) {
            system("CLS"); //!FIXME: REMOVE THIS, STORE IT IN THE DIALOGUE MENU, ADD DIALOGUE MENU AND DOCUMENTATION
            std::vector<std::vector<std::string>> shadowyManDialogue = {
                //node 0
                {"Shadowy Man: Hello young lad, what brings you here?", "Hi there sir. Where am I?", "Hey there, sir. Do you have any wisdom that can help me ? "},
                //node 1
                {"Ah, you find yourself in a realm where the echoes of the past linger in every shadow.", "How do I uncover these echoes of the past?", "Are these echoes tied to a specific event or legend?"},
                //node 2
                {"To find your way in this world, you must listen to the echoes of the past, which linger in every shadow.", "How can I reveal the echoes from the past ?","Do these echoes have a connection to a particular event or legend?"},
                //node3
                {"To uncover the echos of past, seek the forgotten places. They hold the keys to ancient truths.","Keys to ancient truths?","Forgotten places?"},
                //node4
                {"Indeed, they are echoes of a long-forgotten tale, a saga of valor and betrayal woven into the very fabric of our history.","Valor and betrayal?","Could you share more details about this tale?"},
                //node5
                {"To uncover the past, seek the forgotten places. They hold the keys to ancient truths.","Keys to ancient truths?","Forgotten places?"},
                //node6
                {"Certainly, they echo a tale lost to time, a narrative of courage and deceit entwined within our historical tapestry.","Valor and betrayal?"," Could you share more details about this tale?"},
                //node7
                {"To unravel the keys of ancient truths, one must tread the paths of knowledge and virtue. I suggest seeking wisdom in the church or delving into the ancient tomes within the library. Only through understanding and purity of heart can the secrets of the past be revealed.","Secrets of the past?","Keys of ancient truths?"},
                //node8
                {"Ah, yes. The forgotten places are not merely physical locations but gateways to worlds beyond our own. The unseen forgotten places can only be unveiled through the exploration of the seen forgotten places. They are intertwined, each holding a piece of the puzzle to unlock the truths you seek.", "Worlds beyond our own?","What is the truth?"},
                //node9
                {"Centuries ago, when this realm was but a fledgling land, there lived a mighty sorcerer known for his mastery of the arcane arts. He sought to protect the realm from dark forces by creating a powerful gemstone infused with the essence of pure magic. This gemstone, was said to possess the ability to unlock paths to realms beyond, a safeguard against the encroaching darkness. However, as the relic's creation neared completion, whispers of greed and ambition crept into the hearts of those entrusted with its safekeeping. One among them, a trusted guardian turned traitor, sought to claim the gem's power for selfish gain.In a desperate act of betrayal, he stole the gem.It's power however, can only be utilized by those of pure heart and intention. Angered by this, the traitor hid the gem so that the passage to the new world would become forever blocked. Only those who prove themselves worthy and pure of heart can uncover it and  harness its power.","How can I prove myself worthy?","What is this next world you speak of?"},
                //node10
                {"Centuries ago, in the early days of this realm's existence, a formidable sorcerer renowned for his mastery of magic dwelled within these lands. Recognizing the looming threat of dark forces, he dedicated himself to crafting a potent gemstone infused with pure magical essence. This gem, hidden deep within the ancient ruins, possessed the extraordinary ability to unlock pathways to distant realms, serving as a bulwark against encroaching darkness. Yet, as the sorcerer's work neared completion, whispers of greed and ambition infiltrated the hearts of those tasked with safeguarding the gem.Among them, a once - loyal guardian succumbed to temptation, betraying his trust and stealing the gem for selfish gain.It's power however, can only be utilized by those of pure heart and intention.In an act of desperation, he concealed the gem within a maze of deceptive illusions, ensuring that only those of genuine virtue and purity could unveil its secrets and wield its formidable power.","How do I navigate the maze of deceptive illusions","What is the truth?"},
                //node11
                {"To unravel the keys of ancient truths, one must tread the paths of knowledge and virtue. I suggest seeking wisdom in the church or delving into the ancient tomes within the library. Only through understanding and purity of heart can the secrets of the past be revealed.","Secrets of the past?","keys of ancient truths?"},
                //node12
                {"Ah, yes. The forgotten places are not merely physical locations but gateways to worlds beyond our own. The unseen forgotten places can only be unveiled through the exploration of the seen forgotten places. They are intertwined, each holding a piece of the puzzle to unlock the truths you seek.","Worlds beyond our own??","What is the truth?"},
                //node13
                {"Many centuries ago, in the early days of this realm's existence, there lived a renowned sorcerer skilled in the arcane arts. His aim was to shield our realm from looming darkness by crafting a potent gem infused with pure magical essence. This gem was rumored to unlock pathways to distant realms, a defense against encroaching threats. However, as the gem's completion drew near, whispers of greed and ambition tainted those entrusted with its safekeeping. A trusted guardian turned traitor, driven by selfish desires, stole the gem. Its power, however, can only be wielded by those with pure intentions. Enraged, the traitor concealed the gem, blocking the passage to the new world. Only those of genuine virtue can uncover it and harness its formidable power.", "How can I prove myself worthy?","What is within this next world?"},
                //node14
                {"Centuries ago, in the early days of this realm's existence, a formidable sorcerer renowned for his mastery of magic dwelled within these lands. Recognizing the looming threat of dark forces, he dedicated himself to crafting a potent gemstone infused with pure magical essence. This gem, hidden deep within the ancient ruins, possessed the extraordinary ability to unlock pathways to distant realms, serving as a bulwark against encroaching darkness. Yet, as the sorcerer's work neared completion, whispers of greed and ambition infiltrated the hearts of those tasked with safeguarding the gem. Among them, a once-loyal guardian succumbed to temptation, betraying his trust and stealing the gem for selfish gain. It's power however, can only be utilized by those of pure heart and intention.In an act of desperation, he concealed the gem within a maze of deceptive illusions, ensuring that only those of genuine virtue and purity could unveil its secrets and wield its formidable power.","How do I navigate the maze of deceptive illusions?","What is the truth?"},
                //node15
                {"I've already spoken more than I should. It's time for you to find your own path and uncover the truths that await you.","",""},
                //node16
                {"I have divulged more than intended. It is time for you to forge your path and discover the rest on your own.","",""},
                //node17
                {"Enough for now, young traveler. Some secrets are best unraveled in due time. You must seek wisdom elsewhere, for I have already shared more than intended.","",""},
                //node18
                {"The truth lies within the library.I have already revealed more than intended. Go on now young adventurer, for there is much more in store for you","",""},
                //node19
                {"I have already revealed more than intended. You will find more wisdom in the library. But more importantly, go to the church. To purify yourself will shelter you from the darkness ahead .Go on weary traveler, for your quest is but a great one.","",""},
                //node20
                {"I have already revealed more than intended. The last thing I shall say is go to the church. You must go there and purify yourself before advancing on this quest. Go on, for your quest is of great importance to not only yourself, but for the safety of the entire universe.","","" },
                //node21
                {"I have already revealed more than intended. You will find more wisdom in the library. But more importantly, go to the church. An unclean spirit will make it impossible for you to withstand the darkness that lies ahead. Go on weary traveler, for your quest is but a great one.","",""},
                //node22
                {"I have already revealed more than intended. The last thing I shall say is go to the church. You must go there and purify yourself before advancing on this quest. Go on, for your quest is of great importance to not only yourself, but for the safety of the entire universe.","",""},
                //node23
                {"I've already spoken more than I should. It's time for you to find your own path and uncover the truths that await you.","",""},
                //node24
                {"I have divulged more than intended. It is time for you to forge your path and discover the rest on your own.","",""},
                //node25
                {"Enough for now, young traveler. Some secrets are best unraveled in due time. You must wisdom elsewhere, for I have already shared more than intended.","",""},
                //node26
                {"The truth lies within the library. I have already revealed more than intended. Go on now young adventurer, for there is much more in store for you","",""},
                //node27
                {"I have already revealed more than intended. You will find more wisdom in the library. But more importantly, go to the church. To purify yourself will shelter you from the darkness ahead .Go on weary traveler, for your quest is but a great one.","",""},
                //node28
                { "I have already revealed more than intended. The last thing I shall say is go to the church. You must go there and purify yourself before advancing on this quest. Go on, for your quest is of great importance to not only yourself, but for the safety of the entire universe.","","" },
                //node29
                {"I have already revealed more than intended. You will find more wisdom in the library. But more importantly, go to the church. To purify yourself will shelter you from the darkness ahead .Go on weary traveler, for your quest is but a great one.","",""},
                //node30
                {"I have already revealed more than intended. The last thing I shall say is go to the church. You must go there and purify yourself before advancing on this quest. Go on, for your quest is of great importance to not only yourself, but for the safety of the entire universe.","",""}

            };
            int userChoice;
            int index = 0;
            //for loop iterates number of levels for possible responses
            //!FIXME: IMPLEMENT TREE LEVEL ALGORITHM
            for (int i = 0; i < 5; i++) {
                //print dialogue
                system("CLS");
                //if current quotation has two responses
                if (i < 5) {
                    std::cout << shadowyManDialogue[index][0] << std::endl;
                    std::cout << std::endl << std::endl;
                    std::cout << "[1] " << shadowyManDialogue[index][1] << std::endl;
                    std::cout << "[2] " << shadowyManDialogue[index][2] << std::endl;
                    std::cout << "[3] Exit" << std::endl << std::endl;
                    std::cout << "Choice: ";
                    std::cin >> userChoice;

                    //if user chooses option 1
                    if (userChoice == 1) {
                        index = (2 * index) + 1;
                    }
                    //if user chooses option 2
                    else if (userChoice == 2) {
                        index = (2 * index) + 2;
                    }
                    //if user chooses to exit dialogue
                    else if (userChoice == 3) {
                        std::cout << "\n\n      Goodbye." << std::endl;
                    
                        system("CLS");
                        i = 4;
                    }
                    //if user chooses an invalid option
                    else {
                        //print error message
                        std::cout << "This is not an option!";
                        //for loop is set back one loop if the user does not input a valid number
                        i--;
                    }
                }
            }


            system("PAUSE");
        }

        //if player chooses to talk to old man 
        else if (playerChoice == 2) {
            system("CLS"); //!FIXME: REMOVE THIS, STORE IT IN THE DIALOGUE MENU, ADD DIALOGUE MENU AND DOCUMENTATION
            std::vector<std::vector<std::string>> oldManDialogue = {
                //node0
                {"Ahh, greetings, young traveler. I've been expecting you","Do you even know where I come from?","Who are you?"},
                //node1
                {"My dear traveler, I have known you for many years, though our paths have not crossed until now. You are from a different world. Though we come from two different worlds, we are but threads woven by the same divine hand, guided by the same celestial compass. I have have been watching over you.", "Where are you from?", "How do you know me?"},
                //node2
                {"I am but a humble observer of journeys, a keeper of tales. You, young traveler, are a part of a story yet untold","Why am I here?", "How do you know me?"},
                //node3
                {"We both existence within a singular realm, yet we traverse divergent paths. My world is distinguished by its outwardly supernatural manifestations which is merely a subtle divergence from the fabric of your own reality.","Why have I been brought here?", "Supernatural manifestations?"},
                //node4
                {"Though we reside in two distinct worlds, we are but threads woven by the same divine hand, guided by the same celestial compass. I have have been watching over you, protecting you from evil until it became to big a task. It was time for you to save yourself.","Evil? What kind of evil?", "Who is this divine hand?"},
                //node5
                {"You have been summoned to this realm due to the encroaching shadow of Evil that now engulfs your world, rendering it unsafe. Here, you are tasked with unlocking the pathways to successive universes until you locate her, the revered Queen of Heaven.", "What should I do now?", "Encroaching shadow of evil?"},
                //node6
                {"In our distinct worlds, we are threads woven by the same divine hand, guided by a celestial compass toward our destinies. I've been your guardian, warding off encroaching darkness until the weight became too much. Now, it's time for you to ascend and safeguard your own path.", "What should I do now?","Where am I being guided?"},
                //node 7
                {"You have been summoned to this realm due to the encroaching shadow of Evil that now engulfs your world, rendering it unsafe. Here, you are tasked with unlocking the pathways to successive universes until you locate her, the revered Queen of Heaven.", "What should I do now?", "Who is the queen of heaven?"},
                //node 8
                {"Yes. In the grand design of existence, characters within this universe serve as guardian angels to counterparts in your world. I, as your celestial guide, possess glimpses into realms beyond your current sight. Each of us has our own overseers, yet their identities remain shrouded in mystery.","Why am I here?","Where are you guiding me?"},
                //node 9
                {"The Evil that grips your world is not merely a force external but has insidiously crept into the souls of ordinary beings, corrupting their hearts and minds. It manifests in the form of greed, hatred, and the pursuit of power at the cost of virtue. The battle against this darkness is not just physical but spiritual, a test of faith and righteousness.","Why was I chosen to defeat this evil?","How do I win this battle?"},
                //node 10
                {"The divine hand I speak of is that of the Creator, the Almighty, who shapes destinies and guides souls along their paths. Follow your heart, for it is attuned to the whispers of divine guidance. The Queen of Heaven, representing the embodiment of grace and wisdom, is also your steadfast guide.","What should I do now?","Where am I being guided?"},
                //node 11
                {"To emerge victorious in this struggle, you must embark on a profound odyssey that transcends not just this realm but potentially extends through subsequent worlds, each reflecting the spiritual trials of humanity. Your mission is to discover the Queen of Heaven, embodying divine wisdom and grace. Look not only within but also beyond, engaging in dialogues with others, exploring the preserved knowledge in the library, and seeking solace and guidance at the church. Let your heart, guided by faith and righteousness, be your guiding light on this quest.","Thank You","Who is this Queen of Heaven?"},
                //node 12
                {"The Evil that grips your world is not merely a force external but has insidiously crept into the souls of ordinary beings, corrupting their hearts and minds. It manifests in the form of greed, hatred, and the pursuit of power at the cost of virtue. The battle against this darkness is not just physical but spiritual, a test of faith and righteousness.","Why was I chosen to defeat this evil?","How do I win this battle?"},
                //node 13 (yep, wxactly the same as 12, some are the same)
                {"The Evil that grips your world is not merely a force external but has insidiously crept into the souls of ordinary beings, corrupting their hearts and minds. It manifests in the form of greed, hatred, and the pursuit of power at the cost of virtue. The battle against this darkness is not just physical but spiritual, a test of faith and righteousness.","Why was I chosen to defeat this evil?","How do I win this battle?"},
                //node 14
                {"The divine hand I speak of is that of the Creator, the Almighty, who shapes destinies and guides souls along their paths. Follow your heart, for it is attuned to the whispers of divine guidance. The Queen of Heaven, representing the embodiment of grace and wisdom, is also your steadfast guide.","What should I do now?","Where am I being guided?"},
                //node 15
                {" OLD MAN:To emerge victorious in this struggle, you must embark on a profound odyssey that transcends not just this realm but potentially extends through subsequent worlds, each reflecting the spiritual trials of humanity. Your mission is to discover the Queen of Heaven, embodying divine wisdom and grace. Look not only within but also beyond, engaging in dialogues with others, exploring the preserved knowledge in the library, and seeking solace and guidance at the church. Let your heart, guided by faith and righteousness, be your guiding light on this quest. The Queen of Heaven awaits, her presence illuminating the path to triumph over darkness. Time is of the essence, young traveler. Hasten, for the fate of realms and souls hinges upon your virtuous endeavors.","",""},
                //node16
                {"I am but a speck of dust compared to her majesty. I will say you must find her to truly know all that she is. She is the epitome of divine wisdom and grace, and is forseeing your journey and arrival far more than I ever could. Go to her, for there isn't much time." },
                //node17
                {"You have been sent here to escape the Evil that engulfs your world. It is only the begining of your journey. You must embark on a profound journey, not just through this realm but potentially through subsequent worlds, which are a reflection of the spiritual challenges faced by humanity. Your quest is to find the Queen of Heaven, the embodiment of divine wisdom and grace.  Go on now, there isn't much time before its too late, the queen of heaven awaits your arrival.","",""},
                //node18
                {"I have only guided you here. After this, you must guide yourself. Your individual wisdom can show you things that I cannot. Engage in conversations beyond yourself, seek knowledge in the library, find solace at the church. Let faith and righteousness guide your heart; the Queen of Heaven awaits as your guiding light. Time is pressing, young traveler. The fate of realms and souls rests upon your righteous deeds. You must hurry.","",""},
                //node19
                {"You have been chosen because within you lies the potential for great virtue and strength of spirit. Your heart is pure, your intentions noble. The divine providence has deemed you worthy to embark on this sacred quest, for it is through your courage, faith, and righteousness that the tide of darkness may be turned. You are the beacon of hope in a world besieged by shadows, destined to bring forth the light of redemption and salvation. Go on now, there isn't much time before its too late, the queen of heaven awaits your arrival. ","",""},
                //node20
                {"To triumph in this battle, you must embark on a profound journey, not just through this realm but potentially through subsequent worlds, which are a reflection of the spiritual challenges faced by humanity. Your quest is to find the Queen of Heaven, the embodiment of divine wisdom and grace. Seek not only within yourself but also beyond, engaging in conversations with others, delving into the knowledge preserved in the library, and seeking solace and guidance at the church. Your heart, guided by faith and righteousness, is your beacon in this journey. The Queen of Heaven awaits, her presence a guiding light leading you to victory over darkness. Time is of the essence, young traveler. Hurry, for the destiny of realms and souls rests upon your righteous actions.","",""},
                //node21
                {"You have been sent here to escape the Evil that engulfs your world. It is only the begining of your journey. You must embark on a profound journey, not just through this realm but potentially through subsequent worlds, which are a reflection of the spiritual challenges faced by humanity. Your quest is to find the Queen of Heaven, the embodiment of divine wisdom and grace.  Go on now, there isn't much time before its too late, the queen of heaven awaits your arrival. ","",""},
                //node22
                {"I have only guided you here. After this, you must guide yourself. Your individual wisdom can show you things that I cannot. Engage in conversations beyond yourself, seek knowledge in the library, find solace at the church. Let faith and righteousness guide your heart; the Queen of Heaven awaits as your guiding light. Time is pressing, young traveler. The fate of realms and souls rests upon your righteous deeds. You must hurry.","",""},
                //node23
                {"It is my pleasure, courageous one. The Queen of Heaven awaits, her presence illuminating the path to triumph over darkness. Time is of the essence, young traveler. Hasten, for the fate of realms and souls hinges upon your virtuous endeavors.","",""},
                //node24
                {"I am but a speck of dust compared to her majesty. I will say you must find her to truly know all that she is. She is the epitome of divine wisdom and grace, and is forseeing your journey and arrival far more than I ever could. Go to her, for there isn't much time.","","" },
                //node25
                {"You have been chosen because within you lies the potential for great virtue and strength of spirit. Your heart is pure, your intentions noble. The divine providence has deemed you worthy to embark on this sacred quest, for it is through your courage, faith, and righteousness that the tide of darkness may be turned. You are the beacon of hope in a world besieged by shadows, destined to bring forth the light of redemption and salvation. Go on now, there isn't much time before its too late, the queen of heaven awaits your arrival. ","",""},
                //node26
                {"To triumph in this battle, you must embark on a profound journey, not just through this realm but potentially through subsequent worlds, which are a reflection of the spiritual challenges faced by humanity. Your quest is to find the Queen of Heaven, the embodiment of divine wisdom and grace. Seek not only within yourself but also beyond, engaging in conversations with others, delving into the knowledge preserved in the library, and seeking solace and guidance at the church. Your heart, guided by faith and righteousness, is your beacon in this journey. The Queen of Heaven awaits, her presence a guiding light leading you to victory over darkness. Time is of the essence, young traveler. Hurry, for the destiny of realms and souls rests upon your righteous actions.","",""},
                //node27
                {"You have been chosen because within you lies the potential for great virtue and strength of spirit. Your heart is pure, your intentions noble. The divine providence has deemed you worthy to embark on this sacred quest, for it is through your courage, faith, and righteousness that the tide of darkness may be turned. You are the beacon of hope in a world besieged by shadows, destined to bring forth the light of redemption and salvation. Go on now, there isn't much time before its too late, the queen of heaven awaits your arrival. ","",""},
                //node28
                {"To triumph in this battle, you must embark on a profound journey, not just through this realm but potentially through subsequent worlds, which are a reflection of the spiritual challenges faced by humanity. Your quest is to find the Queen of Heaven, the embodiment of divine wisdom and grace. Seek not only within yourself but also beyond, engaging in conversations with others, delving into the knowledge preserved in the library, and seeking solace and guidance at the church. Your heart, guided by faith and righteousness, is your beacon in this journey. The Queen of Heaven awaits, her presence a guiding light leading you to victory over darkness. Time is of the essence, young traveler. Hurry, for the destiny of realms and souls rests upon your righteous actions.","",""},
                //node29
                {"You have been sent here to escape the Evil that engulfs your world. It is only the begining of your journey. You must embark on a profound journey, not just through this realm but potentially through subsequent worlds, which are a reflection of the spiritual challenges faced by humanity. Your quest is to find the Queen of Heaven, the embodiment of divine wisdom and grace.  Go on now, there isn't much time before its too late, the queen of heaven awaits your arrival. ","",""},
                //node30
                {"I have only guided you here. After this, you must guide yourself. Your individual wisdom can show you things that I cannot. Engage in conversations beyond yourself, seek knowledge in the library, find solace at the church. Let faith and righteousness guide your heart; the Queen of Heaven awaits as your guiding light. Time is pressing, young traveler. The fate of realms and souls rests upon your righteous deeds. You must hurry.","",""},

            };

            int userChoice;
            int index = 0;
            //for loop iterates number of levels for possible responses
            //!FIXME: IMPLEMENT TREE LEVEL ALGORITHM
            for (int i = 0; i < 5; i++) {
                //print dialogue
                system("CLS");
                //if current quotation has two responses
                if (i < 5) {
                    std::cout << oldManDialogue[index][0] << std::endl;
                    std::cout << std::endl << std::endl;
                    std::cout << "[1] " << oldManDialogue[index][1] << std::endl;
                    std::cout << "[2] " << oldManDialogue[index][2] << std::endl;
                    std::cout << "[3] Exit" << std::endl << std::endl;
                    std::cout << "Choice: ";
                    std::cin >> userChoice;

                    //if user chooses option 1
                    if (userChoice == 1) {
                        index = (2 * index) + 1;
                    }
                    //if user chooses option 2
                    else if (userChoice == 2) {
                        index = (2 * index) + 2;
                    }
                    //if user chooses to exit dialogue
                    else if (userChoice == 3) {
                        std::cout << "\n\n      Goodbye." << std::endl;

                        system("CLS");
                        i = 4;
                    }
                    //if user chooses an invalid option
                    else {
                        //print error message
                        std::cout << "This is not an option!";
                        //for loop is set back one loop if the user does not input a valid number
                        i--;
                    }
                }
            }


            system("PAUSE");
            
        }

        //if player chooses to go to bar
        else if (playerChoice == 3) {
            execLoungeExchangeMenu(player, playerChoice);
        }

        //if player chooses to exit lounge
        else if (playerChoice == 4) {
            system("CLS");
            std::cout << "Goodbye laddy!" << std::endl << std::endl;
            system("PAUSE");
            sentinel = 1;
        }

        else {
            system("CLS");
            std::cout << "That is not an option." << std::endl << std::endl;
            system("PAUSE");
        }
    }
};

int lounge::execLoungeLobbyMenu(player& player, int& playerChoice) {
    //reset playerChoice so that error-proofing loop may begin
    playerChoice = 0;
    //error-proofing while loop
    while ((playerChoice < 1) || (playerChoice > 3)) {
        //print enter shop menu
        system("CLS");
        std::cout << "Welcome to " << loungeName << " where tales and mysteries intertwine. " << std::endl << std::endl;
        std::cout << "What would you like to do next?" << std::endl << std::endl;
        std::cout << "[1] Talk to Strange Man" << std::endl;
        std::cout << "[2] Talk to Old Man" << std::endl;
        std::cout << "[3] Go to Bar" << std::endl;
        std::cout << "[4] Exit" << std::endl << std::endl;
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

void lounge::execLoungeExchangeMenu(player& player, int& playerChoice) {
    //reset playerChoice so that error-proofing loop may begin
    playerChoice = 0;
    //sentinel prevents this menu from closing until uses
    int sentinel = 0;
    //error-proofing while loop
    while (((playerChoice < 1) || (playerChoice > 3)) && (sentinel != 1)) {
        //print enter shop menu
        system("CLS");
        std::cout << "Hello lad! What can I do you for?" << std::endl << std::endl;
        std::cout << "[1] I'll take a beer" << std::endl;
        std::cout << "[2] I'll grab some water" << std::endl;
        std::cout << "[3] Exit" << std::endl << std::endl;
        std::cout << "Choice: ";
        std::cin >> playerChoice;
        //if-else if branches determine which menu to print depending on player's shop menu choice
        //if player chooses to buy beer
        if (playerChoice == 1) {
            system("CLS");
            player.getInventory()->setCoinCount(player.getInventory()->getCointCount() - drinkSlot1.getDrinkCoinValue());
            std::cout << "You purchased a beer. "<< std::endl;
            std::cout << drinkSlot1.getDrinkCoinValue() << " subtracted from gold. " << std::endl;
            std::cout << "Would You like to drink this beer?" << std::endl;
            std::cout << "[1] Yes drink it now" << std::endl;
            std::cout << "[2] No store in inventory" << std::endl;
            std::cout << "Choice: ";
            std::cin >> playerChoice;
            system("CLS");
            if (playerChoice == 1) {
                player.setHp((player.getHp() - drinkSlot1.getDrinkHealValue()));
                std::cout << "Whoops! These arent normal beers!" << std::endl;
                std::cout << "Your Hp has decreased. Tour new Hp is " << player.getHp() << std::endl;
            }
            else if (playerChoice == 2) {
                player.getInventory()->setDrink(drinkSlot1);
            }

            
            
       

        }
        //if player chooses to buy water
        else if (playerChoice == 2) {
            system("CLS");
            player.getInventory()->setCoinCount(player.getInventory()->getCointCount() - drinkSlot1.getDrinkCoinValue());
            std::cout << "You grabbed a water. " << std::endl;
            std::cout << drinkSlot2.getDrinkCoinValue() << " subtracted from gold. " << std::endl;
            std::cout << "Would You like to drink this water?" << std::endl;
            std::cout << "[1] Yes drink it now" << std::endl;
            std::cout << "[2] No store in inventory" << std::endl;
            std::cout << "Choice: ";
            std::cin >> playerChoice;
            if (playerChoice == 1) {
                system("CLS");
                player.setHp((player.getHp() + drinkSlot2.getDrinkHealValue()));
                std::cout << "That was Refleshing!" << player.getHp() << std::endl << std::endl;
                std::cout << "Your new Hp is " << player.getHp() << std::endl;
            }
            else if (playerChoice == 2) {
                player.getInventory()->setDrink(drinkSlot2);
            }
           
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








