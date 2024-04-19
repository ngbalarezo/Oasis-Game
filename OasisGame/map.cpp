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

//MAPNODE CLASS DEFINITIONS
//constructors
mapNode::mapNode() {
	isVillage = false;
	isWilderness = false;
}

//village specialized constructor
mapNode::mapNode(village nodeVillage) {
	this->nodeVillage = &nodeVillage;
	isVillage = true;
	isWilderness = false;
}

//wilderness specialized constructor
mapNode::mapNode(wilderness nodeWilderness) {
	this->nodeWilderness = &nodeWilderness;
	isVillage = false;
	isWilderness = true;
}

//getters
village mapNode::getNodeVillage() { return *nodeVillage; }

wilderness mapNode::getNodeWilderness() { return *nodeWilderness; }

bool mapNode::getIsVillage() { return isVillage; }

bool mapNode::getIsWilderness() { return isWilderness; }

//setters
void mapNode::setNodeVillage(village& nodeVillage) { this->nodeVillage = &nodeVillage; }

void mapNode::setNodeWilderness(wilderness& nodeWilderness) { this->nodeWilderness = &nodeWilderness; }


void mapNode::setIsVillage(bool isVillage) { this->isVillage = isVillage; }

void mapNode::setIsWilderness(bool isWilderness) { this->isWilderness = isWilderness; }

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
void map::generateMap(wilderness WILDERNESS[5], village VILLAGES[5]) {
	//declare variables
	std::default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	std::uniform_int_distribution<unsigned int> randomLocation{ 1,10 };
	std::uniform_int_distribution<unsigned int> randomArrayChoice{ 0,5 };
	int locationTypeChoice;
	int	randomArrayIndex;
	int coordinateI;
	int coordinateJ;
	//generate map from two arrays of pregenerated villages and wilderness locations
	//outer for loop for rows
	for (int i = 0; i < gridSize; i++) {
		//inner for loop for columns
		for (int j = 0; j < gridSize; j++) {
			//store random values
			locationTypeChoice = randomLocation(engine);
			randomArrayIndex = randomArrayChoice(engine);
			//30% chance village is generated
			if (locationTypeChoice < 4) {
				mapGrid[i][j].setNodeVillage(VILLAGES[randomArrayIndex]);
				mapGrid[i][j].setIsVillage(true);
				//sets startingMapNode to current village, making the farthest village the starting village.
				startingMapNode = &mapGrid[i][j];
				currentMapNode = startingMapNode;
				//!FIXME LEFT OFF HERE: MAKE PLAYER COORDINATE INT AND STORE THEM EITHER IN PLAYER OR INVENTORY CLASS
				coordinateI = i;
				coordinateJ = j;
			}
			//70% chance wilderness is generate
			else if (locationTypeChoice >= 4) {
				mapGrid[i][j].setNodeWilderness(WILDERNESS[randomArrayIndex]);
				mapGrid[i][j].setIsWilderness(true);
			}
		}
	}
}

void map::display() {
	//clear console and print heading
	system("CLS");
	std::cout << "MAP:" << std::endl << std::endl;
	//outer for loop for rows
	for (int i = 0; i < gridSize; i++) {
		//inner for loop for columns
		for (int j = 0; j < gridSize; j++) {
			//prints V if current node is village
			if (mapGrid[i][j].getIsVillage() == true) {
				//if village to be printed is current location
				if (&mapGrid[i][j] == currentMapNode) {
					//if node is at edge of map
					if (j == gridSize - 1) {
						std::cout << "\033[1;31mV" << std::endl;
					}
					//else node is not at edge of map
					else {
						std::cout << "\033[1;31mV " << "\033[0;37m- ";
					}
				}
				//if village to be printed is not current location
				else if (&mapGrid[i][j] != currentMapNode) {
					//if node is at edge of map
					if (j == gridSize - 1) {
						std::cout << "\033[1;34mV" << std::endl;
					}
					//else node is not at edge of map
					else {
						std::cout << "\033[1;34mV " << "\033[0;37m- ";
					}
				}
			}
			//prints W if current node is wilderness
			else if (mapGrid[i][j].getIsWilderness() == true) {
				//if wilderness to be printed is current location
				if (&mapGrid[i][j] == currentMapNode) {
					//if node is at edge of map
					if (j == gridSize - 1) {
						std::cout << "\033[0;31mW" << std::endl;
					}
					//else node is not at edge of map
					else {
						std::cout << "\033[1;31mW " << "\033[0;37m- ";
					}
				}
				//if wilderness to be printed is not current location
				else if (&mapGrid[i][j] != currentMapNode) {
					//if node is at edge of map
					if (j == gridSize - 1) {
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
		if (i != gridSize - 1) {
			//prints downward grid lines
			for (int k = 0; k < gridSize; k++) {
				//if grid line is at edge of map
				if (k == gridSize - 1) {
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

//!FIXME: NOTES
//! WALK FUNCTIONALITY IN VILLAGE MENU CLASS
//! CONSIDER WHERE TO STORE PREVIOUSLY VISITED CHURCH NODE



