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

//ITEM CLASS DEFINITIONS

//constructor
item::item() {
	itemName = "empty";
	coinValue = 0;
	weight = 0;
	isQuestItem = false;
}

item::item(std::string itemName, int coinValue, int weight, bool isQuestItem) {
	this->itemName = itemName;
	this->coinValue = coinValue;
	this->weight = weight;
	this->isQuestItem = isQuestItem;
}

//getters
std::string item::getName() { return itemName; }

int item::getCoinValue() { return coinValue; }

int item::getWeight() { return weight; }

bool item::getIsQuestItem() { return isQuestItem; }

//setters
void item::setName(std::string itemName) { this->itemName = itemName; }

void item::setCoinValue(int coinValue) { this->coinValue = coinValue; }

void item::setWeight(int weight) { this->weight = weight; }

void item::setIsQuestItem(bool isQuestItem) { this->isQuestItem = isQuestItem; }

//WEAPON CLASS DEFINITIONS

//constructor
weapon::weapon() {
	itemName = "empty";
	coinValue = 0;
	weight = 0;
	isQuestItem = false;
	atk = 1;
	focus = 0;
}

weapon::weapon(int atk, int focus) {
	itemName = "empty";
	coinValue = 0;
	weight = 0;
	isQuestItem = false;
	this->atk = atk;
	this->focus = focus;
}

weapon::weapon(std::string itemName, int coinValue, int weight, bool isQuestItem, int atk, int focus) {
	this->itemName = itemName;
	this->coinValue = coinValue;
	this->weight = weight;
	this->isQuestItem = isQuestItem;
	this->atk = atk;
	this->focus = focus;
}

//destructor
weapon::~weapon() {
	/*itemName = "empty";
	coinValue = 0;
	weight = 0;
	isQuestItem = false;
	atk = 0;
	focus = 0;*/
}

//getters
int weapon::getAtk() { return atk; }

int weapon::getFocus() { return focus; }

int weapon::getBuffPercent() { return (1 + (atk / 100)); }

//setters
void weapon::setAtk(int atk) { this->atk = atk; }

void weapon::setFocus(int focus) { this->focus = focus; }

//ARMOR CLASS DEFINITIONS

//constructor
armor::armor() {
	itemName = "empty";
	coinValue = 0;
	weight = 0;
	isQuestItem = false;
	def = 0;
}

armor::armor(std::string itemName, int coinValue, int weight, bool isQuestItem, int def) {
	this->itemName = itemName;
	this->coinValue = coinValue;
	this->weight = weight;
	this->isQuestItem = isQuestItem;
	this->def = def;
}

//getters
int armor::getDef() { return def; }

int armor::getDefPercent() { return (1 + ( def / 100)); }

//setters
void armor::setDef(int def) { this->def = def; }


//POTION CLASS DEFINITIONS

//constructor
potion::potion() {
	potionName = "empty";
	potionCount = 0;
	healValue = 0;
	staminaValue = 0;
	focusValue = 0;
	coinValue = 0;
}

potion::potion(std::string potionName, int potionCount, int healValue, int staminaValue, int focusValue, int coinValue) {
	this->potionName = potionName;
	this->potionCount = potionCount;
	this->healValue = healValue;
	this->staminaValue = staminaValue;
	this->focusValue = focusValue;
	this->coinValue = coinValue * potionCount;
}

//getters
std::string potion::getName() { return potionName; }

int potion::getPotionCount() { return potionCount; }

int potion::getHealValue() { return healValue; }

int potion::getStaminaValue() { return staminaValue; }

int potion::getFocusValue() { return focusValue; }

int potion::getCoinValue() { return coinValue; }

//setters
void potion::setName(std::string potionName) { this->potionName = potionName; }

void potion::setPotionCount(int potionCount) { this->potionCount = potionCount; }

void potion::setHealValue(int healValue) { this->healValue = healValue; }

void potion::setStaminaValue(int staminValue) { this->staminaValue = staminValue; }

void potion::setFocusValue(int focusValue) { this->focusValue = focusValue; }

void potion::setCoinValue(int coinValue) { this->coinValue = coinValue; }


//DRINK CLASS DEFINITIONS

//constructor
drink::drink() {
	drinkName = "empty";
	drinkCount = 0;
	drinkCoinValue = 0;
	drinkHealValue = 0;

	/*drinkCoinValue = 0;
	drinkHealValue = 0;*/
}
drink::drink(std::string drinkName) {
	this->drinkName = drinkName;
}

drink::drink(std::string drinkName, int drinkCount, int coinValue, int wisdomEffect) {
	this->drinkName = drinkName;
	this->drinkCount = drinkCount;
	this->drinkCoinValue = coinValue;
	this->drinkHealValue = drinkHealValue;
}

//getters
std::string drink::getDrinkName() { return drinkName; }

int drink::getDrinkCount() { return drinkCount; }

int drink::getDrinkCoinValue() { return drinkCoinValue; }

int drink::getDrinkHealValue() { return drinkHealValue; }

//setters
void drink::setName(std::string drinkName) { this->drinkName = drinkName; }

void drink::setDrinkCount(int drinkCount) { this->drinkCount = drinkCount; };

void drink::setDrinkCoinValue(int drinkCoinValue) { this->drinkCoinValue = drinkCoinValue; }

void drink::setDrinkHealValue(int drinkHealValue) { this->drinkHealValue = drinkHealValue; }


