#pragma once
#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <iostream>
#include <string>
#include <random>

//parent class
class character {
protected:
	//members
	std::string name;
	int hp;
	double atk;
	double def;
public:
	//constructor
	//methods
	std::string getName();//getters
	int getHp();
	double getAtk();
	double getDef();

	void setName(std::string name);//setters
	void setHp(int hp);
	void setAtk(double atk);
	void setDef(double def);
};

//base classes
class player : public character {
private:
	//members
	int fp;
	int sp;
public:
	//constructor
	player(std::string name);
	//methods
	/**/
	int getFp();
	int getSp();
	/**/
	void setFp(int fp);
	void setSp(int sp);

};

class npc : public character {
private:

public:
};

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