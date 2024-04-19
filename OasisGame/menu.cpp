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

//START MENU DEFINITIONS
int startMenu::print() {
    int userChoice;
    PlaySound(MAKEINTRESOURCE(START_MENU_MUSIC), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);
    std::cout << "[1] Start Game" << std::endl;
    std::cout << "[2] Info" << std::endl;
    std::cout << "[3] Dev Testing" << std::endl;
    std::cout << "[4] Exit" << std::endl;
    std::cout << "Choice: ";
    std:: cin >> userChoice;
    return userChoice;
}

std::string startMenu::promptPlayerName() {
    std::string playerName;
    //clear screen
    system("CLS");
    //prompt user for player name and return as string
    std::cout << "Input player name: " << std::endl;
    std::cin >> playerName;
    return playerName;
}

//TEST MENU DEFINITIONS
void testMenu::print() {//!FIXME: change main menu options
    std::cout << "1. Return to Game" << std::endl;
    std::cout << "2. Enter Battle" << std::endl;
    std::cout << "3. Manage Inventory" << std::endl;
    std::cout << "4. Enter Shop" << std::endl;
    std::cout << "5. Talk to Someone" << std::endl;
    std::cout << "6. Quit Game" << std::endl;
    //!FIXME: insert feature to choose option using cin and functions referencing other .h files
}

void testMenu::testLoop(int initialChoice, player& player) {
    PlaySound(MAKEINTRESOURCE(MISC_MUSIC_1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);
    //clear console
    system("CLS");
    //generate misc. variables
    int sentinel = 0;
    bool played;
    int userChoice = initialChoice;

    //generate test items
    enemy testEnemy("Test Zombie", 100, 40, 20, false);
    weapon woodenSword("Wooden Sword", 150, 5, false, 10, 1);
    weapon woodenAxe("Wooden Axe", 200, 5, false, 15, 1);
    armor chainmailArmor("Chainmail", 300, 25, false, 15);
    potion smallHealPotion("Small Heal Potion", 50, 0, 0, 100);
    item ruby("Ruby", 300, 0, false);
    shop testShop(woodenSword, woodenAxe, chainmailArmor, smallHealPotion, ruby);

    //loops test start menu
    while (sentinel != 1) {
        std::cout << "TEST MENU: " << std::endl;
        print();
        std::cin >> userChoice;
        if (userChoice == 1) { //NULL
            system("CLS");
            std::cout << "null" << std::endl;
        }
        else if (userChoice == 2) { //BATTLE TEST
            system("CLS");
            played = PlaySound(MAKEINTRESOURCE(BATTLE_MUSIC_1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);
            //played = PlaySound(NULL, GetModuleHandle(NULL), NULL); //STOPS ASYNCHRONOUS MUSIC
            testEnemy.battle(player);
        }
        else if (userChoice == 3) { //STANDARD INVENTORY DISPLAY
            system("CLS");
            player.accessInventory();
        }
        else if (userChoice == 4) { //NULL
            system("CLS");
            //played = PlaySound(MAKEINTRESOURCE(MISC_MUSIC_1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);
            testShop.enterShop(player);
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
}

//PAUSE MENU DEFINITIONS

