#include <iostream>
#include <iomanip>
#include <string>
#include "characters.h"
#include "inventory.h"
#include "items.h"

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
	weaponSlot = noWeapon;
	armorSlot = noArmor;
	potionSlot = noPotion;
	potionCount = 0;
	itemSlot1 = noItem;
	itemSlot2 = noItem;
	itemSlot3 = noItem;
	coinCount = 0;
}

playerInventory::playerInventory(weapon noWeapon, armor noArmor, potion noPotion, item noItem) {
	weaponSlot = noWeapon;
	armorSlot = noArmor;
	potionSlot = noPotion;
	potionCount = 0;
	itemSlot1 = noItem;
	itemSlot2 = noItem;
	itemSlot3 = noItem;
	coinCount = 0;
}

//getters
weapon playerInventory::getWeapon() { return weaponSlot; }

armor playerInventory::getArmor() { return armorSlot; }

potion playerInventory::getPotion() { return potionSlot; }

int playerInventory::getPotionCount() { return potionCount; }

item playerInventory::getItemSlot1() { return itemSlot1; }

item playerInventory::getItemSlot2() { return itemSlot2; }

item playerInventory::getItemSlot3() { return itemSlot3; }

//setters
void playerInventory::setWeapon(weapon newWeapon) { weaponSlot = newWeapon; }

void playerInventory::setArmor(armor newArmor) { armorSlot = newArmor; }

void playerInventory::setPotion(potion newPotion) { potionSlot = newPotion; }

void playerInventory::setPotionCount(int potionCount) { this->potionCount = potionCount; }

void playerInventory::setItem1(item newItem) { itemSlot1 = newItem; }

void playerInventory::setItem2(item newItem) { itemSlot2 = newItem; }

void playerInventory::setItem3(item newItem) { itemSlot3 = newItem; }

//methods
void playerInventory::display() {
	//iomanip stream manipulations
	std::cout << std::setiosflags(std::ios::right); //left aligns setw()
	//display spacing header
	//!FIXME: see if you can middle align titles
	std::cout << std::setw(8) << "Slot" << "|" << std::setw(8) << "Name" << "|" << std::setw(8) << "Value" << "|" << std::setw(8) << "Weight" << std::endl;
	//display items in order
	std::cout << "Weapon Slot: " << weaponSlot.getName() << "  " << weaponSlot.getCoinValue() << "  " << weaponSlot.getWeight() << std::endl;
	
	
	
}

//!FIXME: add in return type, choice menu, etc, seperate function?



