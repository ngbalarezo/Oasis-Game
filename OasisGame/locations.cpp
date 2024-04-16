#include <iostream>
#include <iomanip>
#include "locations.h"
#include "buildings.h"
#include "characters.h"
#include "items.h"

//WILDERNESS CLASS DEFINITIONS
//constructors
wilderness::wilderness() {  } //default constructor

//initialize wilderness with custom members, non-boss location
wilderness::wilderness(npc localNpc1, enemy localEnemy1, enemy localEnemy2) {
    this->localNpc1 = localNpc1;
    this->localEnemy1 = localEnemy1;
    this->localEnemy2 = localEnemy2;
    isBossBattleLocation = false;
}

//initialize wilderness with custom members, boss battle location
wilderness::wilderness(npc localNpc1, enemy localEnemy1, enemy localEnemy2, enemy localBoss, bool isBossBattleLocation) {
    this->localNpc1 = localNpc1;
    this->localEnemy1 = localEnemy1;
    this->localEnemy2 = localEnemy2;
    this->localBoss = localBoss;
    this->isBossBattleLocation = isBossBattleLocation;
}

//getters
npc wilderness::getLocalNpc1() { return localNpc1; }

enemy wilderness::getLocalEnemy1() { return localEnemy1; }

enemy wilderness::getLocalEnemy2() { return localEnemy2; }

enemy wilderness::getLocalBoss() { return localBoss; }

//setters
void wilderness::setLocalNpc1(npc& localNpc1) { this->localNpc1 = localNpc1; }

void wilderness::setLocalEnemy1(enemy& localEnemy1) { this->localEnemy1 = localEnemy1; }

void wilderness::setLocalEnemy2(enemy& localEnemy2) { this->localEnemy2 = localEnemy2; }

void wilderness::setLocalBoss(enemy& localBoss) { this->localBoss = localBoss; }

//methods

//VILLAGE CLASS DEFINITIONS
//constructors
village::village() {  } //default constructor

//initialize village with custom members
village::village(shop localShop, Church localChurch, npc localNpc1, npc localNpc2) {
    this->localShop = localShop;
    this->localChurch = localChurch;
    this->localNpc1 = localNpc1;
    this->localNpc2 = localNpc2;
}

//getters
shop village::getLocalShop() { return localShop; }

Church village::getLocalChurch() { return localChurch; }

npc village::getLocalNpc1() { return localNpc1; }

npc village::getLocalNpc2() { return localNpc2; }

//setters
void village::setLocalShop(shop& localShop) { this->localShop = localShop; }

void village::setLocalChurch(Church& localChurch) { this->localChurch = localChurch; }

void village::setLocalNpc1(npc& localNpc1) { this->localNpc1 = localNpc1; }

void village::setLocalNpc2(npc& localNpc2) { this->localNpc2 = localNpc2; }

//methods
