#pragma once
#ifndef DIALOGUETREE_H
#define DIALOGUETREE_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

class dialogueTree {
private:
	std::vector<std::vector<std::string>> dialogueVector;

public:
	//constructors
	dialogueTree();

	dialogueTree(std::vector<std::vector<std::string>> dialogueVector);

	//getters
	std::vector<std::vector<std::string>> getDialogueVector();

	//setters
	void setDialogueVector(std::vector<std::vector<std::string>> dialogueVector);

	//methods
	void printDialogue();

};

#endif
