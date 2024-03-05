// OasisGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <vector>
#include <string>
#include "menu.h"
#include "characters.h"

int main()
{
    //game begins, main menu prints 
    /*
    mainMenu test;
    test.print();
    */

    
    //game generates all world items, npcs, and features

    //game generates player and prompts for name and information

    //test battle feature
    std::string playerName = "Khevsureti";
    player player(playerName);
    enemy zombie;
    zombie.battle(player);

    return 0;
}