#pragma once
#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "locations.h"
#include "buildings.h"
#include "characters.h"
#include "items.h"

class mapNode {
private:
	//location contained in mapNode
	village nodeVillage;
	wilderness nodeWilderness;
	//bool to distinguish what location is in the node
	bool isVillage;
	bool isWilderness;
	//node pointers to create map options
	mapNode* upMapNode;
	mapNode* leftMapNode;
	mapNode* downMapNode;
	mapNode* rightMapNode;

public:
	//constructors
	//!FIXME: REFACTOR CONSTRUCTORS AND CLASSES
	//default constructor
	mapNode() {
		upMapNode = nullptr;
		leftMapNode = nullptr;
		downMapNode = nullptr;
		rightMapNode = nullptr;
	}

	//village specialized constructor
	mapNode(village nodeVillage, mapNode& upMapNode, mapNode& leftMapNode, mapNode& downMapNode, mapNode& rightMapNode) {
		this->nodeVillage = nodeVillage;
		isVillage = true;
		isWilderness = false;
		this->upMapNode = &upMapNode;
		this->leftMapNode = &leftMapNode;
		this->downMapNode = &downMapNode;
		this->rightMapNode = &rightMapNode;
	}

	//wilderness specialized constructor
	mapNode(wilderness nodeWilderness, mapNode& upMapNode, mapNode& leftMapNode, mapNode& downMapNode, mapNode& rightMapNode) {
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

	mapNode* getUpMapNode() { return upMapNode; }

	mapNode* getLeftMapNode() { return leftMapNode; }

	mapNode* getDownMapNode() { return downMapNode; }

	mapNode* getRightMapNode() { return rightMapNode; }

	//setters
	
	//!FIXME: SETTERS FOR VILLAGE AND WILDERNESS + BOOLS

	void setUpMapNode(mapNode& upMapNode) { this->upMapNode = &upMapNode; }

	void setLeftMapNode(mapNode& leftMapNode) { this->leftMapNode = &leftMapNode; }

	void setDownMapNode(mapNode& downMapNode) { this->downMapNode = &downMapNode; }

	void setRightMapNode(mapNode& rightMapNode) { this->rightMapNode = &rightMapNode; }

	//methods

};

//!FIXME: potentially add village and wilderness inherited classes

class map {
private:
	mapNode* startingMapNode;
	mapNode* currentMapNode;
	mapNode* prevMapNodeVisited;

public:
	//constructors
	map() {
		startingMapNode = nullptr;
		currentMapNode = nullptr;
		prevMapNodeVisited = nullptr;
	}

	map(mapNode* startingMapNode, mapNode* currentMapNode, mapNode* prevMapNodeVisited) {
		this->startingMapNode = startingMapNode;
		this->currentMapNode = currentMapNode;
		this->prevMapNodeVisited = prevMapNodeVisited;
	}

	//getters
	mapNode* getStartingMapNode() { return startingMapNode; }

	mapNode* getCurrentMapNode() { return currentMapNode; }

	mapNode* getPrevMapNodeVisited() { return prevMapNodeVisited; }

	//setters
	void setStartingMapNode(mapNode& startingMapNode) { this->startingMapNode = &startingMapNode; }

	void setCurrentMapNode(mapNode& currentMapNode) { this->currentMapNode = &currentMapNode; }

	void setPrevMapNodeVisited(mapNode& prevMapNodeVisited) { this->prevMapNodeVisited = &prevMapNodeVisited; }

	//methods

};


#endif
