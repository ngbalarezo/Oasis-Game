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

class playerInventory : public inventory{
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
	//constructor
	playerInventory(weapon noWeapon, armor noArmor, potion noPotion, item noItem);

	//getters
	weapon getWeapon();

	armor getArmor();

	potion getPotion();

	int getPotionCount();

	item getItemSlot1();

	item getItemSlot2();

	item getItemSlot3();

	//setters
	void setWeapon(weapon newWeapon);

	void setArmor(armor newArmor);

	void setPotion(potion newPotion);

	void setPotionCount(int potionCount);

	void setItem1(item newItem);

	void setItem2(item newItem);

	void setItem3(item newItem);

	//methods

};

#endif