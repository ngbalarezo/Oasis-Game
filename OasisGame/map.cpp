#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include "menu.h"
#include "map.h"
#include "locations.h"
#include "buildings.h"
#include "characters.h"
#include "inventory.h"
#include "items.h"
#include "DialogueTree.h"
#include "resource.h"

//MAPNODE CLASS DEFINITIONS
//constructors
mapNode::mapNode() {
	isVillage = false;
	isWilderness = false;
	wasVisited = 0;
}

//village specialized constructor
mapNode::mapNode(village nodeVillage) {
	this->nodeVillage = &nodeVillage;
	isVillage = true;
	isWilderness = false;
	wasVisited = 0;
}

//wilderness specialized constructor
mapNode::mapNode(wilderness nodeWilderness) {
	this->nodeWilderness = &nodeWilderness;
	isVillage = false;
	isWilderness = true;
	wasVisited = 0;
}

//getters
village* mapNode::getNodeVillage() { return nodeVillage; }

wilderness* mapNode::getNodeWilderness() { return nodeWilderness; }

bool mapNode::getIsVillage() { return isVillage; }

bool mapNode::getIsWilderness() { return isWilderness; }

bool mapNode::getWasVisited() { return wasVisited; }

//setters
void mapNode::setNodeVillage(village& nodeVillage) { this->nodeVillage = &nodeVillage; }

void mapNode::setNodeWilderness(wilderness& nodeWilderness) { this->nodeWilderness = &nodeWilderness; }

void mapNode::setIsVillage(bool isVillage) { this->isVillage = isVillage; }

void mapNode::setIsWilderness(bool isWilderness) { this->isWilderness = isWilderness; }

void mapNode::setWasVisited(bool wasVisited) { this->wasVisited = wasVisited; }

//methods

//MAP CLASS DEFINITIONS
//constructors
map::map() {
	startingMapNode = nullptr;
	currentMapNode = nullptr;
	prevMapNodeVisited = nullptr;
}

map::map(int gridSize) {
	std::vector<std::vector<mapNode>> mapGrid(gridSize, std::vector<mapNode>(gridSize));
	this->mapGrid = mapGrid;
	this->gridSize = gridSize;
	startingMapNode = nullptr;
	currentMapNode = nullptr;
	prevMapNodeVisited = nullptr;
}

//getters
std::vector<std::vector<mapNode>> map::getMapGrid() { return mapGrid; }

mapNode* map::getStartingMapNode() { return startingMapNode; }

mapNode* map::getCurrentMapNode() { return currentMapNode; }

mapNode* map::getPrevMapNodeVisited() { return prevMapNodeVisited; }

//setters
void map::setMapGrid(std::vector<std::vector<mapNode>> mapGrid) { this->mapGrid = mapGrid; }

void map::setStartingMapNode(mapNode& startingMapNode) { this->startingMapNode = &startingMapNode; }

void map::setStartingMapNode(mapNode* startingMapNode) { this->startingMapNode = startingMapNode; }

void map::setCurrentMapNode(mapNode& currentMapNode) { this->currentMapNode = &currentMapNode; }

void map::setCurrentMapNode(mapNode* currentMapNode) { this->currentMapNode = currentMapNode; }

void map::setPrevMapNodeVisited(mapNode& prevMapNodeVisited) { this->prevMapNodeVisited = &prevMapNodeVisited; }

void map::setPrevMapNodeVisited(mapNode* prevMapNodeVisited) { this->prevMapNodeVisited = prevMapNodeVisited; }

//methods
void map::generateMap(wilderness WILDERNESS[5], village VILLAGES[5], player& player) {
	//declare variables
	std::default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	std::uniform_int_distribution<unsigned int> randomLocation{ 1,10 };
	std::uniform_int_distribution<unsigned int> randomArrayChoice{ 0,5 };
	int locationTypeChoice;
	int	randomArrayIndex;
	int coordinateY = 0;
	int coordinateX = 0;
	//generate map from two arrays of pregenerated villages and wilderness locations
	//outer for loop for rows
	for (int y = 0; y < gridSize; y++) {
		//inner for loop for columns
		for (int x = 0; x < gridSize; x++) {
			//store random values
			locationTypeChoice = randomLocation(engine);
			randomArrayIndex = randomArrayChoice(engine);
			//30% chance village is generated
			if (locationTypeChoice < 4) {
				mapGrid[y][x].setNodeVillage(VILLAGES[randomArrayIndex]);
				mapGrid[y][x].setIsVillage(true);
				//sets startingMapNode to current village, making the farthest village the starting village.
				startingMapNode = &mapGrid[y][x];
				currentMapNode = startingMapNode;
				coordinateY = y;
				coordinateX = x;
			}
			//70% chance wilderness is generate
			else if (locationTypeChoice >= 4) {
				mapGrid[y][x].setNodeWilderness(WILDERNESS[randomArrayIndex]);
				mapGrid[y][x].setIsWilderness(true);
			}
		}
	}
	//set player coordinates to current coordinates
	player.setCoordinateY(coordinateY);
	player.setCoordinateX(coordinateX);
}

//!FIXME: ADD PRINT CURRENT LOCATION COORDINATES IN DISPLAY MAP
void map::display() {
	//clear console and print heading
	system("CLS");
	std::cout << "MAP:" << std::endl << std::endl;
	//outer for loop for rows
	for (int y = 0; y < gridSize; y++) {
		//inner for loop for columns
		for (int x = 0; x < gridSize; x++) {
			//prints V if current node is village
			if (mapGrid[y][x].getIsVillage() == true) {
				//if village to be printed is current location
				if (&mapGrid[y][x] == currentMapNode) {
					//if node is at edge of map
					if (x == gridSize - 1) {
						std::cout << "\033[1;31mV" << std::endl;
					}
					//else node is not at edge of map
					else {
						std::cout << "\033[1;31mV " << "\033[0;37m- ";
					}
				}
				//if village to be printed is not current location
				else if (&mapGrid[y][x] != currentMapNode) {
					//if node is at edge of map
					if (x == gridSize - 1) {
						std::cout << "\033[1;34mV" << std::endl;
					}
					//else node is not at edge of map
					else {
						std::cout << "\033[1;34mV " << "\033[0;37m- ";
					}
				}
			}
			//prints W if current node is wilderness
			else if (mapGrid[y][x].getIsWilderness() == true) {
				//if wilderness to be printed is current location
				if (&mapGrid[y][x] == currentMapNode) {
					//if node is at edge of map
					if (x == gridSize - 1) {
						std::cout << "\033[0;31mW" << std::endl;
					}
					//else node is not at edge of map
					else {
						std::cout << "\033[1;31mW " << "\033[0;37m- ";
					}
				}
				//if wilderness to be printed is not current location
				else if (&mapGrid[y][x] != currentMapNode) {
					//if node is at edge of map
					if (x == gridSize - 1) {
						std::cout << "\033[0;32mW" << std::endl;
					}
					//else node is not at edge of map
					else {
						std::cout << "\033[1;32mW " << "\033[0;37m- ";
					}
				}
			}
		}
		//prevent downward lines from printing below the map
		if (y != gridSize - 1) {
			//prints downward grid lines
			for (int i = 0; i < gridSize; i++) {
				//if grid line is at edge of map
				if (i == gridSize - 1) {
					std::cout << "\033[0;37m|" << std::endl;
				}
				//else grid line is not at edge of map
				else {
					std::cout << "\033[0;37m|   ";
				}
			}
		}
	}
	std::cout << std::endl;
	std::cout << "\033[0;31mRed" << "\033[0;37m = current location." << std::endl << std::endl;
	system("PAUSE");
}

void map::execLocation(player& player) {
	int userChoice = 0;
	int sentinel = 0;
	int mapDisplayChoice = 0;
	mapPlayerMenu mapPlayerMenu;
	//while loop to keep you in current location until you decide to leave
	while (sentinel != 1) {
		//display menu
		userChoice = locationDisplay();

		//execute user choice
		execChoice(userChoice, player);

		//displays player menu
		if (userChoice == 4) {
			//uses userChoice to display map if user chooses map
			while (mapDisplayChoice != 2) {
				mapDisplayChoice = mapPlayerMenu.print(player);
				if (mapDisplayChoice == 1) {
					display();
				}
			}
			mapDisplayChoice = 0;
		}
		//check if user chooses to leave the current location
		else if (userChoice == 5) {
			sentinel = moveLocation(player);
		}
	}
	//set start node to wasVisited so starting village message remains until user leaves the village.
	startingMapNode->setWasVisited(true);

}

int map::locationDisplay() {
	//generate misc. variables
	int userChoice;
	int sentinel = 0;
	char firstChar;
	std::string prefix = "";

	//loop for error proofing
	while (sentinel != 1) {
		system("CLS");
		std::cout << std::setiosflags(std::ios::left);
		//if current location is a village
		if (currentMapNode->getIsVillage() == true) {
			//sets prefix properly if it is a vowel for styling purposes
			firstChar = currentMapNode->getNodeVillage()->getLocalShop().getShopType().at(0);
			if ((firstChar == 'a') || (firstChar == 'e') || (firstChar == 'i') || (firstChar == 'o') || (firstChar == 'u')) {
				prefix = "an ";
			}
			else {
				prefix = "a ";
			}
			//print village menu
			//!FIXME: GENERATE RANDOMIZED VILLAGE ENTRY MESSAGE
			
			//prints different message if you are in the starting node for the first time
			if ((currentMapNode->getWasVisited() == false) && (currentMapNode == startingMapNode)) {
				std::cout << "======= START VILLAGE =======" << std::endl;
				std::cout << "You begin in the " << currentMapNode->getNodeVillage()->getName() << "." << std::endl<<std::endl;
				
			}
			else {
				std::cout << "========== VILLAGE ==========" << std::endl;
				std::cout << "You enter the " << currentMapNode->getNodeVillage()->getName() << "." << std::endl << std::endl;
			}
			std::cout << "Before you is " << prefix << currentMapNode->getNodeVillage()->getLocalShop().getShopType() << ", ";

			std::cout << "the local " << currentMapNode->getNodeVillage()->getLocalChurch().getChurchType() << ", ";
			//sets prefix properly if it is a vowel for styling purposes
			
			//!FIXME: ADD IN LOUNGES
			/*firstChar = currentMapNode->getNodeVillage().getLocalLounge().getShopType().at(0);
			if ((firstChar == 'a') || (firstChar == 'e') || (firstChar == 'i') || (firstChar == 'o') || (firstChar == 'u')) {
				prefix = "an ";
			}
			else {
				prefix = "a ";
			}
			std::cout << "There is" << prefix << currentMapNode->getNodeVillage().getLocalLounge().getLoungeType() << ", " << std::endl;*/
			std::cout << "and a [INSERT LOUNGE]." << std::endl;//!FIXME: FILLER LINE
			if ((currentMapNode->getWasVisited() == false) && (currentMapNode == startingMapNode)) {
				std::cout << "=============================" << std::endl << std::endl;
			}
			else {
				std::cout << "==============================" << std::endl << std::endl;
			}

			//choice options
			std::cout << "What would you like to do?" << std::endl;
			//enter shop, church, or lounge
			std::cout << "[1] Enter " << currentMapNode->getNodeVillage()->getLocalShop().getShopType() << std::endl; 
			std::cout << "[2] Enter " << currentMapNode->getNodeVillage()->getLocalChurch().getChurchType() << std::endl;
			std::cout << "[3] Enter " << "[INSERT LOUNGE]" << std::endl;
			//player menu contains inventory, player stats, and map display
			std::cout << "[4] Player Menu" << std::endl;
			//executes moveLocation function
			std::cout << "[5] Leave Village" << std::endl;
			std::cout << "Choice: ";
			std::cin >> userChoice;
			//error proofing, cuts the loop if userChoice is valid
			if ((userChoice < 1) || (userChoice > 5)) {
				system("CLS");
				std::cout << "This is not an option." << std::endl << std::endl;
				system("PAUSE");
			}
			else if ((userChoice >= 1) || (userChoice <= 5)) {
				sentinel = 1;
			}
		}

		//if current location is wilderness
		else if (currentMapNode->getIsWilderness() == true) {
			//print wilderness menu
			//!FIXME: GENERATE RANDOMIZED WILDERNESS ENTRY MESSAGE
			std::cout << "========= WILDERNESS =========" << std::endl;
			std::cout << "You enter the " << currentMapNode->getNodeWilderness()->getName() << std::endl;
			//if the wilderness area is a boss battle location
			if (currentMapNode->getNodeWilderness()->getIsBossBattleLocation() == true) {
				//!FIXME: LEFT OFF HERE, ADD IN BOSS BATTLE MENU
			}
			//if the wilderness area is not a boss battle location
			else if (currentMapNode->getNodeWilderness()->getIsBossBattleLocation() == false) {
				//NPC 1
				firstChar = currentMapNode->getNodeWilderness()->getLocalNpc1().getName().at(0);
				if ((firstChar == 'a') || (firstChar == 'e') || (firstChar == 'i') || (firstChar == 'o') || (firstChar == 'u')) {
					prefix = "an ";
				}
				else {
					prefix = "a ";
				}
				std::cout << "Before you there is " << prefix << currentMapNode->getNodeWilderness()->getLocalNpc1().getName() << ", ";
				//ENEMY 1
				firstChar = currentMapNode->getNodeWilderness()->getLocalEnemy1()->getName().at(0);
				if ((firstChar == 'a') || (firstChar == 'e') || (firstChar == 'i') || (firstChar == 'o') || (firstChar == 'u')) {
					prefix = "an ";
				}
				else {
					prefix = "a ";
				}
				std::cout << prefix << currentMapNode->getNodeWilderness()->getLocalEnemy2()->getName() << ", ";
				//ENEMY 2
				firstChar = currentMapNode->getNodeWilderness()->getLocalEnemy2()->getName().at(0);
				if ((firstChar == 'a') || (firstChar == 'e') || (firstChar == 'i') || (firstChar == 'o') || (firstChar == 'u')) {
					prefix = "an ";
				}
				else {
					prefix = "a ";
				}
				std::cout << "and " << prefix << currentMapNode->getNodeWilderness()->getLocalEnemy2()->getName() << "." << std::endl;
			}

			//std::cout << "There is" << prefix << currentMapNode->getNodeVillage().getLocalShop().getShopType() << ", " << std::endl; !FIXME: ADD IN LOUNGES
			std::cout << "===============================" << std::endl << std::endl;
			//choice options
			std::cout << "What would you like to do?" << std::endl;
			//speak with npc, or battle enemies choices display
			std::cout << "[1] Speak with " << currentMapNode->getNodeWilderness()->getLocalNpc1().getName() << std::endl;
			//slain enemy options menu
			//if local enemy 1 is slain
			if (currentMapNode->getNodeWilderness()->getLocalEnemy1()->getIsSlain() == true) {
				std::cout << "[2] Inspect slain " << currentMapNode->getNodeWilderness()->getLocalEnemy1()->getName() << std::endl;
			}
			//if local enemy 1 is not slain
			else if (currentMapNode->getNodeWilderness()->getLocalEnemy1()->getIsSlain() == false) {
				std::cout << "[2] Battle " << currentMapNode->getNodeWilderness()->getLocalEnemy1()->getName() << std::endl;
			}
			//if local enemy 2 is slain
			if (currentMapNode->getNodeWilderness()->getLocalEnemy2()->getIsSlain() == true) {
				std::cout << "[3] Inspect slain " << currentMapNode->getNodeWilderness()->getLocalEnemy2()->getName() << std::endl;
			}
			//if local enemy 2 is not slain
			else if (currentMapNode->getNodeWilderness()->getLocalEnemy2()->getIsSlain() == false) {
				std::cout << "[3] Battle " << currentMapNode->getNodeWilderness()->getLocalEnemy2()->getName() << std::endl;
			}
			//player menu contains inventory, player stats, and map display
			std::cout << "[4] Player Menu" << std::endl;
			//executes moveLocation function
			std::cout << "[5] Leave Village" << std::endl; 
			std::cout << "Choice: ";
			std::cin >> userChoice;
			//error proofing, cuts the loop if userChoice is valid
			if ((userChoice < 1) || (userChoice > 5)) {
				system("CLS");
				std::cout << "This is not an option." << std::endl << std::endl;
				system("PAUSE");
			}
			else if ((userChoice >= 1) || (userChoice <= 5)) {
				sentinel = 1;
			}
		}
	}
	return userChoice;
}

int map::execChoice(int& userChoice, player& player) {
	//if current location is a village
	if (currentMapNode->getIsVillage() == true) {
		//player enters lcoal shop
		if (userChoice == 1) {
			currentMapNode->getNodeVillage()->getLocalShop().enterShop(player);
		}
		//player enters local Church
		else if (userChoice == 2) {
			currentMapNode->getNodeVillage()->getLocalChurch().enterChurch(player);
		}
		//player enters local lounge
		else if (userChoice == 3) {
			//!FIXME: ADD IN LOUNGE
			//currentMapNode->getNodeVillage().getLocalLounge().enterLounge();
			//!FIXME: remove test message after lounge is added
			system("CLS");
			std::cout << "LOUNGE ENTERED." << std::endl << std::endl;
			system("PAUSE");
		}
	}
	//if current location is wilderness
	else if (currentMapNode->getIsWilderness() == true) {
		//boss battle wilderness
		//!FIXME: ADD BOSS BATTLE INTO A RUINS LOCATION, "THE GOOD PEOPLE OF THESE RUINS MAY MOVE IN AND BEGIN TO REBUILD..."

		//regular wilderness
		if (userChoice == 1) {
			//!FIXME: FINISH PLAYER PRINT DIALOGUE/MAYBE MOVE THIS TO A NPC VECTOR INSTEAD OF AN ENTIRE DIALOGUE TREE 
			currentMapNode->getNodeWilderness()->getLocalNpc1().getDialogueTree()->printDialogue();
		}
		else if (userChoice == 2) {
			currentMapNode->getNodeWilderness()->getLocalEnemy1()->battle(player);
		}
		else if (userChoice == 3) {
			currentMapNode->getNodeWilderness()->getLocalEnemy2()->battle(player);
		}
	}
	return userChoice;
}

//Moves player to a new node in the map. Player can travel North, East, South, and West
int map::moveLocation(player& player) {
	//declare variables
	int userChoice;
	int sentinel = 0;
	int newY = 0;
	int newX = 0;
	//loop for error proofing
	while (sentinel != 1) {
		//clear console
		system("CLS");
		//print direction menu
		std::cout << "Which way would you like to go?" << std::endl;
		std::cout << "[1] North" << std::endl;
		std::cout << "[2] East" << std::endl;
		std::cout << "[3] South" << std::endl;
		std::cout << "[4] West" << std::endl;
		std::cout << "[5] Exit" << std::endl;
		std::cout << "Choice: ";
		std::cin >> userChoice;
		//store current x and y coordinates
		int y = player.getCoordinateY();
		int x = player.getCoordinateX();

		//if player moves north
		if (userChoice == 1) {
			newY = y - 1;
			//if up movement doesn't walk off map
			if (newY >= 0) {
				currentMapNode = &mapGrid[newY][x];
				player.setCoordinateY(newY);
				sentinel = 1;
				//return 1 to signify that user actually moved location
				return 1;
			}
			//if up movement does walk off map
			else if (newY < 0) {
				system("CLS");
				std::cout << "You are at the edge of the map!" << std::endl << std::endl;
				system("PAUSE");

			}
		}
		//if player moves east
		else if (userChoice == 2) {
			newX = x - 1;
			//if up movement doesn't walk off map
			if (newY >= 0) {
				currentMapNode = &mapGrid[y][newX];
				player.setCoordinateX(newX);
				sentinel = 1;
				//return 1 to signify that user actually moved location
				return 1;
			}
			//if up movement does walk off map
			else if (newX < 0) {
				system("CLS");
				std::cout << "You are at the edge of the map!" << std::endl << std::endl;
				system("PAUSE");
			}
		}
		//if player moves south
		else if (userChoice == 3) {
			newY = y + 1;
			//if up movement doesn't walk off map
			if (newY <= (gridSize - 1)) {
				currentMapNode = &mapGrid[newY][x];
				player.setCoordinateY(newY);
				sentinel = 1;
				//return 1 to signify that user actually moved location
				return 1;
			}
			//if up movement does walk off map
			else if (newY > (gridSize - 1)) {
				system("CLS");
				std::cout << "You are at the edge of the map!" << std::endl << std::endl;
				system("PAUSE");
			}
		}
		//if user moves west
		else if (userChoice == 4) {
			newX = x + 1;
			//if up movement doesn't walk off map
			if (newX <= (gridSize - 1)) {
				currentMapNode = &mapGrid[y][newX];
				player.setCoordinateX(newX);
				sentinel = 1;
				//return 1 to signify that user actually moved location
				return 1;
			}
			//if up movement does walk off map
			else if (newX > (gridSize - 1)) {
				system("CLS");
				std::cout << "You are at the edge of the map!" << std::endl << std::endl;
				system("PAUSE");
			}
		}
		//exit menu
		else if (userChoice == 5) {
			sentinel = 1;
			//return 0 so loop outer loop of execLocation doesn't break
			return 0;
		}
		else {
			system("CLS");
			std::cout << "This is not an option." << std::endl << std::endl;
			system("PAUSE");

		}
	}
}



