#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H

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

class inventory {
protected:

public:
	//!FIXME: maybe make this general and applicable to all? LEFT OFF HERE AND IN ITEMS.H
};

class playerInventory{
private:
	//each player inventory has 1 weapon slot and 1 armor slot
	weapon weaponSlot;
	armor armorSlot;
	//each player inventory has 1 potion slot with a potion count
	potion potionSlot;
	//each player inventory has 3 miscellaneous item slots
	item itemSlot1;
	item itemSlot2;
	item itemSlot3;
	//each player inventory has a coin sack with infinite depth
	int coinCount;

public:
	//constructors
	playerInventory();

	playerInventory(weapon weaponSlot, armor armorSlot, potion potionSlot, item itemSlot1, item itemSlot2, item itemSlot3, int coinCount);

	//getters
	weapon getWeapon();

	std::string getWeaponAttackString();

	armor getArmor();

	std::string getArmorDefenseString();

	potion* getPotion();

	std::string getPotionDisplayString();

	std::string getPotionStatString();

	item getItemSlot1();

	item getItemSlot2();

	item getItemSlot3();

	int getCointCount();

	//setters
	void setWeapon(weapon &newWeapon);

	void setArmor(armor &newArmor);

	void setPotion(potion &newPotion);

	void setItem1(item &newItem);

	void setItem2(item &newItem);

	void setItem3(item &newItem);

	void setCoinCount(int coinCount);

	//methods
	void display();

	void battleDisplay();

	void churchDisplay();

	int inventoryChoiceMenu();

	int execInventoryChoice(int& playerChoice);

	void dropItemMenu(int& playerChoice);

	int checkDropChoice(int& playerChoice);

	void dropItem(int& playerChoice);
  
};

#endif