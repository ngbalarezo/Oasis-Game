#include <iostream>
#include "menu.h"
#include "map.h"
#include "locations.h"
#include "buildings.h"
#include "characters.h"
#include "inventory.h"
#include "items.h"
#include "DialogueTree.h"
/*
//menu options
void returnToOverworld() {
    std::cout << "Returned to Overworld." << std::endl;
}
void enterBattle() {
    std::cout << "Entered Battle." << std::endl;
}
void manageInventory() {
    std::cout << "Inventory Opened." << std::endl;
}
void enterShop() {
    std::cout << "Entered Shop." << std::endl;
}
void chat() {
    std::cout << "You chat with an NPC." << std::endl;
}
void quitGame() {
    std::cout << "Game Quit." << std::endl;
}

//main menu
void menu() {
    int userInput;
    std::cout << "1. Return to Game" << std::endl;
    std::cout << "2. Enter Battle" << std::endl;
    std::cout << "3. Manage Inventory" << std::endl;
    std::cout << "4. Enter Shop" << std::endl;
    std::cout << "5. Talk to Someone" << std::endl;
    std::cout << "6. Quit Game" << std::endl;

    std::cin >> userInput;
    switch (userInput) {
    case 1:
        returnToOverworld();
        break;
    case 2:
        enterBattle();
        break;
    case 3:
        manageInventory();
        break;
    case 4:
        enterShop();
        break;
    case 5:
        chat();
        break;
    case 6:
        quitGame();
        break;
    default:
        std::cout << "Not an option." << std::endl;
    }
}


//LINKED LIST MAP GRID

//declare temporary mapNode pointers
mapNode* newNode;
mapNode* newLeft;
mapNode* newRight;
mapNode* leftTemp = currentMapNode;
mapNode* rightTemp = currentMapNode;
//create start node
newNode = new mapNode; //!FIXME: ADD START VILLAGE HERE IN CONSTRUCTOR 
//set newNode to be start node
startingMapNode = newNode;
//for loop generates middle column of grid above starting location
for (int i = 0; i < n; i++) {
	//!FIXME: CONSIDER PREPROGRAMMING VILLAGE/WILDERNESS USING RANDOMIZER AND IF STATEMENTS, CONTAINING A
	//!CALL FOR DIFFERENT CONSTRUCTOR BASED ON STATS -> 30%/70% village:wilderness constructor, using village and wilderness array
	//create a new mapNode 
	newNode = new mapNode;
	//set current mapNode up to newNode
	currentMapNode->setUpMapNode(newNode);
	//current set to new upNode
	currentMapNode = currentMapNode->getUpMapNode();
}
//set current back to first node above starting location
currentMapNode = startingMapNode->getUpMapNode();

//generate rows and row connections first, while there are still rows to be generated
while (currentMapNode->getUpMapNode() != nullptr) {
	//generate left and right sides of map using leftTemp and rightTemp pointers
	for (int i = 0; i < (n / 2); ) {
		//create new left and right node
		newLeft = new mapNode;
		newRight = new mapNode;
		//set left and right mapNodes to newLeft and newRight respectively
		leftTemp->setLeftMapNode(newLeft);
		rightTemp->setRightMapNode(newRight);
		//set newLeft and newRight left and right 
		newLeft->setRightMapNode(leftTemp);
		newRight->setLeftMapNode(rightTemp);
		//move left temp left and right temp right
		leftTemp = newLeft;
		rightTemp = newRight;
		//checks if the loop has reached corner
		if (i = (n / 2) - 1) {
			//stores cornerNode
			cornerNode = leftTemp;
		}
	}
	//set current to next up to generate next row
	currentMapNode = currentMapNode->getUpMapNode();
	//set right and left temp pointers to current
	leftTemp = currentMapNode;
	rightTemp = currentMapNode;
}

//generate up and down connections for all rows
mapNode* prevRowCenter;

*/




