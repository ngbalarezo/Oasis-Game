#pragma once
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <windows.h>
#include "menu.h"
#include "map.h"
#include "locations.h"
#include "buildings.h"
#include "characters.h"
#include "inventory.h"
#include "items.h"
#include "DialogueTree.h"
#include "resource.h"

class startMenu {
private:

public:
	int print();

	std::string promptPlayerName();
};

class testMenu {
private:

public:
	//constructor
	
	//methods
	void print();

	void testLoop(int initialChoice, player& player, map& gameMenu);
};

class playerMenu {
private:

public:
	void print(player& player);
};

class pauseMenu {
private:

public:
	void print();
};



#endif