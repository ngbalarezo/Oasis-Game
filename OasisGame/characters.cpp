#include "characters.h"
#include <random>

//<--------------!-------------->//
//character class definitions
/*character class getters*/
std::string character::getName() { return name; }
int character::getHp() { return hp; }
double character::getAtk() { return atk; }
double character::getDef() { return def; }
/*character class setters*/
void character::setName(std::string name) { this->name = name; }
void character::setHp(int hp) { this->hp = hp; }
void character::setAtk(double atk) { this->atk = atk; }
void character::setDef(double def) { this->def = def; }

//<--------------!-------------->//
//player class definitions
/*player class getters*/
int player::getFp() { return fp; }
int player::getSp() { return sp; }

/*player class setters*/
void player::setFp(int fp) { this->fp = fp; }
void player::setSp(int sp) { this->sp = sp; }

/*player class constructor*/
player::player(std::string name) {
	this->name = name;
	hp = 100;
	fp = 10;
	sp = 100;
	atk = 2;
	def = 2;
}

//<--------------!-------------->//
//npc class definitions

//<--------------!-------------->//
//enemy class definitions
/*enemy class constructor*/
enemy::enemy() {
	hp = 20;
	atk = 10;
	def = 2;
	flees = false;
}
/*enemy class getters*/
bool enemy::getFlees() { return flees; }
/*enemy class setters*/
void enemy::setFlees(bool flees) { this->flees = flees; }

/*
*name: printBattleStats()
*parameters: player &player
*return: n/a
*description:
*/
void enemy::printBattleStats(player &player) {
	//print battle stats screen
	std::cout << "*****************************" << std::endl;
	std::cout << "Enemy: " << "[Insert enemy name]" << std::endl;//!FIXME: insert enemy name
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
void enemy::playerAttackTurn(int input, int &damageDone, std::default_random_engine &engine, player &player) {
	//declare variables
	std::uniform_int_distribution<unsigned int> enemyDodgeChance{ 1,7 };
	std::uniform_int_distribution<unsigned int> playerHeavyAttackRange{ 7,12 };
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
			if (input == 1) {
				//calculates random damage amount
				damageDone = playerHeavyAttackRange(engine);
				//!FIXME: ADD IN, calculates according to buff/nerf

				//subtracts stamina points
				player.setSp(player.getSp() - 30);
				//sets new enemy hp by subtracting damageDone from current enemy hp
				this->setHp(this->getHp() - damageDone);
				//attack landed text, pauses on this screen and then resets screen back to stats menu
				system("CLS");
				std::cout << "You strike with a heavy blow! " << damageDone << " damage done!" << std::endl;
				system("PAUSE");
				system("CLS");
			}
			//light attack
			else if (input == 2) {
				//!FIXME: insert miss chance 
			}
		}
	}
	//inventory
	else if (input == 3) {
		//insert inventory functionality
	}
	else {
		//!FIXME: insert fail proofing using while loop
	}
}

/*
*/
void enemy::enemyAttackTurn(int &damageDone, std::default_random_engine& engine, player& player) {
	//declare variables
	std::uniform_int_distribution<unsigned int> enemyMissChance{ 1,12 };
	std::uniform_int_distribution<unsigned int> enemyAttackRange{ 10,20 };
	//enemy is still alive after your attack
	if (this->getHp() > 0) {
		//determines if the enemy attack misses or not
		if (enemyMissChance(engine) == 6) {
			system("CLS");
			std::cout << "[Insert enemy name] " << " slashes wildly and misses its attack!" << std::endl;
			system("PAUSE");
			system("CLS");
		}
		else if (enemyMissChance(engine) != 6) {
			damageDone = enemyAttackRange(engine);
			player.setHp(player.getHp() - damageDone);
			//enemy attack landed text, pauses on this screen and then resets screen back to stats menu
			system("CLS");
			std::cout << "[Insert enemy name] " << "slashes you with sharp claws! " << damageDone << " damage done!" << std::endl;
			system("PAUSE");
			system("CLS");
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
void enemy::battle(player &player) {
	//declare variables
	int input;
	int damageDone;
	std::default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	std::uniform_int_distribution<unsigned int> playerLightAttackRange{ 4,6 };
	std::uniform_int_distribution<unsigned int> playerDodgeChance{1,2};
	//while loop ends battle if enemy dies, player dies, or enemy flees
	while ((player.getHp() > 0) && (this->getHp() > 0) && (this->getFlees() != true)) {
		//print enemy and player battle stats respectively
		printBattleStats(player);
		//print battle options
		input = printBattleOptions();
		//player's turn executes based on user's choice
		playerAttackTurn(input, damageDone, engine, player);
		//enemy attack turn executes based on predefined enemy stats, but only if enemy is not already dead
		enemyAttackTurn(damageDone, engine, player);
	}
	if(player.getHp() == 0) {
		system("CLS");
		std::cout << "You have been slain..." << std::endl;
		system("PAUSE");
		system("CLS");
	}
}