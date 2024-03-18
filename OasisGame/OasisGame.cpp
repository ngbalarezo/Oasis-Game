// OasisGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <vector>
#include <string>
#include "menu.h"
#include "characters.h"
#include "inventory.h"
#include "items.h"

int main() {
    //game begins, main menu prints 
    /*
    mainMenu test;
    test.print();
    */

    //MAIN GAME: start menu, prompts user to choose base settings

    //MAIN GAME: game generates all world items, npcs, and features
    
    //TEST: generate empty inventory
    playerInventory playerInventory;

    //TEST: prompt user for player name, generate empty player
    std::string playerName; 
    playerName = "Khevsureti";
    /*std::cout << "Insert Player Name: ";
    std::cin >> playerName;*/
    player player(playerName, playerInventory);
    system("CLS");

    //MAIN GAME: game generates player and prompts for name and information

    //TEST: battle feature
    enemy zombie;
    zombie.battle(player);

    return 0;
}

/*
* !FIXME LIST:
* Add in buff/nerf in battle function according to armor and weapons
* Start menu + music
* Change the name of focus stat of weapon class to better capture the essence of the stat (difficulty requries more focus, precision?)
* Organize header include tags
*/