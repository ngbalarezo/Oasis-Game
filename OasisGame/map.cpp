#include <iostream>
#include <iomanip>
#include "locations.h"
#include "buildings.h"
#include "characters.h"
#include "items.h"
#include "map.h"

//!FIXME: TRANSFER MAP DEFINITIONS TO THIS FILE

//MAPNODE CLASS DEFINITIONS
//constructors

//getters

//setters

//MAP CLASS DEFINITIONS
	//constructors
map::map() {
	startingMapNode = nullptr;
	currentMapNode = nullptr;
	prevMapNodeVisited = nullptr;
}

map::map(mapNode* startingMapNode, mapNode* currentMapNode, mapNode* prevMapNodeVisited) {
	this->startingMapNode = startingMapNode;
	this->currentMapNode = currentMapNode;
	this->prevMapNodeVisited = prevMapNodeVisited;
}

//getters
mapNode* map::getStartingMapNode() { return startingMapNode; }

mapNode* map::getCurrentMapNode() { return currentMapNode; }

mapNode* map::getPrevMapNodeVisited() { return prevMapNodeVisited; }

//setters
void map::setStartingMapNode(mapNode& startingMapNode) { this->startingMapNode = &startingMapNode; }

void map::setCurrentMapNode(mapNode& currentMapNode) { this->currentMapNode = &currentMapNode; }

void map::setPrevMapNodeVisited(mapNode& prevMapNodeVisited) { this->prevMapNodeVisited = &prevMapNodeVisited; }

//methods

