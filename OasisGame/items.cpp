#include "characters.h"
#include "inventory.h"
#include "items.h"


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
	atk = 0;
	focus = 0;
}

weapon::weapon(int atk, int focus) : item(itemName, coinValue, weight, isQuestItem) {
	this->itemName = itemName;
	this->coinValue = coinValue;
	this->weight = weight;
	this->isQuestItem = isQuestItem;
	this->atk = atk;
	this->focus = focus;
}

//getters
int weapon::getAtk() { return atk; }

int weapon::getFocus() { return focus; }

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

armor::armor(int def) : item(itemName, coinValue, weight, isQuestItem) {
	this->itemName = itemName;
	this->coinValue = coinValue;
	this->weight = weight;
	this->isQuestItem = isQuestItem;
	this->def = def;
}

//getters
int armor::getDef() { return def; }

//setters
void armor::setDef(int def) { this->def = def; }

//POTION CLASS DEFINITIONS

//constructor
potion::potion() {
	potionName = "empty";
	healValue = 0;
	staminaValue = 0;
	focusValue = 0;
}

potion::potion(std::string potionName, int healValue, int staminaValue, int focusValue, int coinValue) {
	this->potionName = potionName;
	this->healValue = healValue;
	this->staminaValue = staminaValue;
	this->focusValue = focusValue;
	this->coinValue = coinValue;
}

//getters
std::string potion::getPotionName() { return potionName; }

int potion::getHealValue() { return healValue; }

int potion::getStaminaValue() { return staminaValue; }

int potion::getFocusValue() { return focusValue; }

int potion::getCoinValue() { return coinValue; }

//setters
void potion::setPotionName(std::string potionName) { this->potionName = potionName; }

void potion::setHealValue(int healValue) { this->healValue = healValue; }

void potion::setStaminaValue(int staminValue) { this->staminaValue = staminValue; }

void potion::setFocusValue(int focusValue) { this->focusValue = focusValue; }

void potion::setCoinValue(int setCoinValue) { this->coinValue = coinValue; }


