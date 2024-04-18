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
	upMapNode = nullptr;
	leftMapNode = nullptr;
	downMapNode = nullptr;
	rightMapNode = nullptr;
}

//village specialized constructor
mapNode::mapNode(village nodeVillage, mapNode& upMapNode, mapNode& leftMapNode, mapNode& downMapNode, mapNode& rightMapNode) {
	this->nodeVillage = nodeVillage;
	isVillage = true;
	isWilderness = false;
	this->upMapNode = &upMapNode;
	this->leftMapNode = &leftMapNode;
	this->downMapNode = &downMapNode;
	this->rightMapNode = &rightMapNode;
}

//wilderness specialized constructor
mapNode::mapNode(wilderness nodeWilderness, mapNode& upMapNode, mapNode& leftMapNode, mapNode& downMapNode, mapNode& rightMapNode) {
	this->nodeWilderness = nodeWilderness;
	isVillage = false;
	isWilderness = true;
	this->upMapNode = &upMapNode;
	this->leftMapNode = &leftMapNode;
	this->downMapNode = &downMapNode;
	this->rightMapNode = &rightMapNode;
}

//getters
village mapNode::getNodeVillage() { return nodeVillage; }

wilderness mapNode::getNodeWilderness() { return nodeWilderness; }

bool mapNode::getIsVillage() { return isVillage; }

bool mapNode::getIsWilderness() { return isWilderness; }

mapNode* mapNode::getUpMapNode() { return upMapNode; }

mapNode* mapNode::getLeftMapNode() { return leftMapNode; }

mapNode* mapNode::getDownMapNode() { return downMapNode; }

mapNode* mapNode::getRightMapNode() { return rightMapNode; }

//setters
void mapNode::setNodeVillage(village& nodeVillage) { this->nodeVillage = nodeVillage; }

void mapNode::setNodeWilderness(wilderness& nodeWilderness) { this->nodeWilderness = nodeWilderness; }

void mapNode::setIsVillage(bool& isVillage) { this->isVillage = isVillage; }

void mapNode::setIsWilderness(bool& isWilderness) { this->isWilderness = isWilderness; }

void mapNode::setUpMapNode(mapNode& upMapNode) { this->upMapNode = &upMapNode; }

void mapNode::setUpMapNode(mapNode* upMapNode) { this->upMapNode = upMapNode; }

void mapNode::setLeftMapNode(mapNode& leftMapNode) { this->leftMapNode = &leftMapNode; }

void mapNode::setLeftMapNode(mapNode* leftMapNode) { this->leftMapNode = leftMapNode; }

void mapNode::setDownMapNode(mapNode& downMapNode) { this->downMapNode = &downMapNode; }

void mapNode::setDownMapNode(mapNode* downMapNode) { this->downMapNode = downMapNode; }

void mapNode::setRightMapNode(mapNode& rightMapNode) { this->rightMapNode = &rightMapNode; }

void mapNode::setRightMapNode(mapNode* rightMapNode) { this->rightMapNode = rightMapNode; }

//methods

//MAP CLASS DEFINITIONS
//constructors
map::map() {
	startingMapNode = nullptr;
	currentMapNode = nullptr;
	prevMapNodeVisited = nullptr;
}

//starting node initalized, current set to start, prev node set to nullptr
map::map(mapNode& startingMapNode) {
	this->startingMapNode = &startingMapNode;
	currentMapNode = nullptr;
	prevMapNodeVisited = nullptr;
}

//!FIXME: might remove, unneccesary total initialization 
map::map(mapNode& startingMapNode, mapNode& currentMapNode, mapNode& prevMapNodeVisited) {
	this->startingMapNode = &startingMapNode;
	this->currentMapNode = &currentMapNode;
	this->prevMapNodeVisited = &prevMapNodeVisited;
}

//getters
mapNode* map::getStartingMapNode() { return startingMapNode; }

mapNode* map::getCurrentMapNode() { return currentMapNode; }

mapNode* map::getPrevMapNodeVisited() { return prevMapNodeVisited; }

//setters
void map::setStartingMapNode(mapNode& startingMapNode) { this->startingMapNode = &startingMapNode; }

void map::setStartingMapNode(mapNode* startingMapNode) { this->startingMapNode = startingMapNode; }

void map::setCurrentMapNode(mapNode& currentMapNode) { this->currentMapNode = &currentMapNode; }

void map::setCurrentMapNode(mapNode* currentMapNode) { this->currentMapNode = currentMapNode; }

void map::setPrevMapNodeVisited(mapNode& prevMapNodeVisited) { this->prevMapNodeVisited = &prevMapNodeVisited; }

void map::setPrevMapNodeVisited(mapNode* prevMapNodeVisited) { this->prevMapNodeVisited = prevMapNodeVisited; }

//methods
void map::generateGrid(int n) {
	
}



