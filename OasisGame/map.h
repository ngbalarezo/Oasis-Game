#pragma once
#ifndef MAP_H
#define MAP_H

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
	mapNode();

	//village specialized constructor
	mapNode(village nodeVillage, mapNode& upMapNode, mapNode& leftMapNode, mapNode& downMapNode, mapNode& rightMapNode);

	//wilderness specialized constructor
	mapNode(wilderness nodeWilderness, mapNode& upMapNode, mapNode& leftMapNode, mapNode& downMapNode, mapNode& rightMapNode);


	//getters

	//!FIXME: GETTERS FOR VILLAGE AND WILDERNESS + BOOLS

	mapNode* getUpMapNode();

	mapNode* getLeftMapNode();

	mapNode* getDownMapNode();

	mapNode* getRightMapNode();

	//setters

	//!FIXME: SETTERS FOR VILLAGE AND WILDERNESS + BOOLS

	void setUpMapNode(mapNode& upMapNode);

	void setLeftMapNode(mapNode& leftMapNode);

	void setDownMapNode(mapNode& downMapNode);

	void setRightMapNode(mapNode& rightMapNode);

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
	//default constructor
	map();

	//starting node initalized, current set to start, prev node set to nullptr
	map(mapNode* startingMapNode);

	//!FIXME: might remove, unneccesary total initialization 
	map(mapNode* startingMapNode, mapNode* currentMapNode, mapNode* prevMapNodeVisited);

	//getters
	mapNode* getStartingMapNode();

	mapNode* getCurrentMapNode();

	mapNode* getPrevMapNodeVisited();

	//setters
	void setStartingMapNode(mapNode& startingMapNode);

	void setCurrentMapNode(mapNode& currentMapNode);

	void setPrevMapNodeVisited(mapNode& prevMapNodeVisited);

	//methods

};


#endif
