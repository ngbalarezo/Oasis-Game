#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include <string>
#include <random>
#include <windows.h>
#include <stdlib.h>
#include "menu.h"
#include "map.h"
#include "locations.h"
#include "buildings.h"
#include "characters.h"
#include "inventory.h"
#include "items.h"
#include "resource.h"

//START MENU DEFINITIONS
int startMenu::print() {
    int userChoice;
    std::cout << "OASIS" << std::endl << std::endl;
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
    std::cout << "Input player name: ";
    std::cin >> playerName;
    return playerName;
}

//PLAYER MENU DEFINITIONS
void playerMenu::print(player& player, map& currentMap) {
    int playerChoice = 0;
    int sentinel = 0;
    int potionUse = 0;
    while (sentinel != 1) {
        system("CLS");
        std::cout << "==============================" << std::endl;
        std::cout << "Player Menu:" << std::endl << std::endl;
        std::cout << "[1] Inventory" << std::endl;
        std::cout << "[2] Player Stats" << std::endl;
        std::cout << "[3] Check Map" << std::endl;
        std::cout << "[4] Exit" << std::endl;
        std::cout << "==============================" << std::endl << std::endl;
        std::cout << "Choice: ";
        std::cin >> playerChoice;
        if (playerChoice == 1) {
            while (potionUse != 2) {
                system("CLS");
                //sets potion use to 1 or 2 depending on if the user chooses to use a potion or exit the menu respectively
                potionUse = player.getInventory()->inventoryChoiceMenu();
                //if potionUse returns as 1 then user uses a potion
                if (potionUse == 1) {
                    player.usePotion();
                }
                //if potionUse returns as 2 then mini loop breaks;
            }
        }
        //if player chooses to check their stats
        else if (playerChoice == 2) {
            player.printStats();
            //reset playerChoice to continue loop unless player chooses to exit

        }
        //if player chooses to display menu
        else if (playerChoice == 3) {
            currentMap.display();
            //reset playerChoice to continue loop unless player chooses to exit
        }
        //if player chooses to exit
        else if (playerChoice == 4) {
            //set sentinel to 1 to break the loop
            sentinel = 1;
        }
        else {
            system("CLS");
            std::cout << "This is not an option!" << std::endl << std::endl;
            system("PAUSE");
            system("CLS");
        }
    }
}

//MAP PLAYER MENU DEFINITIONS
int mapPlayerMenu::print(player& player) {
    system("CLS");
    int sentinel = 0;
    int potionUse = 0;
    while (sentinel != 4) {
        std::cout << "==============================" << std::endl;
        std::cout << "Player Menu:" << std::endl << std::endl;
        std::cout << "[1] Inventory" << std::endl;
        std::cout << "[2] Player Stats" << std::endl;
        std::cout << "[3] Check Map" << std::endl;
        std::cout << "[4] Exit" << std::endl;
        std::cout << "==============================" << std::endl << std::endl;
        std::cout << "Choice: ";
        std::cin >> sentinel;
        if (sentinel == 1) {
            while (potionUse != 2) {
                system("CLS");
                //sets potion use to 1 or 2 depending on if the user chooses to use a potion or exit the menu respectively
                potionUse = player.getInventory()->inventoryChoiceMenu();
                //if potionUse returns as 1 then user uses a potion
                if (potionUse == 1) {
                    player.usePotion();
                }
                //if potionUse returns as 2 then mini loop breaks;
            }
            return 0;
        }
        else if (sentinel == 2) {
            system("CLS");
            player.printStats();
            return 0;
        }
        else if (sentinel == 3) {
            return 1;
        }
        else if (sentinel == 4) {
            system("CLS");
            return 2;
        }
        else {
            system("CLS");
            std::cout << "This is not an option!" << std::endl << std::endl;
            system("PAUSE");
            system("CLS");
        }
    }
}

//TEST MENU DEFINITIONS
void testMenu::print() {//!FIXME: change main menu options
    system("CLS");
    std::cout << "1. Return to Game" << std::endl;
    std::cout << "2. Enter Battle" << std::endl;
    std::cout << "3. Manage Inventory" << std::endl;
    std::cout << "4. Enter Shop" << std::endl;
    std::cout << "5. Talk to Someone" << std::endl;
    std::cout << "6. Move location" << std::endl;
    std::cout << "7. Print map" << std::endl;
    std::cout << "9. Exit Dev Testing" << std::endl;
    //!FIXME: insert feature to choose option using cin and functions referencing other .h files
}

void testMenu::testLoop(int initialChoice, player& player, map& testMap, playerMenu& testMenu, std::vector<std::vector<std::string>>& testShadowyManDialogue) {
    npc testShadowyMan("Shadowy man", testShadowyManDialogue);
    PlaySound(MAKEINTRESOURCE(MISC_MUSIC_1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);
    //clear console
    system("CLS");
    //generate misc. variables
    int sentinel = 0;
    bool played;
    int userChoice = initialChoice;
    int mapInt = 0;

    //generate test items
    npc testNpc("Test Shop Keeper");
    enemy testEnemy("Test Zombie", 100, 40, 20, false);
    weapon woodenSword("Wooden Sword", 150, 5, false, 2000, 1);
    weapon woodenAxe("Wooden Axe", 200, 5, false, 15, 1);
    armor chainmailArmor("Chainmail", 300, 25, false, 15);
    potion smallHealPotion("Small Heal Potion", 5, 50, 0, 0, 100);
    item ruby("Ruby", 300, 0, false);
    shop testShop("Test Shop", "test shop", testNpc, woodenSword, woodenAxe, chainmailArmor, smallHealPotion, ruby);

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
            testEnemy.battle(player);
        }
        else if (userChoice == 3) { //STANDARD INVENTORY DISPLAY
            testMenu.print(player, testMap);
        }
        else if (userChoice == 4) { //NULL
            system("CLS");
            //played = PlaySound(MAKEINTRESOURCE(MISC_MUSIC_1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);
            testShop.enterShop(player);
        }
        else if (userChoice == 5) { //NULL
            system("CLS");
            testShadowyMan.initiateDialogue();
            std::cout << "null" << std::endl;
        }
        else if (userChoice == 6) {
            testMap.moveLocation(player);
        }
        else if (userChoice == 7) { //PRINT MAP
            testMap.display();
        }
        else if (userChoice == 9) {
            //system("CLS");
            sentinel = 1;
        }
        else { //NULL
            system("CLS");
            std::cout << "null" << std::endl;
        }
    }
}



