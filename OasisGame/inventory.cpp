#include <iostream>
#include <iomanip>
#include <string>
#include "menu.h"
#include "map.h"
#include "locations.h"
#include "buildings.h"
#include "characters.h"
#include "inventory.h"
#include "items.h"
#include "DialogueTree.h"

//INVENTORY CLASS DEFINITIONS

//PLAYER INVENTORY CLASS DEFINITIONS

//constructor
playerInventory::playerInventory() {
	//declare variables
	weapon noWeapon;
	armor noArmor;
	potion noPotion;
	item noItem;

	//set default variables
	//!FIXME: LEFT OFF HERE, TRY USING SETTERS TO SET DEFAULTS
	weaponSlot = noWeapon;
	armorSlot = noArmor;
	potionSlot = noPotion;
	itemSlot1 = noItem;
	itemSlot2 = noItem;
	itemSlot3 = noItem;
	coinCount = 0;
}

playerInventory::playerInventory(weapon weaponSlot, armor armorSlot, potion potionSlot, item itemSlot1, item itemSlot2, item itemSlot3, int coinCount) {
	this->weaponSlot = weaponSlot;
	this->armorSlot = armorSlot;
	this->potionSlot = potionSlot;
	this->itemSlot1 = itemSlot1;
	this->itemSlot2 = itemSlot2;
	this->itemSlot3 = itemSlot3;
	this->coinCount = coinCount;
}

//getters
weapon playerInventory::getWeapon() { return weaponSlot; }

std::string playerInventory::getWeaponAttackString() {
	return "Atk: " + std::to_string(weaponSlot.getAtk());
}

armor playerInventory::getArmor() { return armorSlot; }

std::string playerInventory::getArmorDefenseString() {
	return "Def: " + std::to_string(armorSlot.getDef());
}

potion* playerInventory::getPotion() { return &potionSlot; }

std::string playerInventory::getPotionDisplayString() { 
	//return only potion name if the potionSlot is empty
	if (potionSlot.getPotionCount() == 0) {
		//will return "empty"
		return potionSlot.getName(); //!FIXME: MAKE SURE THAT IF POTION COUNT IS 0 THEN NAME CHANGES TO EMPTY/NOPOTION BECOMES POTIONSLOT
	}
	//return 
	else if (potionSlot.getPotionCount() > 0) {
		return potionSlot.getName() + " x" + std::to_string(potionSlot.getPotionCount());
	}
}

std::string playerInventory::getPotionStatString() {
	return "HP +" + std::to_string(potionSlot.getHealValue()) + "/SP +" + std::to_string(potionSlot.getStaminaValue());
}

item playerInventory::getItemSlot1() { return itemSlot1; }

item playerInventory::getItemSlot2() { return itemSlot2; }

item playerInventory::getItemSlot3() { return itemSlot3; }

int playerInventory::getCointCount() { return coinCount; }

//setters
void playerInventory::setWeapon(weapon &weaponSlot) { this->weaponSlot = weaponSlot; }

void playerInventory::setArmor(armor &armorSlot) { this->armorSlot = armorSlot; }

void playerInventory::setPotion(potion &potionSlot) { this->potionSlot = potionSlot; }

void playerInventory::setItem1(item &itemSlot1) { this->itemSlot1 = itemSlot1; }

void playerInventory::setItem2(item& itemSlot2) { this->itemSlot2 = itemSlot2; }

void playerInventory::setItem3(item& itemSlot3) { this->itemSlot3 = itemSlot3; }

void playerInventory::setCoinCount(int coinCount) { this->coinCount = coinCount; }

//methods
void playerInventory::display() {
	//!FIXME: ADD ATTACK STATS
	//clear console
	system("CLS");
	//iomanip stream manipulations
	std::cout << std::setiosflags(std::ios::left); //left aligns setw()
	//display spacing header for inventory
	std::cout << "Inventory:" << std::endl << std::endl;
	std::cout << std::setw(15) << "Slot" << std::setw(25) << "Item Name" << std::setw(15) << "Coin Value" << std::setw(6) << "Weight" << std::endl;
	std::cout << "================================================================" << std::endl << std::endl;
	//display inventory items in order
	std::cout << std::setw(15) << "Weapon Slot: " << std::setw(25) << weaponSlot.getName() << std::setw(15) << weaponSlot.getCoinValue() << std::setw(6) << weaponSlot.getWeight() << std::endl << std::endl;
	std::cout << std::setw(15) << "Armor Slot: " << std::setw(25) << armorSlot.getName() << std::setw(15) << armorSlot.getCoinValue() << std::setw(6) << armorSlot.getWeight() << std::endl << std::endl;
	std::cout << std::setw(15) << "Potion Slot: " << std::setw(25) << getPotionDisplayString() << std::setw(15) << potionSlot.getCoinValue() << std::setw(6) << "n/a" << std::endl << std::endl;
	std::cout << std::setw(15) << "Item Slot 1: " << std::setw(25) << itemSlot1.getName() << std::setw(15) << itemSlot1.getCoinValue() << std::setw(6) << itemSlot1.getWeight() << std::endl << std::endl;
	std::cout << std::setw(15) << "Item Slot 2: " << std::setw(25) << itemSlot2.getName() << std::setw(15) << itemSlot2.getCoinValue() << std::setw(6) << itemSlot2.getWeight() << std::endl << std::endl;
	std::cout << std::setw(15) << "Item Slot 3: " << std::setw(25) << itemSlot3.getName() << std::setw(15) << itemSlot3.getCoinValue() << std::setw(6) << itemSlot3.getWeight() << std::endl << std::endl;
	std::cout << "================================================================" << std::endl << std::endl;
}

void playerInventory::battleDisplay() {
	//iomanip stream manipulations
	std::cout << std::setiosflags(std::ios::left); //left aligns setw()
	//display spacing header
	//!FIXME: see if you can middle align titles
	std::cout << std::setw(15) << "Slot" << std::setw(25) << "Item Name" << std::setw(15) << "Stats" << std::endl;
	std::cout << std::setw(45) << "=====================================================" << std::endl << std::endl;
	//display items in order
	std::cout << std::setw(15) << "Weapon Slot: " << std::setw(25) << weaponSlot.getName() << std::setw(15) << getWeaponAttackString() << std::endl << std::endl;
	std::cout << std::setw(15) << "Armor Slot: " << std::setw(25) << armorSlot.getName() << std::setw(15) << getArmorDefenseString() << std::endl << std::endl;
	std::cout << std::setw(15) << "Potion Slot: " << std::setw(25) << getPotionDisplayString() << std::setw(15) << getPotionStatString() << std::endl << std::endl;
	std::cout << std::setw(15) << "Item Slot 1: " << std::setw(25) << itemSlot1.getName() << std::endl << std::endl;
	std::cout << std::setw(15) << "Item Slot 2: " << std::setw(25) << itemSlot2.getName() << std::endl << std::endl;
	std::cout << std::setw(15) << "Item Slot 3: " << std::setw(25) << itemSlot3.getName() << std::endl << std::endl;
	std::cout << std::setw(45) << "=====================================================" << std::endl << std::endl;
}

int playerInventory::inventoryChoiceMenu(player& player, int& playerChoice) {
	int playerChoice;
	while ((playerChoice < 1) || (playerChoice > 3)) {
		int playerChoice;
		//print and reprint inventory choices
		std::cout << "Would you like to do anything with your items?" << std::endl << std::endl;
		std::cout << "================================================================" << std::endl << std::endl;
		std::cout << "[1] Drop Item" << std::endl;
		std::cout << "[2] Use Potion" << std::endl;
		std::cout << "[3] Exit" << std::endl << std::endl;
		std::cin >> playerChoice;
		//erroneous choice message
		if ((playerChoice < 1) || (playerChoice > 3)) {
			system("CLS");
			std::cout << "This is not an option." << std::endl << std::endl;
			system("PAUSE");
			display();
		}
		else {
			//if user chooses to exit then execInventoryChoice returns 1 to break this menu's while loop
			playerChoice = execInventoryChoice(player, playerChoice);
		}
	}
}

int playerInventory::execInventoryChoice(player& player, int& playerChoice) {
	//if player chooses to drop an item
	if (playerChoice == 1) {
		display();
		dropItemMenu(player, playerChoice);
		return -1;
	}
	//if player chooses to 
	else if (playerChoice == 2) {
		player.usePotion();
		//return -1 to continue main loop inventoryChoiceMenu loop
		return -1;
	}
	else if (playerChoice == 3) {
		//return 1 to quit inventory main loop inventoryChoiceMenu loop
		return 1;
	}
}

void playerInventory::dropItemMenu(player& player, int& playerChoice) {
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
			display();
		}
	}
	if (playerChoice != 7) {
		droptItem(player, playerChoice);
	}
}

void playerInventory::dropItem(player& player, int& playerChoice) {
	//!FIXME: LEFT OFF HERE, ADD DROP FUNCTIONALITY
}

//!FIXME: add in return type, choice menu, etc, seperate function?
//!FIXME: ADD "ARE YOU SURE YOU WANT TO SELL?" MENU!!!



