#include <iostream>
#include <string>
#include "inventory.h"
#include "items.h"

//INVENTORY CLASS DEFINITIONS

//PLAYER INVENTORY CLASS DEFINITIONS

//constructor
playerInventory::playerInventory() {
	potionCount = 0;
	coinCount = 0;
}

//getters
weapon playerInventory::getWeapon() { return weaponSlot; }

armor playerInventory::getArmor() { return armorSlot; }

potion playerInventory::getPotion() { return potionSlot; }

int playerInventory::getPotionCount() { return potionCount; }

miscItem playerInventory::getItemSlot1() { return itemSlot1; }

miscItem playerInventory::getItemSlot2() { return itemSlot2; }

miscItem playerInventory::getItemSlot3() { return itemSlot3; }

//setters
void playerInventory::setWeapon(weapon newWeapon) { weaponSlot = newWeapon; }

void playerInventory::setArmor(armor newArmor) { armorSlot = newArmor; }

void playerInventory::setPotion(potion newPotion) { potionSlot = newPotion; }

void playerInventory::setPotionCount(int potionCount) { this->potionCount = potionCount; }

void playerInventory::setItem1(miscItem newItem) { itemSlot1 = newItem; }

void playerInventory::setItem2(miscItem newItem) { itemSlot2 = newItem; }

void playerInventory::setItem3(miscItem newItem) { itemSlot3 = newItem; }

//methods



