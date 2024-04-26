#pragma once
#ifndef MENU_H
#define MENU_H

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

//START MENU CLASS
class startMenu {
private:

public:
	int print();

	std::string promptPlayerName();
};

//PLAYER MENU CLASS
class playerMenu {
private:

public:
	void print(player& player, map& currentMap);
};

//MAP PLAYER MENU CLASS
class mapPlayerMenu {
private:

public:
	int print(player& player);
};

//TEST MENU CLASS
class testMenu {
private:

public:
	//constructor
	
	//methods
	void print();

	void testLoop(int initialChoice, player& player, map& testMap, playerMenu& testMenu, std::vector<std::vector<std::string>>& testShadowyManDialogue);

};

#endif