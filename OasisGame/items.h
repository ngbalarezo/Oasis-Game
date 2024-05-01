#pragma once
#ifndef ITEMS_H
#define ITEMS_H

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

	//destructor
	~item() = default;

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

	weapon(std::string itemName, int coinValue, int weight, bool isQuestItem, int atk, int focus);

	//destructor
	virtual ~weapon();

	//getters
	int getAtk();

	int getFocus();

	int getBuffPercent();

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

	armor(std::string itemName, int coinValue, int weight, bool isQuestItem, int def);

	//destructor
	~armor() = default;

	//getters
	int getDef();

	int getDefPercent();

	//setters
	void setDef(int def);

	
};

//POTION CLASS
class potion {
private:
	std::string potionName;
	int potionCount;
	int healValue;
	int staminaValue;
	int focusValue;
	int coinValue;

public:
	//constructors
	potion();

	potion(std::string potionName, int potionCount, int healValue, int staminaValue, int focusValue, int coinValue);

	//destructor
	~potion() = default;

	//getters
	std::string getName();

	int getPotionCount();
	
	int getHealValue();

	int getStaminaValue();

	int getFocusValue();

	int getCoinValue();


	//setters
	void setName(std::string potionName);

	void setPotionCount(int potionCount);

	void setHealValue(int healValue);

	void setStaminaValue(int staminValue);

	void setFocusValue(int focusValue);

	void setCoinValue(int setCoinValue);

};


//DRINK CLASS FOR BAR
class drink: public item {
protected:
	std::string drinkName;
	int drinkCount;
	int drinkCoinValue;
	int drinkHealValue;

public:
	//constructors
	drink();
	drink(std::string drinkName);
	drink(std::string drinkName,int drinkCount,  int coinValue, int wisdomEffect);

	

	//getters
	std::string getDrinkName();

	int getDrinkCount();

	int getDrinkCoinValue();

	int getDrinkHealValue();

	//setters
	void setName(std::string drinkName);

	void setDrinkCount(int drinkCount);

	void setDrinkCoinValue(int drinkCoinValue);

	void setDrinkHealValue(int drinkHealValue);


};


#endif