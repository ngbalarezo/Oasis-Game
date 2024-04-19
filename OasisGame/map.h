#pragma once
#ifndef MAP_H
#define MAP_H

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

class mapNode {
private:
	//location contained in mapNode
	village* nodeVillage;
	wilderness* nodeWilderness;
	//bool to distinguish what location is in the node
	bool isVillage;
	bool isWilderness;

public:
	//constructors
	//default constructor
	mapNode();

	//village specialized constructor
	mapNode(village nodeVillage);

	//wilderness specialized constructor
	mapNode(wilderness nodeWilderness);

	//getters
	village getNodeVillage();

	wilderness getNodeWilderness();

	bool getIsVillage();

	bool getIsWilderness();

	//setters 
	void setNodeVillage(village& nodeVillage);

	void setNodeWilderness(wilderness& nodeWilderness);

	void setIsVillage(bool isVillage);

	void setIsWilderness(bool isWilderness);

	//methods

};

class map {
private:
	int gridSize;
	std::vector<std::vector<mapNode>> mapGrid;
	mapNode* startingMapNode;
	mapNode* currentMapNode;
	mapNode* prevMapNodeVisited;

public:
//constructors
//default constructor
	map();

	//!FIXME: might remove, unneccesary total initialization 
	map(mapNode& startingMapNode, mapNode& currentMapNode, mapNode& prevMapNodeVisited);

	//constructor to initialize vector with grid size
	map(int gridSize);

	//getters
	std::vector<std::vector<mapNode>> getMapGrid();

	mapNode* getStartingMapNode();

	mapNode* getCurrentMapNode();

	mapNode* getPrevMapNodeVisited();

	mapNode* getCornerNode();

	//setters
	void setMapGrid(std::vector<std::vector<mapNode>> mapGrid);
	
	void setStartingMapNode(mapNode& startingMapNode);

	void setStartingMapNode(mapNode* startingMapNode);

	void setCurrentMapNode(mapNode& currentMapNode);

	void setCurrentMapNode(mapNode* currentMapNode);

	void setPrevMapNodeVisited(mapNode& prevMapNodeVisited);

	void setPrevMapNodeVisited(mapNode* prevMapNodeVisited);

	void setCornerNode(mapNode& cornerNode);

	void setCornerNode(mapNode* cornerNode);

	//methods
	//generates a grid of mapNodes of size nxn
	void generateMap(wilderness WILDERNESS[5], village VILLAGES[5], player& player);

	void display();

	void moveLocation(player& player);

};


#endif
