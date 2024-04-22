#pragma once
#ifndef LOCATIONS_H
#define LOCATIONS_H

#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include <string>
#include "menu.h"
#include "map.h"
#include "locations.h"
#include "buildings.h"
#include "characters.h"
#include "inventory.h"
#include "items.h"
#include "DialogueTree.h"

class wilderness {
private:
    std::string name;
    npc localNpc1;
    enemy localEnemy1;
    enemy localEnemy2;
    enemy localBoss;
    bool isBossBattleLocation;

public:
    //constructors
    wilderness(); //default constructor

    //initialize wilderness with custom members, non-boss location
    wilderness(std::string name, npc& localNpc1, enemy& localEnemy1, enemy& localEnemy2);

    //initialize wilderness with custom members, boss battle location
    wilderness(enemy& localBoss, bool isBossBattleLocation);
    
    //getters
    std::string getName();

    npc getLocalNpc1();

    enemy* getLocalEnemy1();

    enemy* getLocalEnemy2();

    enemy* getLocalBoss();

    bool getIsBossBattleLocation();

    //setters
    void setName(std::string name);
    
    void setLocalNpc1(npc& localNpc1);

    void setLocalEnemy1(enemy& localEnemy1);

    void setLocalEnemy2(enemy& localEnemy2);

    void setLocalBoss(enemy& localBoss);

    void setIsBossBattleLocation(bool isBossBattleLocation);

    //methods
};

class village {
private:
    std::string name;
    shop localShop;
    Church localChurch;
    npc localNpc1;
    npc localNpc2;

public:
    //constructors
    //default constructor
    village();

    //initialize village with custom members
    village(std::string name, shop localShop, Church localChurch, npc localNpc1, npc localNpc2);

    //getters
    std::string getName();

    shop getLocalShop();

    Church getLocalChurch();

    npc* getLocalNpc1();

    npc* getLocalNpc2();

    //setters
    void setName(std::string name);

    void setLocalShop(shop& localShop);

    void setLocalChurch(Church& localChurch);

    void setLocalNpc1(npc& localNpc1);

    void setLocalNpc2(npc& localNpc2);

    //methods

};


#endif