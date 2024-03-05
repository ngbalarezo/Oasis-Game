#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include "items.h"

class inventory {
protected:

public:
	//!FIXME: maybe make this general and applicable to all? LEFT OFF HERE AND IN ITEMS.H
};

class playerInventory {
private:
	//each player inventory has 1 weapon slot and 1 armor slot
	weapon weaponSlot;
	armor armorSlot;
	//each player inventory has 1 potion slot with a potion count
	potion potionSlot;
	int potionCount;
	//each player inventory has 3 miscellaneous item slots
	miscItem itemSlot1;
	miscItem itemSlot2;
	miscItem itemSlot3;
	//each player inventory has a coin sack with infinite depth
	int coinCount;

public:
	//constructor
	playerInventory();
	//getters
	weapon getWeapon();
	armor getArmor();
	potion getPotion();
	int getPotionCount();
	miscItem getItemSlot1();
	miscItem getItemSlot2();
	miscItem getItemSlot3();

	//setters
	void setWeapon(weapon newWeapon);
	void setArmor(armor newArmor);
	void setPotion(potion newPotion);
	void setPotionCount(int potionCount);
	void setItem1(miscItem newItem);
	void setItem2(miscItem newItem);
	void setItem3(miscItem newItem);

	//methods
};

#endif