#include <iostream>
#include <iomanip>
#include "locations.h"
#include "buildings.h"
#include "characters.h"
#include "items.h"
#include "map.h"

//!FIXME: TRANSFER MAP DEFINITIONS TO THIS FILE

//MAPNODE CLASS DEFINITIONS
//default constructor
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

//!FIXME: GETTERS FOR VILLAGE AND WILDERNESS + BOOLS

mapNode* mapNode::getUpMapNode() { return upMapNode; }

mapNode* mapNode::getLeftMapNode() { return leftMapNode; }

mapNode* mapNode::getDownMapNode() { return downMapNode; }

mapNode* mapNode::getRightMapNode() { return rightMapNode; }

//setters

//!FIXME: SETTERS FOR VILLAGE AND WILDERNESS + BOOLS

void mapNode::setUpMapNode(mapNode& upMapNode) { this->upMapNode = &upMapNode; }

void mapNode::setLeftMapNode(mapNode& leftMapNode) { this->leftMapNode = &leftMapNode; }

void mapNode::setDownMapNode(mapNode& downMapNode) { this->downMapNode = &downMapNode; }

void mapNode::setRightMapNode(mapNode& rightMapNode) { this->rightMapNode = &rightMapNode; }

//methods

//MAP CLASS DEFINITIONS
// //constructors
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


