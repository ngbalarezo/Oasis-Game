#include "buildings.h"
#include "items.h"

//SHOP CLASS DEFINITIONS

//constructors

shop::shop() {
	//create null item objects
	weapon noWeapon;
	armor noArmor;
	potion noPotion;
	//set defaults to null objects
	sWeaponSlot1 = noWeapon;
	sWeaponSlot2 = noWeapon;
	sWeaponSlot3 = noWeapon;
	sArmorSlot = noArmor;
	sPotionSlot = noPotion;
	isEmpty = true;
	shopLevel = 0;
}

shop::shop(weapon sWeaponSlot1, weapon sWeaponSlot2, weapon sWeaponSlot3, armor sArmorSlot, potion sPotionSlot, bool isEmpty, int shopLevel) {
	this->sWeaponSlot1 = sWeaponSlot1;
	this->sWeaponSlot2 = sWeaponSlot2;
	this->sWeaponSlot3 = sWeaponSlot3;
	this->sArmorSlot = sArmorSlot;
	this->sPotionSlot = sPotionSlot;
	this->shopLevel = shopLevel;
}