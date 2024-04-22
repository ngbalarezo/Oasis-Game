#pragma once
#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <iostream>
#include <string>
#include <random>
#include "menu.h"
#include "map.h"
#include "locations.h"
#include "buildings.h"
#include "characters.h"
#include "inventory.h"
#include "items.h"
#include "DialogueTree.h"

//PARENT CLASS: character
class character {
protected:
	//members
	std::string name;
	int hp;
	int atk;
	int def;
public:
	//constructor
	character();

	//methods
	std::string getName();//getters
	int getHp();
	int getAtk();
	int getDef();

	void setName(std::string name);//setters
	void setHp(int hp);
	void setAtk(int atk);
	void setDef(int def);
};

//CHILD CLASSES

//PLAYER CLASS
class player : public character {
private:
	//player-specific stats
	int fp;
	int sp;
	int weight;
	//player inventory
	playerInventory inventory;
	//coordinates
	int coordinateX;
	int coordinateY;

public:
	//constructor
	player();

	player(std::string name, playerInventory inventory);

	//getters
	int getFp();

	int getSp();

	int getWeight();

	playerInventory* getInventory();

	int getCoordinateX();

	int getCoordinateY();

	//setters
	void setFp(int fp);

	void setSp(int sp);

	void setWeight(int weight);

	void setInventory(playerInventory inventory);

	void setCoordinateX(int coordinateX);

	void setCoordinateY(int coordinateY);

	//methods
	void printStats();

	void accessPlayerMenu();

};

//NPC CLASS
class npc : public character {
private:
	std::string npcName;
	dialogueTree dialogue;

public:
	//constructors
	npc();

	npc(std::string npcName);

	//getters
	std::string getNpcName();

	dialogueTree* getDialogueTree();

	//setters
	void setNpcName(std::string npcName);

	void setDialogueTree(dialogueTree dialogue);

	//methods
	void initiateDialogue();

};

//ENEMY CLASS
class enemy : public character {
private:
	//members
	bool flees;
	bool isSlain;

public:
	//constructors
	enemy();

	enemy(std::string inputName, int inputHp, int inputAtk, int inputDef, bool inputflees);

	//getters
	bool getFlees();

	bool getIsSlain();

	//setters
	void setFlees(bool flees);

	void setIsSlain(bool isSlain);

	//methods
	void printBattleStats(player &player);
	
	int printBattleOptions();
	
	int playerAttackTurn(int input, int& damageDone, std::default_random_engine& engine, player& player);
	
	void enemyAttackTurn(int playerDodges, int& damageDone, std::default_random_engine& engine, player& player);
	
	void battle(player &player);

};

#endif