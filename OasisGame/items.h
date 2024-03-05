#pragma once
#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include <string>
//!FIXME: LEFT OFF HERE, ADD IN ALL ITEM BASICS AND FINISH PRINT INVENTORY MENU IN INVENTORY PARENT CLASS...
class item {
protected:
	std::string itemName;
	int coinValue;
public:
	item(std::string itemName, int coinValue) {
		this->itemName = itemName;
		this->coinValue = coinValue;
	}
};

class weapon : item {
private:
	int atk;
	int weight;

public:
	weapon(std::string itemName, int coinValue, int atk, int weight) {
		this->itemName = itemName;
		this->coinValue = coinValue;
		this->atk = atk;
		this->weight = weight;
	}
};

class armor : item {

};

class potion : item {

};

class miscItem : item {

};

#endif