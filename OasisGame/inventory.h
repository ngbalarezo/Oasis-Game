#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include "menu.h"
#include "map.h"
#include "locations.h"
#include "buildings.h"
#include "characters.h"
#include "inventory.h"
#include "items.h"

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
	int potionCount;
	//each player inventory has 3 miscellaneous item slots
	item itemSlot1;
	item itemSlot2;
	item itemSlot3;
	//each player inventory has a coin sack with infinite depth
	int coinCount;

public:
	//constructors
	playerInventory();

	playerInventory(weapon weaponSlot, armor armorSlot, potion potionSlot, int potionCount, item itemSlot1, item itemSlot2, item itemSlot3, int coinCount);

	//getters
	weapon getWeapon();

	std::string getWeaponAttackString();

	armor getArmor();

	std::string getArmorDefenseString();

	potion getPotion();

	int getPotionCount();

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

	void setPotionCount(int potionCount);

	void setItem1(item &newItem);

	void setItem2(item &newItem);

	void setItem3(item &newItem);

	void setCoinCount(int coinCount);

	//methods
	void display();

	void battleDisplay();
};

#endif