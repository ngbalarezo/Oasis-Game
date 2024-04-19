// OasisGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <windows.h>
#include "menu.h"
#include "map.h"
#include "locations.h"
#include "buildings.h"
#include "characters.h"
#include "inventory.h"
#include "items.h"
#include "DialogueTree.h"
#include "resource.h"

//#pragma comment(lib, "winmm.lib")

int main() {
    //MAIN GAME: GENERATE ITEMS
    //items
    item noItem;
    item ruby("Ruby", 300, 0, false);
    item ITEMS[10] = {};
    //weapons
    weapon noWeapon;
    weapon woodenSword("Wooden Sword", 150, 5, false, 10, 1);
    weapon woodenAxe("Wooden Axe", 200, 5, false, 15, 1);
    weapon ironSword("Iron Sword", 500, 8, false, 22, 1);
    weapon ironAxe("Iron Axe", 550, 11, false, 25, 1);
    weapon codedSword("Coded Sword", 1, 10, false, 300, 0);
    weapon WEAPONS[10] = {};
    //armor
    armor noArmor;
    armor chainmailArmor("Chainmail", 300, 25, false, 15);
    armor ironArmor("Iron Armor", 800, 35, false, 20);
    armor RiotGear("Riot Gear", 9000, 50, false, 400);
    armor ARMOR[10] = {};
    //potions
    potion noPotion;
    potion smallHealPotion("Small Heal Potion", 50, 0, 0, 100);
    potion POTION[10] = {};

    //MAIN GAME: GENERATE DIALOGUES

    //MAIN GAME: GENERATE CHARACTERS
    //npcs
    npc noNpc;
    npc shopKeeper("Shop Keeper Milo");
    npc apprenticeWizard("Apprentice Wizard");
    npc NPCS[12] = {};
    //enemies
    enemy bandit("Bandit", 100, 40, 20, false);
    enemy ENEMIES[15] = {};
    //bosses
    enemy BOSSES[7] = {};

    //MAIN GAME: GENERATE BUILDINGS
    //shops
    shop market("Local Market", noNpc, woodenSword, woodenAxe, chainmailArmor, smallHealPotion, ruby);
    shop smithy("Local Smithy", noNpc, noWeapon, noWeapon, noArmor, noPotion, noItem);
    shop farm("Farm", noNpc, noWeapon, noWeapon, noArmor, noPotion, noItem);
    shop armory("Town Armory", noNpc, noWeapon, noWeapon, noArmor, noPotion, noItem);
    shop apothecary("Apprentice Wizard's Apothecary", apprenticeWizard, noWeapon, noWeapon, noArmor, noPotion, noItem);
    shop SHOPS[15] = {};

    //Churches
    Church CHURCHES[15] = {};

    //lounges
    lounge LOUNGES[10] = {};

    //MAIN GAME: GENERATE LOCATIONS
    //wilderness
    wilderness forest;
    wilderness desert;
    wilderness valley;
    wilderness iceland;
    wilderness jungle;
    wilderness WILDERNESS[5] = {forest, desert, valley, iceland, jungle};

    //villages
    village village1;
    village village2;
    village village3;
    village village4;
    village village5;
    village VILLAGES[5] = {village1, village2, village3, village4, village5};

    //MAIN GAME: GENERATE MAP
    map gameMap(5);
    gameMap.generateMap(WILDERNESS, VILLAGES);


    //MAIN GAME: GENERATE MENUS
    startMenu startScreen;

    //MAIN GAME: GENERATE MISC. VARIABLES
    int sentinel = 0;

    //MAIN GAME: START MENU LOOP
    //start menu music
    PlaySound(MAKEINTRESOURCE(START_MENU_MUSIC), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);
    //loop to prevent erroneous choice
    while (sentinel != 1) {
        //print start screen
        int userChoice = startScreen.print();

        //MAIN GAME: exits start menu loop and begins game
        if (userChoice == 1) { 
            sentinel = 1; 
        }
        //INFO SECTION: tbd
        else if (userChoice == 2) { 
            system("CLS");
            std::cout << "Info: null" << std::endl << std::endl;
            system("PAUSE");
            
        }
        //DEV TESTING: Main menu to test features, generates mainMenu object and prints it, takes userChoice and runs game feature accordingly
        //!FIXME: LEFT OFF ON COORDINATE SYSTEM IN MAP FUNCTION
        else if (userChoice == 3) {
            //generate test menu and test player
            testMenu test;
            playerInventory testInventory(noWeapon, noArmor, noPotion, 0, noItem, noItem, noItem, 100);
            player testPlayer("Dev", testInventory);
            test.testLoop(userChoice, testPlayer, gameMap);
        }
        //EXIT GAME FROM START MENU: 
        else if (userChoice == 4) {
            system("CLS");
            std::cout << "GOODBYE." << std::endl;
            sentinel = 1;
        }
        //ERRONEOUS CHOICE:
        else {
            system("CLS");
            std::cout << "This is not an option." << std::endl << std::endl;
            system("PAUSE");
        }
    }

    //MAIN GAME: GAME BEGINS, PROMPT USER FOR PLAYER NAME AND BASE SETTINGS
    std::string playerName = startScreen.promptPlayerName();

    //MAIN GAME: GENERATE PLAYER AND INVENTORY
    playerInventory playerInventory(noWeapon, noArmor, noPotion, 0, noItem, noItem, noItem, 100);
    player player(playerName, playerInventory);

    //MAIN GAME: INITIATE INTRO SEQUENCE AND MONOLOGUE

    //MAIN GAME: MAIN GAME LOOP
    
    return 0;
}

/*
* !FIXME LIST:
* -------------------------------------------------------------------------------------------------------------------------------------------
* POTIONS FUNCTIONALITY/TRANSFER POTIONCOUNT TO POTION CLASS RATHER THAN INVENTORY
* ASK TYLER IF IT WOULD BE BETTER TO MAKE EVERYTHING PASSED BY REFERENCE AND POINTERS INSTEAD OF EQUALITIES
* CHECK DEFAULT CONSTRUCTORS, MAY NOT HAVE TO INITALIZE WEAPONS IN INVENTORY... THEY DEFUALT TO EMPTY!
* GRAPHICS DISPLAY FOR ENTERING A NEW VILLAGE OR WILDERNESS
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