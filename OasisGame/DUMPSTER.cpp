#include <iostream>


//menu options
void returnToOverworld() {
    std::cout << "Returned to Overworld." << std::endl;
}
void enterBattle() {
    std::cout << "Entered Battle." << std::endl;
}
void manageInventory() {
    std::cout << "Inventory Opened." << std::endl;
}
void enterShop() {
    std::cout << "Entered Shop." << std::endl;
}
void chat() {
    std::cout << "You chat with an NPC." << std::endl;
}
void quitGame() {
    std::cout << "Game Quit." << std::endl;
}

//main menu
void menu() {
    int userInput;
    std::cout << "1. Return to Game" << std::endl;
    std::cout << "2. Enter Battle" << std::endl;
    std::cout << "3. Manage Inventory" << std::endl;
    std::cout << "4. Enter Shop" << std::endl;
    std::cout << "5. Talk to Someone" << std::endl;
    std::cout << "6. Quit Game" << std::endl;

    std::cin >> userInput;
    switch (userInput) {
    case 1:
        returnToOverworld();
        break;
    case 2:
        enterBattle();
        break;
    case 3:
        manageInventory();
        break;
    case 4:
        enterShop();
        break;
    case 5:
        chat();
        break;
    case 6:
        quitGame();
        break;
    default:
        std::cout << "Not an option." << std::endl;
    }
}

//WORK AREA FOR BATTLE FUNCTION






