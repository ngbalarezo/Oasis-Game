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

//WILDERNESS CLASS DEFINITIONS
//constructors
//default constructor
wilderness::wilderness() { 
    name = "null area";
    isBossBattleLocation = false;
} 

//initialize wilderness with custom members, non-boss location
wilderness::wilderness(std::string name, npc& localNpc1, enemy& localEnemy1, enemy& localEnemy2) {
    this->name = name;
    this->localNpc1 = localNpc1;
    this->localEnemy1 = localEnemy1;
    this->localEnemy2 = localEnemy2;
    isBossBattleLocation = false;
}

//initialize wilderness with custom members, boss battle location
wilderness::wilderness(enemy& localBoss, bool isBossBattleLocation) {
    this->localBoss = localBoss;
    this->isBossBattleLocation = isBossBattleLocation;
}

//getters
std::string wilderness::getName() { return name; }

npc wilderness::getLocalNpc1() { return localNpc1; }

enemy* wilderness::getLocalEnemy1() { return &localEnemy1; }

enemy* wilderness::getLocalEnemy2() { return &localEnemy2; }

enemy* wilderness::getLocalBoss() { return &localBoss; }

bool wilderness::getIsBossBattleLocation() { return isBossBattleLocation; }

//setters
void wilderness::setName(std::string name) { this->name = name; }

void wilderness::setLocalNpc1(npc& localNpc1) { this->localNpc1 = localNpc1; }

void wilderness::setLocalEnemy1(enemy& localEnemy1) { this->localEnemy1 = localEnemy1; }

void wilderness::setLocalEnemy2(enemy& localEnemy2) { this->localEnemy2 = localEnemy2; }

void wilderness::setLocalBoss(enemy& localBoss) { this->localBoss = localBoss; }

void wilderness::setIsBossBattleLocation(bool isBossBattleLocation) { this->isBossBattleLocation = isBossBattleLocation; }

//methods

//VILLAGE CLASS DEFINITIONS
//constructors
//default constructor
village::village() {
    name = "null village";
} 

//initialize village with custom members
village::village(std::string name, shop localShop, Church localChurch, npc localNpc1, npc localNpc2) {
    this->name = name;
    this->localShop = localShop;
    this->localChurch = localChurch;
    this->localNpc1 = localNpc1;
    this->localNpc2 = localNpc2;
}

//getters
std::string village::getName() { return name; }

shop village::getLocalShop() { return localShop; }

Church village::getLocalChurch() { return localChurch; }

npc* village::getLocalNpc1() { return &localNpc1; }

npc* village::getLocalNpc2() { return &localNpc2; }

//setters
void village::setName(std::string name) { this->name = name; }

void village::setLocalShop(shop& localShop) { this->localShop = localShop; }

void village::setLocalChurch(Church& localChurch) { this->localChurch = localChurch; }

void village::setLocalNpc1(npc& localNpc1) { this->localNpc1 = localNpc1; }

void village::setLocalNpc2(npc& localNpc2) { this->localNpc2 = localNpc2; }

//methods
