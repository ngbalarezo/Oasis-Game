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
	this->nodeVillage = nodeVillage;
	isVillage = true;
	isWilderness = false;
}

//wilderness specialized constructor
mapNode::mapNode(wilderness nodeWilderness) {
	this->nodeWilderness = nodeWilderness;
	isVillage = false;
	isWilderness = true;
}

//getters
village mapNode::getNodeVillage() { return nodeVillage; }

wilderness mapNode::getNodeWilderness() { return nodeWilderness; }

bool mapNode::getIsVillage() { return isVillage; }

bool mapNode::getIsWilderness() { return isWilderness; }

//setters
void mapNode::setNodeVillage(village& nodeVillage) { this->nodeVillage = nodeVillage; }

void mapNode::setNodeWilderness(wilderness& nodeWilderness) { this->nodeWilderness = nodeWilderness; }

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
void map::generateMap(wilderness* WILDERNESS[5], village* VILLAGES[5]) {
	//declare variables
	std::default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	std::uniform_int_distribution<unsigned int> randomLocation{ 1,10 };
	std::uniform_int_distribution<unsigned int> randomArrayChoice{ 0,5 };
	int locationTypeChoice;
	int	randomArrayIndex;
	//generate map from two arrays of pregenerated villages and wilderness locations
	//outer for loop for rows
	for (int i = 0; i < gridSize; i++) {
		//inner for loop for columns
		for (int j = 0; j < gridSize; j++) {
			//store random values
			locationTypeChoice = randomLocation(engine);
			randomArrayIndex = randomArrayChoice(engine);
			//30% chance village is generated
			if ((locationTypeChoice < 4)) {
				mapGrid[j][i].setNodeVillage(*VILLAGES[randomArrayIndex]);
				mapGrid[j][i].setIsVillage(true);
			}
			//70% chance wilderness is generate
			else if (locationTypeChoice >= 4) {
				mapGrid[j][i].setNodeWilderness(*WILDERNESS[randomArrayIndex]);
				mapGrid[j][i].setIsWilderness(true);
			}
		}
	}
}

void map::display() {

}

//!FIXME: NOTES
//! WALK FUNCTIONALITY IN VILLAGE MENU CLASS
//! CONSIDER WHERE TO STORE PREVIOUSLY VISITED CHURCH NODE



