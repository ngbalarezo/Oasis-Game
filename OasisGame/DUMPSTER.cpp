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

//BUILDINGS FILES
    //class shop {
    //private:
    //    //each shop will sell 3 weapons, 1 armor, and 1 potion, 
    //    weapon weaponSlot1;
    //    weapon weaponSlot2;
    //    weapon weaponSlot3;
    //    armor armorSlot;
    //    potion potionSlot;
    //    //!FIXME: add in scroll/book item + functionality

    //public:
    //    //constructors
    //    shop();

    //    shop(weapon weaponSlot1, weapon weaponSlot2, weapon weaponSlot3, armor armorSlot, potion potionSlot);

    //    //getters

    //    //setters

    //    //methods

    //};

//shop::shop() {
//	//create null item objects
//	weapon noWeapon;
//	armor noArmor;
//	potion noPotion;
//	//set defaults to null objects
//	weaponSlot1 = noWeapon;
//	weaponSlot2 = noWeapon;
//	weaponSlot3 = noWeapon;
//	armorSlot = noArmor;
//	potionSlot = noPotion;
//}
//
//shop::shop(weapon weaponSlot1, weapon weaponSlot2, weapon weaponSlot3, armor armorSlot, potion potionSlot) {
//	this->weaponSlot1 = weaponSlot1;
//	this->weaponSlot2 = weaponSlot2;
//	this->weaponSlot3 = weaponSlot3;
//	this->armorSlot = armorSlot;
//	this->potionSlot = potionSlot;
//}


