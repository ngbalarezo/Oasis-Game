#include <iostream>
#include <iomanip>
#include <random>
#include "menu.h"
#include "map.h"
#include "locations.h"
#include "buildings.h"
#include "characters.h"
#include "inventory.h"
#include "items.h"
#include "DialogueTree.h"

//CHARACTER CLASS DEFINITIONS

//constructors
character::character() {
	name = "null";
	hp = 100;
	atk = 0;
	def = 0;
}

//getters
std::string character::getName() { return name; }

int character::getHp() { return hp; }

int character::getAtk() { return atk; }

int character::getDef() { return def; }

//setters
void character::setName(std::string name) { this->name = name; }

void character::setHp(int hp) { this->hp = hp; }

void character::setAtk(int atk) { this->atk = atk; }

void character::setDef(int def) { this->def = def; }

//PLAYER CLASS DEFINITIONS

//contructor
player::player() {
	playerInventory emptyInventory;
	name = "null";
	hp = 100;
	fp = 0;
	sp = 100;
	atk = 0;
	def = 0;
	weight = 0;
	inventory = emptyInventory;
	coordinateX = 0;
	coordinateY = 0;
}

player::player(std::string name, playerInventory inventory) {
	this->name = name;
	hp = 100;
	fp = 10;
	sp = 100;
	atk = 0;
	def = 0;
	weight = 0;
	this->inventory = inventory;
	coordinateX = 0;
	coordinateY = 0;
}

//getters
int player::getFp() { return fp; }

int player::getSp() { return sp; }

int player::getWeight() { return weight; }

playerInventory* player::getInventory() { return &inventory; }

int player::getCoordinateX() { return coordinateX; }

int player::getCoordinateY() { return coordinateY; }

//setters
void player::setFp(int fp) { this->fp = fp; }

void player::setSp(int sp) { this->sp = sp; }

void player::setWeight(int weight) { this->weight = weight; }

void player::setInventory(playerInventory inventory) { this->inventory = inventory; }

void player::setCoordinateX(int coordinateX) { this->coordinateX = coordinateX; }

void player::setCoordinateY(int coordinateY) { this->coordinateY = coordinateY; }

//methods
void player::printStats() {
	std::cout << name << " Stats: " << std::endl;
	std::cout << "====================" << std::endl;
	std::cout << "HP: " << hp << std::endl;
	std::cout << "SP: " << sp << std::endl;
	std::cout << "FP: " << fp << std::endl;
	std::cout << "Atk: " << atk << std::endl;
	std::cout << "Def: " << def << std::endl;
	std::cout << "Weight: " << weight << std::endl;
	std::cout << "Coin: " << inventory.getCointCount() << std::endl;
	std::cout << "====================" << std::endl << std::endl;
}

void player::accessPlayerMenu(){
	
}

//NPC CLASS DEFINITIONS

//constructors
npc::npc() {
	npcName = "null";
}

npc::npc(std::string npcName) {
	this->npcName = npcName;
}

//getters
std::string npc::getNpcName() { return npcName; }

dialogueTree* npc::getDialogueTree() { return &dialogue; }

//setters
void npc::setNpcName(std::string npcName) { this->npcName = npcName; }

void npc::setDialogueTree(dialogueTree dialogue) { dialogue = dialogue; }

//methods

//ENEMY CLASS DEFINITIONS

//constructor
enemy::enemy() {
	hp = 20;
	atk = 10;
	def = 2;
	flees = false;
}

enemy::enemy(std::string inputName, int inputHp, int inputAtk, int inputDef, bool inputflees) {
	name = inputName;
	hp = inputHp;
	atk = inputAtk;
	def = inputDef;
	flees = inputflees;
}

//getters
bool enemy::getFlees() { return flees; }

//setters
void enemy::setFlees(bool flees) { this->flees = flees; }

//methods

/*
*name: printBattleStats()
*parameters: player &player
*return: n/a
*description:
*/
void enemy::printBattleStats(player& player) {
	//print battle stats screen
	std::cout << "*****************************" << std::endl;
	std::cout << "Enemy: " << name << std::endl;
	std::cout << "HP: " << this->getHp() << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Player: " << player.getName() << std::endl;
	std::cout << "HP: " << player.getHp() << std::endl;
	std::cout << "FP: " << player.getFp() << std::endl;
	std::cout << "SP: " << player.getSp() << std::endl;
	std::cout << "*****************************" << std::endl;
	std::cout << std::endl;
}

/*
*/
int enemy::printBattleOptions() {
	int input;
	//print battle options
	std::cout << "Choose a battle option!" << std::endl;
	std::cout << "[1] Heavy Attack" << std::endl;
	std::cout << "[2] Light Attack" << std::endl;
	std::cout << "[3] Inventory" << std::endl;
	//input and return choice
	std::cout << "Choice: ";
	std::cin >> input;
	system("CLS");
	return input;
}
/*
*/
int enemy::playerAttackTurn(int input, int& damageDone, std::default_random_engine& engine, player& player) {
	//declare variables
	std::uniform_int_distribution<unsigned int> enemyDodgeChance{ 1,7 };
	std::uniform_int_distribution<unsigned int> playerHeavyAttackRange{ 7,12 };
	std::uniform_int_distribution<unsigned int> playerLightAttackRange{ 4,6 };
	std::uniform_int_distribution<unsigned int> playerLightAttackDodgeChance{ 0,1 };
	int playerDodges = 0;
	//if statement checks wheter user attacks or uses inventory
	if ((input == 1) || (input == 2)) {
		//if-else if tree checks if enemy dodges user attack or not
		if (enemyDodgeChance(engine) == 6) {
			//print enemy dodged your attack menu
			system("CLS");
			std::cout << "You lunge forward but the enemy dodges... " << std::endl;
			system("PAUSE");
			system("CLS");
		}
		else if (enemyDodgeChance(engine) != 6) {
			//heavy attack: uses 30 sp, does 7-12 base damage
			int totalDamageDone = 0; //the total amount of damage done (damage after the percentBuff)
			if (input == 1) {
				//calculates random damage amount
				damageDone = playerHeavyAttackRange(engine);
				//!FIXME: ADD IN, calculates according to buff/nerf
				totalDamageDone = damageDone * player.getInventory()->getWeapon().getBuffPercent();
				//subtracts stamina points NOTE: WEIGHT = AMMOUT IT TAKES OFF FROM SP!!!
				player.setSp(player.getSp() - player.getInventory()->getWeapon().getWeight() - 10);
				//sets new enemy hp by subtracting damageDone from current enemy hp
				this->setHp(this->getHp() - totalDamageDone);
				//attack landed text, pauses on this screen and then resets screen back to stats menu
				system("CLS");
				std::cout << "You strike with a heavy blow! " << totalDamageDone << " damage done!" << std::endl;
				system("PAUSE");
				system("CLS");
			}
			//light attack
			else if (input == 2) {
				//calculates randomized 50/50 player dodge chance
				playerDodges = playerLightAttackDodgeChance(engine);
				//calculates random damage amount
				damageDone = playerLightAttackRange(engine);
				//!FIXME: ADD IN, calculates according to buff/nerf
				totalDamageDone = damageDone * player.getInventory()->getWeapon().getBuffPercent();
				//subtracts stamina points NOTE: WEIGHT = HALF THE AMMOUT IT TAKES OFF FROM SP!!!
				player.setSp(player.getSp() - ((player.getInventory()->getWeapon().getWeight()) + ((player.getInventory()->getWeapon().getWeight()) / 2)) - 7);
				//sets new enemy hp by subtracting damageDone from current enemy hp
				this->setHp(this->getHp() - totalDamageDone);
				//attack landed text, pauses on this screen and then resets screen back to stats menu
				system("CLS");
				std::cout << "You strike with a heavy blow! " << totalDamageDone << " damage done!" << std::endl;
				system("PAUSE");
				system("CLS");
			}
		}
	}
	//inventory
	else if (input == 3) {
		//display player inventory
		player.getInventory()->battleDisplay();
		//pauses and clears console
		system("PAUSE");
		system("CLS");
		//sets playerDodges to 3 as return value to prevent enemy from attacking if user picks inventory
		playerDodges = 3;
	}
	else {
		//!FIXME: why do letters break it?
		system("CLS");
		std::cout << "This is not an option. Choose again." << std::endl;
		system("PAUSE");
		system("CLS");
		//sets playerDodges to 3 as return value to prevent enemy from attacking if user picks null option
		playerDodges = 3;
	}
	return playerDodges;
}

/*
*/
void enemy::enemyAttackTurn(int playerDodges, int& damageDone, std::default_random_engine& engine, player& player) {
	//declare variables
	unsigned int atkUnsigned = atk;
	std::uniform_int_distribution<unsigned int> enemyAttackRange{ (atkUnsigned - 20), atkUnsigned };
	std::uniform_int_distribution<unsigned int> enemyMissChance{ 1,12 };
	//enemy is still alive after your attack
	if (this->getHp() > 0) {
		//determines whether player dodges based on value returned from playerAttackTurn
		//player dodges
		if (playerDodges == 1) {
			system("CLS");
			std::cout << "Swiftly you dodge the enemy!" << std::endl;
			system("PAUSE");
			system("CLS");
		}
		//player does not dodge
		else if (playerDodges == 0) {
			//determines if the enemy attack misses or not
			if (enemyMissChance(engine) == 6) {
				system("CLS");
				//!FIXME: ENEMY NAME FEATURE
				std::cout << "[Insert enemy name] " << " slashes wildly and misses its attack!" << std::endl;
				system("PAUSE");
				system("CLS");
			}
			else if (enemyMissChance(engine) != 6) {
				int totalEnemyDamage;
				damageDone = enemyAttackRange(engine);
				totalEnemyDamage = damageDone - player.getInventory()->getArmor().getDefPercent();
				player.setHp(player.getHp() - damageDone);
				//enemy attack landed text, pauses on this screen and then resets screen back to stats menu
				system("CLS");
				std::cout << name << "slashes you with sharp claws! " << totalEnemyDamage << " damage done!" << std::endl;
				system("PAUSE");
				system("CLS");
			}
		}
	}
	//enemy dies after your attack
	else {
		system("CLS");
		std::cout << "[Insert enemy name] " << "has been slain!" << std::endl;
		system("PAUSE");
		system("CLS");
	}
}

/*
*name: battle()
*parameters: player &player
*return: n/a
*description:
*/
void enemy::battle(player& player) {
	//declare variables
	int input;
	int damageDone;
	int playerDodges = 0;
	std::default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	//while loop ends battle if enemy dies, player dies, or enemy flees
	while ((player.getHp() > 0) && (this->getHp() > 0) && (this->getFlees() != true)) {
		playerDodges = 0;
		//print enemy and player battle stats respectively
		printBattleStats(player);
		//print battle options
		input = printBattleOptions();
		//player's turn executes based on user's choice
		playerDodges = playerAttackTurn(input, damageDone, engine, player);
		//enemy attack turn executes based on predefined enemy stats, but only if enemy is not already dead
		if (playerDodges == 3) {
			continue;
		}
		else {
			enemyAttackTurn(playerDodges, damageDone, engine, player);
		}
	}
	if (player.getHp() == 0) {
		system("CLS");
		std::cout << "You have been slain..." << std::endl;
		system("PAUSE");
		system("CLS");
	}
}