#include <iostream>
#include <iomanip>
#include "menu.h"
#include "map.h"
#include "locations.h"
#include "buildings.h"
#include "characters.h"
#include "inventory.h"
#include "items.h"
#include "DialogueTree.h"

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

void mapNode::setIsVillage(bool& isVillage) { this->isVillage = isVillage; }

void mapNode::setIsWilderness(bool& isWilderness) { this->isWilderness = isWilderness; }

//methods

//MAP CLASS DEFINITIONS
//constructors
map::map() {
	startingMapNode = nullptr;
	currentMapNode = nullptr;
	prevMapNodeVisited = nullptr;
}

map::map(int gridSize) {
	std::vector<std::vector<mapNode>> mapGrid(gridSize);
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
void map::generateMap(wilderness WILDERNESS[5], village VILLAGES[5]) {
	//generate map from two arrays of pregenerated villages and wilderness locations
}

//!FIXME: NOTES
//! WALK FUNCTIONALITY IN VILLAGE MENU CLASS
//! CONSIDER WHERE TO STORE PREVIOUSLY VISITED CHURCH NODE



