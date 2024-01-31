#pragma once
#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <iostream>
#include <string>

//parent class
class character {
	int health;
	double attack;
	double defense;
};

//base classes
class player : public character {
private:

public:
};

class npc : public character {
private:

public:
};

class enemy : public character {
private:
	//members
public:
	//methods
	void battle(player &player);
};

#endif