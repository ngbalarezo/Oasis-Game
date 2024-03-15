#pragma once
#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <iostream>
#include <string>
#include <random>
#include "inventory.h"
#include "items.h"

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

public:
	//constructor
	player(std::string name, playerInventory inventory);
	//methods
	/**/
	int getFp();
	int getSp();
	int getWeight();
	/**/
	void setFp(int fp);
	void setSp(int sp);
	void setWeight(int weight);

};

//NPC CLASS
class npc : public character {
private:

public:
};

//ENEMY CLASS
class enemy : public character {
private:
	//members
	bool flees;

public:
	//constructors
	enemy();

	//methods
	/**/
	bool getFlees();
	/**/
	void setFlees(bool flees);
	/**/
	void printBattleStats(player &player);
	/**/
	int printBattleOptions();
	/**/
	int playerAttackTurn(int input, int& damageDone, std::default_random_engine& engine, player& player);
	/**/
	void enemyAttackTurn(int playerDodges, int& damageDone, std::default_random_engine& engine, player& player);
	/**/
	void battle(player &player);

};

#endif