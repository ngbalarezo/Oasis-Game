#pragma once
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "menu.h"
#include "map.h"
#include "locations.h"
#include "buildings.h"
#include "characters.h"
#include "inventory.h"
#include "items.h"
#include "DialogueTree.h"

//base class
class menu {

};

//derived classes
class mainMenu : public menu {
private:

public:
	//constructor
	
	//methods
	void print();
};

class pauseMenu : public menu {

};



#endif