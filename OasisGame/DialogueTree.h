#pragma once
#ifndef DIALOGUETREE_H
#define DIALOGUETREE_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "menu.h"
#include "map.h"
#include "locations.h"
#include "buildings.h"
#include "characters.h"
#include "inventory.h"
#include "items.h"

class dialogueTree {
private:
	std::vector<std::vector<std::string>> dialogueVector;

public:
	//constructors
	dialogueTree();

	dialogueTree(std::vector<std::vector<std::string>> dialogueVector);

	//getters
	std::vector<std::vector<std::string>> getDialogueVector();

	//setters
	void setDialogueVector(std::vector<std::vector<std::string>> dialogueVector);

	//methods
	void printDialogue();

};

#endif
