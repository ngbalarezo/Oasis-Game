#pragma once
#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "buildings.h"
#include "characters.h"
#include "items.h"

class location {
private:
	shop localShop;
	npc localNpc1;
	npc localNpc2;
	enemy localEnemy1;
	enemy localEnemy2;
	enemy localBoss;
	location* upLocation;
	location* leftLocation;
	location* downLocation;
	location* rightLocation;

public:
	//constructors
	//!FIXME: REFACTOR CONSTRUCTORS AND CLASSES
	location() { //default constructor
		upLocation = nullptr;
		leftLocation = nullptr;
		downLocation = nullptr;
		rightLocation = nullptr;
	}

	location(shop localShop, npc localNpc1, npc localNpc2,
		enemy localEnemy1, enemy localEnemy2, enemy localBoss,
		location& upLocation, location& leftLocation,
		location& downLocation, location& rightLocation) { //full info location constructor
		this->localShop = localShop;
		this->localNpc1 = localNpc1;
		this->localNpc2 = localNpc2;
		this->localEnemy1 = localEnemy1;
		this->localEnemy2 = localEnemy2;
		this->localBoss = localBoss;
		this->upLocation = &upLocation;
		this->leftLocation = &leftLocation;
		this->downLocation = &downLocation;
		this->rightLocation = &rightLocation;
	}

	location(shop localShop, npc localNpc1, npc localNpc2, 
			 location& upLocation, location& leftLocation,
			 location& downLocation, location& rightLocation) { //village constructor, !FIXME: CREATE OTHER BUILDINGS

	}

	location(npc localNpc1, enemy localEnemy1, 
			 enemy localEnemy2, enemy localBoss,
			 location& upLocation, location& leftLocation,
			 location& downLocation, location& rightLocation) { //outer area constructor
		
	}

	//getters
	shop getLocalShop() { return localShop; }

	npc getLocalNpc1() { return localNpc1; }

	npc getLocalNpc2() { return localNpc2; }

	enemy getLocalEnemy1() { return localEnemy1; }

	enemy getLocalEnemy2() { return localEnemy2; }

	enemy getLocalBoss() { return localBoss; }

	location* getUpLocation() { return upLocation; }

	location* getLeftLocation() { return leftLocation; }

	location* getDownLocation() { return downLocation; }

	location* getRightLocation() { return rightLocation; }

	//setters
	void setLocalShop(shop& localShop) { this->localShop = localShop; }

	void setLocalNpc1(npc& localNpc1) { this->localNpc1 = localNpc1; }

	void setLocalNpc2(npc& localNpc2) { this->localNpc2 = localNpc2; }

	void setLocalEnemy1(enemy& localEnemy1) { this->localEnemy1 = localEnemy1; }

	void setLocalEnemy2(enemy& localEnemy2) { this->localEnemy2 = localEnemy2; }

	void setLocalBoss(enemy& localBoss) { this->localBoss = localBoss; }

	void setUpLocation(location& upLocation) { this->upLocation = &upLocation; }

	void setLeftLocation(location& leftLocation) { this->leftLocation = &leftLocation; }

	void setDownLocation(location& downLocation) { this->downLocation = &downLocation; }

	void setRightLocation(location& rightLocation) { this->rightLocation = &rightLocation; }

	//methods

};

class map {
private:
	location* startingLocation;
	location* currentLocation;
	location* prevLocationVisited;

public:
	//constructors
	map() {
		startingLocation = nullptr;
		currentLocation = nullptr;
		prevLocationVisited = nullptr;
	}

	map(location* startingLocation, location* currentLocation, location* prevLocationVisited) {
		this->startingLocation = startingLocation;
		this->currentLocation = currentLocation;
		this->prevLocationVisited = prevLocationVisited;
	}

	//getters
	location* getStartingLocation() { return startingLocation; }

	location* getCurrentLocation() { return currentLocation; }

	location* getPrevLocationVisited() { return prevLocationVisited; }

	//setters
	void setStartingLocation(location& startingLocation) { this->startingLocation = &startingLocation; }

	void setCurrentLocation(location& currentLocation) { this->currentLocation = &currentLocation; }

	void setPrevLocationVisited(location& prevLocationVisited) { this->prevLocationVisited = &prevLocationVisited; }

	//methods

};


#endif
