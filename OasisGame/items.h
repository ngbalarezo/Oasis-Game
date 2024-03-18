#pragma once
#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include <string>
#include "characters.h"
#include "inventory.h"

//PARENT CLASS
//ITEM CLASS
class item {
protected:
	std::string itemName;
	int coinValue;
	int weight;
	bool isQuestItem;

public:
	//constructors
	item();

	item(std::string itemName, int coinValue, int weight, bool isQuestItem);

	//getters
	std::string getName();

	int getCoinValue();

	int getWeight();

	bool getIsQuestItem();
	//setters
	void setName(std::string itemName);

	void setCoinValue(int coinValue);

	void setWeight(int weight);

	void setIsQuestItem(bool isQuestItem);

};

//WEAPON CLASS
class weapon : public item {
private:
	int atk;
	int focus;

public:
	//constructors
	weapon();

	weapon(int atk, int focus);

	//getters
	int getAtk();

	int getFocus();

	//setters
	void setAtk(int atk);

	void setFocus(int focus);
};

//ARMOR CLASS
class armor : public item {
private:
	int def;

public:
	//constructors
	armor();

	armor(int def);

	//getters
	int getDef();

	//setters
	void setDef(int def);
	
};

//POTION CLASS
class potion {
private:
	std::string potionName;
	int healValue;
	int staminaValue;
	int focusValue;
	int coinValue;

public:
	//constructors
	potion();

	potion(std::string potionName, int healValue, int staminaValue, int focusValue, int coinValue);

	//getters
	std::string getPotionName();
	
	int getHealValue();

	int getStaminaValue();

	int getFocusValue();

	int getCoinValue();


	//setters
	void setPotionName(std::string potionName);

	void setHealValue(int healValue);

	void setStaminaValue(int staminValue);

	void setFocusValue(int focusValue);

	void setCoinValue(int setCoinValue);

};


#endif