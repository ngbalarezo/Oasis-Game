#include <iostream>
#include "menu.h"
#include "map.h"
#include "locations.h"
#include "buildings.h"
#include "characters.h"
#include "inventory.h"
#include "items.h"
#include "DialogueTree.h"

/* EMPTY SLOT
system("CLS");
    int playerChoice = 0;
    while ((playerChoice < 1) || (playerChoice > 4)) {
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
            player.getInventory()->inventoryChoiceMenu();
            //reset playerChoice to continue loop unless player chooses to exit
            playerChoice = -1;
        }
        //if player chooses to check their stats
        else if (playerChoice == 2) {
            player.printStats();
            //reset playerChoice to continue loop unless player chooses to exit
            playerChoice = -1;
        }
        else if (playerChoice == 3) {
            currentMap.display();
            //reset playerChoice to continue loop unless player chooses to exit
            playerChoice = -1;
        }
        if ((playerChoice < 1) || (playerChoice > 4)) {
            system("CLS");
            std::cout << "This is not an option!" << std::endl << std::endl;
            system("PAUSE");
            system("CLS");
        }
    }
*/

/* EMPTY SLOT
    system("CLS");
    int sentinel = 0;
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
            system("CLS");
            player.getInventory()->inventoryChoiceMenu();
            return 0;
        }
        else if (sentinel == 2) {
            system("CLS");
            player.printStats();
            system("PAUSE");
            system("CLS");
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
*/

/* EMPTY SLOT

*/