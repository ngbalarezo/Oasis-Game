// OasisGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <windows.h>
#include "resource.h"
#include "menu.h"
#include "characters.h"
#include "inventory.h"
#include "items.h"
#include "locations.h"
#include "buildings.h"
#include "DialogueTree.h"

//#pragma comment(lib, "winmm.lib")
void accessInventory(player &player);

int main() {
    //MAIN GAME: game generates all world items, npcs, and features

    //MAIN GAME: start menu, prompts user to choose base settings

    //MAIN GAME: game generates player and prompts for name and information

    /*TESTING BELOW*/
    bool played;
    int sentinel = 0;

    //TEST: generate items
    weapon noWeapon;
    armor noArmor;
    potion noPotion;
    item noItem;

    // BUILD WEAPONS
    
    weapon codedSword("Coded Sword", 1, 10, false, 300, 0);
    weapon woodenSword("Wooden Sword", 150, 5, false, 10, 1);
    weapon woodenAxe("Wooden Axe", 200, 5, false, 15, 1);

    //BUILD ARMOR
    armor chainmailArmor("Chainmail", 300, 25, false, 15);

    //BUILD ENEMYS
    enemy bandit("Bandit", 100, 40, 20, false);

    //BUILD POTIONS
    potion smallHealPotion("Small Heal Potion", 50, 0, 0, 100);

    //BUILD ITEMS
    item ruby("Ruby", 300, 0, false);

    //TEST: generate shop
    shop market(woodenSword, woodenAxe, chainmailArmor, smallHealPotion, ruby);

    //TEST: Initial require game settings, generates empty inventory, prompts user for player name, generates empty player
    playerInventory playerInventory(codedSword, noArmor, noPotion, 0, noItem, noItem, noItem, 500);
    std::string playerName; 
    playerName = "Khevsureti";
    //std::cout << "Insert Player Name: ";
    //std::cin >> playerName;
    player player(playerName, playerInventory);
    system("CLS");

    //TEST: Main menu to test features, generates mainMenu object and prints it, takes userChoice and runs game feature accordingly
    int userChoice;
    mainMenu test;
    //loops test start menu
    while (sentinel != 1) {
        std::cout << "TEST MENU: " << std::endl;
        test.print();
        played = PlaySound(MAKEINTRESOURCE(START_MENU_MUSIC), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);
        std::cin >> userChoice;
        if (userChoice == 1) { //NULL
            system("CLS");
            std::cout << "null" << std::endl;
        }
        else if (userChoice == 2) { //BATTLE TEST
            system("CLS");
            played = PlaySound(MAKEINTRESOURCE(VILLAGE_MUSIC_1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);
            //played = PlaySound(NULL, GetModuleHandle(NULL), NULL); //STOPS ASYNCHRONOUS MUSIC
            bandit.battle(player);
        }
        else if (userChoice == 3) { //STANDARD INVENTORY DISPLAY
            system("CLS");
            accessInventory(player);
        }
        else if (userChoice == 4) { //NULL
            system("CLS");
            //played = PlaySound(MAKEINTRESOURCE(MISC_MUSIC_1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);
            market.enterShop(player);
        }
        else if (userChoice == 5) { //NULL
            system("CLS");
            //npc shopKeeper;
            //shopKeeper.getDialogueTree()->initiateDialogue();
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
    }
    
    return 0;
}

//!FIXME: move this to player.h and leave the name as is
void accessInventory(player &player) {
    int sentinel = 0;
    while (sentinel != 3) {
        std::cout << "[1] Inventory" << std::endl;
        std::cout << "[2] Player Stats" << std::endl;
        std::cout << "[3] Exit" << std::endl;
        std::cout << "Choice: ";
        std::cin >> sentinel;
        if (sentinel == 1) {
            system("CLS");
            player.getInventory()->display();
            system("PAUSE");
            system("CLS");
        }
        else if (sentinel == 2) {
            system("CLS");
            player.printStats();
            system("PAUSE");
            system("CLS");
        }
        else if (sentinel == 3) {
            system("CLS");
        }
        else {
            system("CLS");
            std::cout << "This is not an option!" << std::endl << std::endl;
            system("PAUSE");
            system("CLS");
        }
    }
}

/*
* !FIXME LIST:
* -------------------------------------------------------------------------------------------------------------------------------------------
* ASK TYLER IF IT WOULD BE BETTER TO MAKE EVERYTHING PASSED BY REFERENCE AND POINTERS INSTEAD OF EQUALITIES
* CHECK DEFAULT CONSTRUCTORS, MAY NOT HAVE TO INITALIZE WEAPONS IN INVENTORY... THEY DEFUALT TO EMPTY!
* Fix documentation, make the game easier to understand with comments
* Make the battle screen look nicer!!!
* Change the name of focus stat of weapon class to better capture the essence of the stat (difficulty requries more focus, precision?)
* Organize header include tags
* Quest item cannot drop item, quest item feature
* Clean up system clears and pauses ("CLS") and ("PAUSE")
* NPC = dialogue tree, canSell bool, inventory or 1 item to sell??
* Add scrolls
* Go through and check for items that could be passed by reference
* Add in pause/fade in for area music
* Edit every audio clip and fade them in for quality effect
* -------------------------------------------------------------------------------------------------------------------------------------------
*/