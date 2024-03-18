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

std::string playerInventory::getPotionDisplayString() { 
	return potionSlot.getPotionName() + " x" + std::to_string(potionCount);
	/*std::string potionDisplayString = potionSlot.getPotionName();
	potionDisplayString.append(" x");
	potionDisplayString.append(std::to_string(potionCount));
	return potionDisplayString;*/
}

item playerInventory::getItemSlot1() { return itemSlot1; }

item playerInventory::getItemSlot2() { return itemSlot2; }

item playerInventory::getItemSlot3() { return itemSlot3; }

int playerInventory::getCointCount() { return coinCount; }

//setters
void playerInventory::setWeapon(weapon newWeapon) { weaponSlot = newWeapon; }

void playerInventory::setArmor(armor newArmor) { armorSlot = newArmor; }

void playerInventory::setPotion(potion newPotion) { potionSlot = newPotion; }

void playerInventory::setPotionCount(int potionCount) { this->potionCount = potionCount; }

void playerInventory::setItem1(item newItem) { itemSlot1 = newItem; }

void playerInventory::setItem2(item newItem) { itemSlot2 = newItem; }

void playerInventory::setItem3(item newItem) { itemSlot3 = newItem; }

void playerInventory::setCoinCount(int coinCount) { this->coinCount = coinCount; }

//methods
void playerInventory::display() {
	//iomanip stream manipulations
	std::cout << std::setiosflags(std::ios::left); //left aligns setw()
	//display spacing header
	//!FIXME: see if you can middle align titles
	std::cout << std::setw(15) << "Slot" << std::setw(15) << "Name" << std::setw(15) << "Value" << std::setw(15) << "Weight" << std::endl;
	std::cout << std::setw(51) << "===================================================" << std::endl << std::endl;
	//display items in order
	std::cout << std::setw(15) << "Weapon Slot: " << std::setw(15) << weaponSlot.getName() << std::setw(15) << weaponSlot.getCoinValue() << std::setw(15) << weaponSlot.getWeight() << std::endl << std::endl;
	std::cout << std::setw(15) << "Armor Slot: " << std::setw(15) << armorSlot.getName() << std::setw(15) << armorSlot.getCoinValue() << std::setw(15) << armorSlot.getWeight() << std::endl << std::endl;
	std::cout << std::setw(15) << "Potion Slot: " << std::setw(15) << getPotionDisplayString() << std::setw(15) << potionSlot.getCoinValue() << std::setw(15) << "n/a" << std::endl << std::endl;
	std::cout << std::setw(15) << "Item Slot 1: " << std::setw(15) << itemSlot1.getName() << std::setw(15) << itemSlot1.getCoinValue() << std::setw(15) << itemSlot1.getWeight() << std::endl << std::endl;
	std::cout << std::setw(15) << "Item Slot 2: " << std::setw(15) << itemSlot2.getName() << std::setw(15) << itemSlot2.getCoinValue() << std::setw(15) << itemSlot2.getWeight() << std::endl << std::endl;
	std::cout << std::setw(15) << "Item Slot 3: " << std::setw(15) << itemSlot3.getName() << std::setw(15) << itemSlot3.getCoinValue() << std::setw(15) << itemSlot3.getWeight() << std::endl << std::endl;
	std::cout << std::setw(51) << "===================================================" << std::endl << std::endl;
	std::cout << std::endl;
}

void playerInventory::battleDisplay() {
	//iomanip stream manipulations
	std::cout << std::setiosflags(std::ios::left); //left aligns setw()
	//display spacing header
	//!FIXME: see if you can middle align titles
	std::cout << std::setw(15) << "Slot" << std::setw(15) << "Name" << std::setw(15) << "Stats" << std::endl;
	std::cout << std::setw(45) << "===========================================" << std::endl << std::endl;
	//display items in order
	std::cout << std::setw(15) << "Weapon Slot: " << std::setw(15) << weaponSlot.getName() << "Atk: " << weaponSlot.getAtk()  << std::endl << std::endl;
	std::cout << std::setw(15) << "Armor Slot: " << std::setw(15) << armorSlot.getName() << "Def: " << armorSlot.getDef() << std::endl << std::endl;
	std::cout << std::setw(15) << "Potion Slot: " << std::setw(15) << getPotionDisplayString() << "HP +" << potionSlot.getHealValue() << "/SP +" << potionSlot.getStaminaValue() << std::endl << std::endl;
	std::cout << std::setw(15) << "Item Slot 1: " << std::setw(15) << itemSlot1.getName() << std::endl << std::endl;
	std::cout << std::setw(15) << "Item Slot 2: " << std::setw(15) << itemSlot2.getName() << std::endl << std::endl;
	std::cout << std::setw(15) << "Item Slot 3: " << std::setw(15) << itemSlot3.getName() << std::endl << std::endl;
	std::cout << std::setw(45) << "===========================================" << std::endl << std::endl;
	std::cout << std::endl;


}

//!FIXME: add in return type, choice menu, etc, seperate function?



