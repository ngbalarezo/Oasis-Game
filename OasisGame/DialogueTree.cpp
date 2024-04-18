#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "menu.h"
#include "map.h"
#include "locations.h"
#include "buildings.h"
#include "characters.h"
#include "inventory.h"
#include "items.h"

//DIALOGUE TREE DEFINITIONS
//constructors
dialogueTree::dialogueTree() {  }

dialogueTree::dialogueTree(std::vector<std::vector<std::string>> dialogueVector) {
	this->dialogueVector = dialogueVector;
}

//getters
std::vector<std::vector<std::string>> dialogueTree::getDialogueVector() { return dialogueVector; }

//setters
void dialogueTree::setDialogueVector(std::vector<std::vector<std::string>> dialogueVector) { this->dialogueVector = dialogueVector; }

//methods
void dialogueTree::printDialogue() {
	//declare variables
	int userChoice;
	int index = 0;
	//for loop iterates number of levels for possible responses
	for (int i = 0; i < 4; i++) {
		//print dialogue
		std::cout << dialogueVector[index][0] << std::endl;
		std::cout << "[1]" << dialogueVector[index][1] << std::endl;
		std::cout << "[2]" << dialogueVector[index][2] << std::endl;
		std::cout << "[3] Exit" << std::endl;
		//prompt user for choice
		std::cout << "Choice: ";
		std::cin >> userChoice;
		//if user chooses option 1
		if (userChoice == 1) {
			index = (2 * index) + 1;
		}
		//if user chooses option 2
		else if (userChoice == 2) {
			index = (2 * index) + 2;
		}
		//if user chooses to exit dialogue
		else if (userChoice == 3) {
			//!FIXME: print randomized goodbye message
			std::cout << "That's a funny way to treat a stranger. Goodbye." << std::endl;
		}
		//if user chooses an invalid option
		else {
			//print error message
			std::cout << "This is not an option!";
			//for loop is set back one loop if the user does not input a valid number
			i--;
		}
	}
	
}


