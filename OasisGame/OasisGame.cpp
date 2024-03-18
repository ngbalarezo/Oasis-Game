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
    //MAIN GAME: game generates all world items, npcs, and features

    //MAIN GAME: start menu, prompts user to choose base settings

    //MAIN GAME: game generates player and prompts for name and information

    /*TESTING BELOW*/
    
    //TEST: Initial require game settings, generates empty inventory, prompts user for player name, generates empty player
    playerInventory playerInventory;
    std::string playerName; 
    playerName = "Khevsureti";
    //std::cout << "Insert Player Name: ";
    //std::cin >> playerName;
    player player(playerName, playerInventory);
    system("CLS");

    //TEST: Main menu to test features, generates mainMenu object and prints it, takes userChoice and runs game feature accordingly
    int userChoice;
    mainMenu test;
    std::cout << "TEST MENU: " << std::endl;
    test.print();
    std::cin >> userChoice;
    if (userChoice == 1) { //NULL
        system("CLS");
        std::cout << "null" << std::endl;
    }
    else if (userChoice == 2) { //BATTLE TEST
        system("CLS");
        enemy zombie;
        zombie.battle(player);
    }
    else if (userChoice == 3){ //STANDARD INVENTORY DISPLAY
        system("CLS");
        player.getInventory().display();
        system("PAUSE");
    }
    else if (userChoice == 4) { //NULL
        system("CLS");
        std::cout << "null" << std::endl;
    }
    else if (userChoice == 5) { //NULL
        system("CLS");
        std::cout << "null" << std::endl;
    }
    else if (userChoice == 6) { //NULL
        system("CLS");
        std::cout << "null" << std::endl;
    }
    else { //NULL
        system("CLS");
        std::cout << "null" << std::endl;
    }

    return 0;
}

/*
* !FIXME LIST:
* Add in buff/nerf in battle function according to armor and weapons
* Music
* Fix documentation, make the game easier to understand with comments
* Change the name of focus stat of weapon class to better capture the essence of the stat (difficulty requries more focus, precision?)
* Organize header include tags
* Quest item cannot drop item, quest item feature
* Clean up system clears and pauses ("CLS") and ("PAUSE")
* 
*/