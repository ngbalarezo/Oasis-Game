#include <iostream>
#include "menu.h"
#include "map.h"
#include "locations.h"
#include "buildings.h"
#include "characters.h"
#include "inventory.h"
#include "items.h"
#include "DialogueTree.h"

/*
//reset playerChoice so that error-proofing loop may begin
	playerChoice = 0;
	//error-proofing while loop
	while ((playerChoice < 1) || (playerChoice > 7)) {
		std::cout << "Which item would you like to drop?" << std::endl << std::endl;
		std::cout << "================================================================" << std::endl << std::endl; //!FIXME: LEFT OFF HERE
		std::cout << "[1] " << std::setw(25) << player.getInventory()->getWeapon().getName();
		std::cout << "(" << player.getInventory()->getWeapon().getCoinValue() << " coins)" << std::endl;
		std::cout << "[2] " << std::setw(25) << player.getInventory()->getArmor().getName();
		std::cout << "(" << player.getInventory()->getArmor().getCoinValue() << " coins)" << std::endl;
		std::cout << "[3] " << std::setw(25) << player.getInventory()->getPotionDisplayString();
		std::cout << "(" << player.getInventory()->getPotion()->getCoinValue() << " coins)" << std::endl;
		std::cout << "[4] " << std::setw(25) << player.getInventory()->getItemSlot1().getName();
		std::cout << "(" << player.getInventory()->getItemSlot1().getCoinValue() << " coins)" << std::endl;
		std::cout << "[5] " << std::setw(25) << player.getInventory()->getItemSlot2().getName();
		std::cout << "(" << player.getInventory()->getItemSlot2().getCoinValue() << " coins)" << std::endl;
		std::cout << "[6] " << std::setw(25) << player.getInventory()->getItemSlot3().getName();
		std::cout << "(" << player.getInventory()->getItemSlot3().getCoinValue() << " coins)" << std::endl;
		std::cout << "[7] Exit" << std::endl << std::endl;
		std::cout << "Choice: ";
		std::cin >> playerChoice;
		//erroneous choice message
		if ((playerChoice < 1) || (playerChoice > 7)) {
			system("CLS");
			std::cout << "This is not an option." << std::endl << std::endl;
			system("PAUSE");
			//reprint inventory drop options
			display();
		}
	}
	if (playerChoice != 7) {
		//check drop choie to see if the slot is empty
		playerChoice = checkDropChoice(player, playerChoice);
		//dropItem if choice is valid
		if (playerChoice > 0) {
			dropItem(player, playerChoice);
		}
	}
*/

/*
//branch to check player choices and determine outcome
	//if player chooses to drop their weapon
	if (playerChoice == 1) {
		//if the slot is empty
		if (player.getInventory()->getWeapon().getName() == "empty") {
			system("CLS");
			player.getInventory()->display();
			std::cout << "This slot is empty!" << std::endl << std::endl;
			std::cout << "================================================================" << std::endl << std::endl;
			system("PAUSE");
			return 0;
		}
		//if the slot is not empty
		else {
			system("CLS");
			std::cout << "The item has been removed from your inventory." << std::endl << std::endl;
			system("PAUSE");
			//returns player choice
			return playerChoice;
		}
	}
	//if player chooses to drop their armor
	else if (playerChoice == 2) {
		//if the slot is empty
		if (player.getInventory()->getArmor().getName() == "empty") {
			system("CLS");
			player.getInventory()->display();
			std::cout << "This slot is empty!" << std::endl << std::endl;
			std::cout << "================================================================" << std::endl << std::endl;
			system("PAUSE");
			return 0;
		}
		//if the slot is not empty
		else {
			system("CLS");
			std::cout << "The item has been removed from your inventory." << std::endl << std::endl;
			system("PAUSE");
			//returns player choice
			return playerChoice;
		}
	}
	//if player chooses to drop their potion(s)
	else if (playerChoice == 3) {
		//if the slot is empty
		//!FIXME: INSERT HOW MANY POTIONS YOU WANNA SELL? MENU!!!!!
		if (player.getInventory()->getPotion()->getName() == "empty") {
			system("CLS");
			player.getInventory()->display();
			std::cout << "This slot is empty!" << std::endl << std::endl;
			std::cout << "================================================================" << std::endl << std::endl;
			system("PAUSE");
			return 0;
		}
		//if the slot is not empty
		else {
			system("CLS");
			std::cout << "The item has been removed from your inventory." << std::endl << std::endl;
			system("PAUSE");
			//returns player choice
			return playerChoice;
		}
	}
	//if player chooses to drop item 1
	else if (playerChoice == 4) {
		//if the slot is empty
		if (player.getInventory()->getItemSlot1().getName() == "empty") {
			system("CLS");
			player.getInventory()->display();
			std::cout << "This slot is empty!" << std::endl << std::endl;
			std::cout << "================================================================" << std::endl << std::endl;
			system("PAUSE");
			return 0;
		}
		//if the slot is not empty
		else {
			system("CLS");
			std::cout << "The item has been removed from your inventory." << std::endl << std::endl;
			system("PAUSE");
			//returns player choice
			return playerChoice;
		}
	}
	//if player chooses to drop item 2
	else if (playerChoice == 5) {
		//if the slot is empty
		if (player.getInventory()->getItemSlot2().getName() == "empty") {
			system("CLS");
			player.getInventory()->display();
			std::cout << "This slot is empty!" << std::endl << std::endl;
			std::cout << "================================================================" << std::endl << std::endl;
			system("PAUSE");
			return 0;
		}
		//if the slot is not empty
		else {
			system("CLS");
			std::cout << "The item has been removed from your inventory." << std::endl << std::endl;
			system("PAUSE");
			//returns player choice
			return playerChoice;
		}
	}
	//if player chooses to drop item 3
	else if (playerChoice == 6) {
		//if the slot is empty
		if (player.getInventory()->getItemSlot3().getName() == "empty") {
			system("CLS");
			player.getInventory()->display();
			std::cout << "This slot is empty!" << std::endl << std::endl;
			std::cout << "================================================================" << std::endl << std::endl;
			system("PAUSE");
			return 0;
		}
		//if the slot is not empty
		else {
			system("CLS");
			std::cout << "The item has been removed from your inventory." << std::endl << std::endl;
			system("PAUSE");
			//returns player choice
			return playerChoice;
		}
	}
*/

/*
weapon noWeapon;
	armor noArmor;
	potion noPotion;
	item noItem;

	//player chooses to drop their weapon
	if (playerChoice == 1) {
		//set player inventory weapon to noWeapon
		player.getInventory()->setWeapon(noWeapon);
	}
	//player chooses to drop their armor
	else if (playerChoice == 2) {
		//set player inventory weapon to noWeapon
		player.getInventory()->setArmor(noArmor);
	}
	//player chooses to drop their potion
	else if (playerChoice == 3) {
		//set player inventory weapon to noWeapon
		player.getInventory()->setPotion(noPotion);
	}
	//player chooses to drop item 1
	else if (playerChoice == 4) {
		//if item 1 is a quest item
		if (player.getInventory()->getItemSlot1().getIsQuestItem() == true) {
			system("CLS");
			std::cout << "You can't drop that! It is a quest item." << std::endl << std::endl;
			system("PAUSE");
		}
		//if item 1 is not a quest item
		else if (player.getInventory()->getItemSlot1().getIsQuestItem() == false) {
			//set player inventory weapon to noWeapon
			player.getInventory()->setItem1(noItem);
		}
	}
	//player chooses to drop item 2
	else if (playerChoice == 5) {
		//if item 2 is a quest item
		if (player.getInventory()->getItemSlot2().getIsQuestItem() == true) {
			system("CLS");
			std::cout << "You can't drop that! It is a quest item." << std::endl << std::endl;
			system("PAUSE");
		}
		//if item 2 is not a quest item
		else if (player.getInventory()->getItemSlot2().getIsQuestItem() == false) {
			//set player inventory weapon to noWeapon
			player.getInventory()->setItem2(noItem);
		}
	}
	//player chooses to drop item 3
	else if (playerChoice == 6) {
		//if item 3 is a quest item
		if (player.getInventory()->getItemSlot3().getIsQuestItem() == true) {
			system("CLS");
			std::cout << "You can't drop that! It is a quest item." << std::endl << std::endl;
			system("PAUSE");
		}
		//if item 3 is not a quest item
		else if (player.getInventory()->getItemSlot3().getIsQuestItem() == false) {
			//set player inventory weapon to noWeapon
			player.getInventory()->setItem3(noItem);
		}
	}
*/