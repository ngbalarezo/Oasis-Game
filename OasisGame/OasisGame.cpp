// OasisGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <windows.h>
#include <stdlib.h>
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
    weapon strongTestWeapon("STRONG TEST WEAPON", 1, 5, false, 20000, 1);
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
    armor ARMOR_REALM1[10] = {};
    //potions
    potion noPotion;
    potion smallHealPotion("Small Heal Potion", 50, 0, 0, 100);
    potion POTION[10] = {};

    //MAIN GAME: GENERATE DIALOGUES
    /*std::vector<std::vector<std::string>> MOCKshopKeeperDialogue1 = {
        //node 0
        {"GREETINGS", "Hello", "Don't talk to me"},
        //node 1
        {"WHAT CAN I DO FOR YA...", "Tell me sir, what is the town like!", "Please share your life story with me!"},
        //node 2
        {"WHY SIR? I thought you seemed nice!", "Well, IM NOT", "Pardon my rudeness, I have schizophrenia..."},
        //node3
        {}

    };
    */

    //MAIN GAME: GENERATE DIALOGUES
    std::vector<std::vector<std::string>> shadowyManDialogue = {
        //node 0
        {"Shadowy Man: Hello young lad, what brings you here?", "Hi there sir. Where am I?", "Hey there, sir. Do you have any wisdom that can help me ? "},
        //node 1
        {"Ah, you find yourself in a realm where the echoes of the past linger in every shadow.", "How do I uncover these echoes of the past?", "Are these echoes tied to a specific event or legend?"},
        //node 2
        {"To find your way in this world, you must listen to the echoes of the past, which linger in every shadow.", "How can I reveal the echoes from the past ?","Do these echoes have a connection to a particular event or legend?"},
        //node3
        {"To uncover the echos of past, seek the forgotten places. They hold the keys to ancient truths.","Keys to ancient truths?","Forgotten places?"},
        //node4
        {"Indeed, they are echoes of a long-forgotten tale, a saga of valor and betrayal woven into the very fabric of our history.","Valor and betrayal?","Could you share more details about this tale?"},
        //node5
        {"To uncover the past, seek the forgotten places. They hold the keys to ancient truths.","Keys to ancient truths?","Forgotten places?"},
        //node6
        {"Certainly, they echo a tale lost to time, a narrative of courage and deceit entwined within our historical tapestry.","Valor and betrayal?"," Could you share more details about this tale?"},
        //node7
        {"To unravel the keys of ancient truths, one must tread the paths of knowledge and virtue. I suggest seeking wisdom in the church or delving into the ancient tomes within the library. Only through understanding and purity of heart can the secrets of the past be revealed.","Secrets of the past?","Keys of ancient truths?"},
        //node8
        {"Ah, yes. The forgotten places are not merely physical locations but gateways to worlds beyond our own. The unseen forgotten places can only be unveiled through the exploration of the seen forgotten places. They are intertwined, each holding a piece of the puzzle to unlock the truths you seek.", "Worlds beyond our own?","What is the truth?"},
        //node9
        {"Centuries ago, when this realm was but a fledgling land, there lived a mighty sorcerer known for his mastery of the arcane arts. He sought to protect the realm from dark forces by creating a powerful gemstone infused with the essence of pure magic. This gemstone, was said to possess the ability to unlock paths to realms beyond, a safeguard against the encroaching darkness. However, as the relic's creation neared completion, whispers of greed and ambition crept into the hearts of those entrusted with its safekeeping. One among them, a trusted guardian turned traitor, sought to claim the gem's power for selfish gain.In a desperate act of betrayal, he stole the gem.It's power however, can only be utilized by those of pure heart and intention. Angered by this, the traitor hid the gem so that the passage to the new world would become forever blocked. Only those who prove themselves worthy and pure of heart can uncover it and  harness its power.","How can I prove myself worthy?","What is this next world you speak of?"},
        //node10
        {"Centuries ago, in the early days of this realm's existence, a formidable sorcerer renowned for his mastery of magic dwelled within these lands. Recognizing the looming threat of dark forces, he dedicated himself to crafting a potent gemstone infused with pure magical essence. This gem, hidden deep within the ancient ruins, possessed the extraordinary ability to unlock pathways to distant realms, serving as a bulwark against encroaching darkness. Yet, as the sorcerer's work neared completion, whispers of greed and ambition infiltrated the hearts of those tasked with safeguarding the gem.Among them, a once - loyal guardian succumbed to temptation, betraying his trust and stealing the gem for selfish gain.It's power however, can only be utilized by those of pure heart and intention.In an act of desperation, he concealed the gem within a maze of deceptive illusions, ensuring that only those of genuine virtue and purity could unveil its secrets and wield its formidable power.","How do I navigate the maze of deceptive illusions","What is the truth?"},
        //node11
        {"To unravel the keys of ancient truths, one must tread the paths of knowledge and virtue. I suggest seeking wisdom in the church or delving into the ancient tomes within the library. Only through understanding and purity of heart can the secrets of the past be revealed.","Secrets of the past?","keys of ancient truths?"},
        //node12
        {"Ah, yes. The forgotten places are not merely physical locations but gateways to worlds beyond our own. The unseen forgotten places can only be unveiled through the exploration of the seen forgotten places. They are intertwined, each holding a piece of the puzzle to unlock the truths you seek.","Worlds beyond our own??","What is the truth?"},
        //node13
        {"Many centuries ago, in the early days of this realm's existence, there lived a renowned sorcerer skilled in the arcane arts. His aim was to shield our realm from looming darkness by crafting a potent gem infused with pure magical essence. This gem was rumored to unlock pathways to distant realms, a defense against encroaching threats. However, as the gem's completion drew near, whispers of greed and ambition tainted those entrusted with its safekeeping. A trusted guardian turned traitor, driven by selfish desires, stole the gem. Its power, however, can only be wielded by those with pure intentions. Enraged, the traitor concealed the gem, blocking the passage to the new world. Only those of genuine virtue can uncover it and harness its formidable power.", "How can I prove myself worthy?","What is within this next world?"},
        //node14
        {"Centuries ago, in the early days of this realm's existence, a formidable sorcerer renowned for his mastery of magic dwelled within these lands. Recognizing the looming threat of dark forces, he dedicated himself to crafting a potent gemstone infused with pure magical essence. This gem, hidden deep within the ancient ruins, possessed the extraordinary ability to unlock pathways to distant realms, serving as a bulwark against encroaching darkness. Yet, as the sorcerer's work neared completion, whispers of greed and ambition infiltrated the hearts of those tasked with safeguarding the gem. Among them, a once-loyal guardian succumbed to temptation, betraying his trust and stealing the gem for selfish gain. It's power however, can only be utilized by those of pure heart and intention.In an act of desperation, he concealed the gem within a maze of deceptive illusions, ensuring that only those of genuine virtue and purity could unveil its secrets and wield its formidable power.","How do I navigate the maze of deceptive illusions?","What is the truth?"},
        //node15
        {"I've already spoken more than I should. It's time for you to find your own path and uncover the truths that await you.","",""},
        //node16
        {"I have divulged more than intended. It is time for you to forge your path and discover the rest on your own.","",""},
        //node17
        {"Enough for now, young traveler. Some secrets are best unraveled in due time. You must seek wisdom elsewhere, for I have already shared more than intended.","",""},
        //node18
        {"The truth lies within the library.I have already revealed more than intended. Go on now young adventurer, for there is much more in store for you","",""},
        //node19
        {"I have already revealed more than intended. You will find more wisdom in the library. But more importantly, go to the church. To purify yourself will shelter you from the darkness ahead .Go on weary traveler, for your quest is but a great one.","",""},
        //node20
        {"I have already revealed more than intended. The last thing I shall say is go to the church. You must go there and purify yourself before advancing on this quest. Go on, for your quest is of great importance to not only yourself, but for the safety of the entire universe.","","" },
        //node21
        {"I have already revealed more than intended. You will find more wisdom in the library. But more importantly, go to the church. An unclean spirit will make it impossible for you to withstand the darkness that lies ahead. Go on weary traveler, for your quest is but a great one.","",""},
        //node22
        {"I have already revealed more than intended. The last thing I shall say is go to the church. You must go there and purify yourself before advancing on this quest. Go on, for your quest is of great importance to not only yourself, but for the safety of the entire universe.","",""},
        //node23
        {"I've already spoken more than I should. It's time for you to find your own path and uncover the truths that await you.","",""},
        //node24
        {"I have divulged more than intended. It is time for you to forge your path and discover the rest on your own.","",""},
        //node25
        {"Enough for now, young traveler. Some secrets are best unraveled in due time. You must wisdom elsewhere, for I have already shared more than intended.","",""},
        //node26
        {"The truth lies within the library. I have already revealed more than intended. Go on now young adventurer, for there is much more in store for you","",""},
        //node27
        {"I have already revealed more than intended. You will find more wisdom in the library. But more importantly, go to the church. To purify yourself will shelter you from the darkness ahead .Go on weary traveler, for your quest is but a great one.","",""},
        //node28
        { "I have already revealed more than intended. The last thing I shall say is go to the church. You must go there and purify yourself before advancing on this quest. Go on, for your quest is of great importance to not only yourself, but for the safety of the entire universe.","","" },
        //node29
        {"I have already revealed more than intended. You will find more wisdom in the library. But more importantly, go to the church. To purify yourself will shelter you from the darkness ahead .Go on weary traveler, for your quest is but a great one.","",""},
        //node30
        {"I have already revealed more than intended. The last thing I shall say is go to the church. You must go there and purify yourself before advancing on this quest. Go on, for your quest is of great importance to not only yourself, but for the safety of the entire universe.","",""}
        
    };

    //OLD MAN DIALOGUE
    std::vector<std::vector<std::string>> oldManDialogue = {
        //node0
        {"Ahh, greetings, young traveler. I've been expecting you","Do you even know where I come from?","Who are you?"},
        //node1
        {"My dear traveler, I have known you for many years, though our paths have not crossed until now. You are from a different world. Though we come from two different worlds, we are but threads woven by the same divine hand, guided by the same celestial compass. I have have been watching over you.", "Where are you from?", "How do you know me?"},
        //node2
        {"I am but a humble observer of journeys, a keeper of tales. You, young traveler, are a part of a story yet untold","Why am I here?", "How do you know me?"},
        //node3
        {"We both existence within a singular realm, yet we traverse divergent paths. My world is distinguished by its outwardly supernatural manifestations which is merely a subtle divergence from the fabric of your own reality.","Why have I been brought here?", "Supernatural manifestations?"},
        //node4
        {"Though we reside in two distinct worlds, we are but threads woven by the same divine hand, guided by the same celestial compass. I have have been watching over you, protecting you from evil until it became to big a task. It was time for you to save yourself.","Evil? What kind of evil?", "Who is this divine hand?"},
        //node5
        {"You have been summoned to this realm due to the encroaching shadow of Evil that now engulfs your world, rendering it unsafe. Here, you are tasked with unlocking the pathways to successive universes until you locate her, the revered Queen of Heaven.", "What should I do now?", "Encroaching shadow of evil?"},
        //node6
        {"In our distinct worlds, we are threads woven by the same divine hand, guided by a celestial compass toward our destinies. I've been your guardian, warding off encroaching darkness until the weight became too much. Now, it's time for you to ascend and safeguard your own path.", "What should I do now?","Where am I being guided?"},
        //node 7
        {"You have been summoned to this realm due to the encroaching shadow of Evil that now engulfs your world, rendering it unsafe. Here, you are tasked with unlocking the pathways to successive universes until you locate her, the revered Queen of Heaven.", "What should I do now?", "Who is the queen of heaven?"},
        //node 8
        {"Yes. In the grand design of existence, characters within this universe serve as guardian angels to counterparts in your world. I, as your celestial guide, possess glimpses into realms beyond your current sight. Each of us has our own overseers, yet their identities remain shrouded in mystery.","Why am I here?","Where are you guiding me?"},
        //node 9
        {"The Evil that grips your world is not merely a force external but has insidiously crept into the souls of ordinary beings, corrupting their hearts and minds. It manifests in the form of greed, hatred, and the pursuit of power at the cost of virtue. The battle against this darkness is not just physical but spiritual, a test of faith and righteousness.","Why was I chosen to defeat this evil?","How do I win this battle?"},
        //node 10
        {"The divine hand I speak of is that of the Creator, the Almighty, who shapes destinies and guides souls along their paths. Follow your heart, for it is attuned to the whispers of divine guidance. The Queen of Heaven, representing the embodiment of grace and wisdom, is also your steadfast guide.","What should I do now?","Where am I being guided?"},
        //node 11
        {"To emerge victorious in this struggle, you must embark on a profound odyssey that transcends not just this realm but potentially extends through subsequent worlds, each reflecting the spiritual trials of humanity. Your mission is to discover the Queen of Heaven, embodying divine wisdom and grace. Look not only within but also beyond, engaging in dialogues with others, exploring the preserved knowledge in the library, and seeking solace and guidance at the church. Let your heart, guided by faith and righteousness, be your guiding light on this quest.","Thank You","Who is this Queen of Heaven?"},
        //node 12
        {"The Evil that grips your world is not merely a force external but has insidiously crept into the souls of ordinary beings, corrupting their hearts and minds. It manifests in the form of greed, hatred, and the pursuit of power at the cost of virtue. The battle against this darkness is not just physical but spiritual, a test of faith and righteousness.","Why was I chosen to defeat this evil?","How do I win this battle?"},
        //node 13 (yep, wxactly the same as 12, some are the same)
        {"The Evil that grips your world is not merely a force external but has insidiously crept into the souls of ordinary beings, corrupting their hearts and minds. It manifests in the form of greed, hatred, and the pursuit of power at the cost of virtue. The battle against this darkness is not just physical but spiritual, a test of faith and righteousness.","Why was I chosen to defeat this evil?","How do I win this battle?"},
        //node 14
        {"The divine hand I speak of is that of the Creator, the Almighty, who shapes destinies and guides souls along their paths. Follow your heart, for it is attuned to the whispers of divine guidance. The Queen of Heaven, representing the embodiment of grace and wisdom, is also your steadfast guide.","What should I do now?","Where am I being guided?"},
        //node 15
        {" OLD MAN:To emerge victorious in this struggle, you must embark on a profound odyssey that transcends not just this realm but potentially extends through subsequent worlds, each reflecting the spiritual trials of humanity. Your mission is to discover the Queen of Heaven, embodying divine wisdom and grace. Look not only within but also beyond, engaging in dialogues with others, exploring the preserved knowledge in the library, and seeking solace and guidance at the church. Let your heart, guided by faith and righteousness, be your guiding light on this quest. The Queen of Heaven awaits, her presence illuminating the path to triumph over darkness. Time is of the essence, young traveler. Hasten, for the fate of realms and souls hinges upon your virtuous endeavors.","",""},
        //node16
        {"I am but a speck of dust compared to her majesty. I will say you must find her to truly know all that she is. She is the epitome of divine wisdom and grace, and is forseeing your journey and arrival far more than I ever could. Go to her, for there isn't much time." },
        //node17
        {"You have been sent here to escape the Evil that engulfs your world. It is only the begining of your journey. You must embark on a profound journey, not just through this realm but potentially through subsequent worlds, which are a reflection of the spiritual challenges faced by humanity. Your quest is to find the Queen of Heaven, the embodiment of divine wisdom and grace.  Go on now, there isn't much time before its too late, the queen of heaven awaits your arrival.","",""},
        //node18
        {"I have only guided you here. After this, you must guide yourself. Your individual wisdom can show you things that I cannot. Engage in conversations beyond yourself, seek knowledge in the library, find solace at the church. Let faith and righteousness guide your heart; the Queen of Heaven awaits as your guiding light. Time is pressing, young traveler. The fate of realms and souls rests upon your righteous deeds. You must hurry.","",""},
        //node19
        {"You have been chosen because within you lies the potential for great virtue and strength of spirit. Your heart is pure, your intentions noble. The divine providence has deemed you worthy to embark on this sacred quest, for it is through your courage, faith, and righteousness that the tide of darkness may be turned. You are the beacon of hope in a world besieged by shadows, destined to bring forth the light of redemption and salvation. Go on now, there isn't much time before its too late, the queen of heaven awaits your arrival. ","",""},
        //node20
        {"To triumph in this battle, you must embark on a profound journey, not just through this realm but potentially through subsequent worlds, which are a reflection of the spiritual challenges faced by humanity. Your quest is to find the Queen of Heaven, the embodiment of divine wisdom and grace. Seek not only within yourself but also beyond, engaging in conversations with others, delving into the knowledge preserved in the library, and seeking solace and guidance at the church. Your heart, guided by faith and righteousness, is your beacon in this journey. The Queen of Heaven awaits, her presence a guiding light leading you to victory over darkness. Time is of the essence, young traveler. Hurry, for the destiny of realms and souls rests upon your righteous actions.","",""},
        //node21
        {"You have been sent here to escape the Evil that engulfs your world. It is only the begining of your journey. You must embark on a profound journey, not just through this realm but potentially through subsequent worlds, which are a reflection of the spiritual challenges faced by humanity. Your quest is to find the Queen of Heaven, the embodiment of divine wisdom and grace.  Go on now, there isn't much time before its too late, the queen of heaven awaits your arrival. ","",""},
        //node22
        {"I have only guided you here. After this, you must guide yourself. Your individual wisdom can show you things that I cannot. Engage in conversations beyond yourself, seek knowledge in the library, find solace at the church. Let faith and righteousness guide your heart; the Queen of Heaven awaits as your guiding light. Time is pressing, young traveler. The fate of realms and souls rests upon your righteous deeds. You must hurry.","",""},
        //node23
        {"It is my pleasure, courageous one. The Queen of Heaven awaits, her presence illuminating the path to triumph over darkness. Time is of the essence, young traveler. Hasten, for the fate of realms and souls hinges upon your virtuous endeavors.","",""},
        //node24
        {"I am but a speck of dust compared to her majesty. I will say you must find her to truly know all that she is. She is the epitome of divine wisdom and grace, and is forseeing your journey and arrival far more than I ever could. Go to her, for there isn't much time.","","" },
        //node25
        {"You have been chosen because within you lies the potential for great virtue and strength of spirit. Your heart is pure, your intentions noble. The divine providence has deemed you worthy to embark on this sacred quest, for it is through your courage, faith, and righteousness that the tide of darkness may be turned. You are the beacon of hope in a world besieged by shadows, destined to bring forth the light of redemption and salvation. Go on now, there isn't much time before its too late, the queen of heaven awaits your arrival. ","",""},
        //node26
        {"To triumph in this battle, you must embark on a profound journey, not just through this realm but potentially through subsequent worlds, which are a reflection of the spiritual challenges faced by humanity. Your quest is to find the Queen of Heaven, the embodiment of divine wisdom and grace. Seek not only within yourself but also beyond, engaging in conversations with others, delving into the knowledge preserved in the library, and seeking solace and guidance at the church. Your heart, guided by faith and righteousness, is your beacon in this journey. The Queen of Heaven awaits, her presence a guiding light leading you to victory over darkness. Time is of the essence, young traveler. Hurry, for the destiny of realms and souls rests upon your righteous actions.","",""},
        //node27
        {"You have been chosen because within you lies the potential for great virtue and strength of spirit. Your heart is pure, your intentions noble. The divine providence has deemed you worthy to embark on this sacred quest, for it is through your courage, faith, and righteousness that the tide of darkness may be turned. You are the beacon of hope in a world besieged by shadows, destined to bring forth the light of redemption and salvation. Go on now, there isn't much time before its too late, the queen of heaven awaits your arrival. ","",""},
        //node28
        {"To triumph in this battle, you must embark on a profound journey, not just through this realm but potentially through subsequent worlds, which are a reflection of the spiritual challenges faced by humanity. Your quest is to find the Queen of Heaven, the embodiment of divine wisdom and grace. Seek not only within yourself but also beyond, engaging in conversations with others, delving into the knowledge preserved in the library, and seeking solace and guidance at the church. Your heart, guided by faith and righteousness, is your beacon in this journey. The Queen of Heaven awaits, her presence a guiding light leading you to victory over darkness. Time is of the essence, young traveler. Hurry, for the destiny of realms and souls rests upon your righteous actions.","",""},
        //node29
        {"You have been sent here to escape the Evil that engulfs your world. It is only the begining of your journey. You must embark on a profound journey, not just through this realm but potentially through subsequent worlds, which are a reflection of the spiritual challenges faced by humanity. Your quest is to find the Queen of Heaven, the embodiment of divine wisdom and grace.  Go on now, there isn't much time before its too late, the queen of heaven awaits your arrival. ","",""},
        //node30
        {"I have only guided you here. After this, you must guide yourself. Your individual wisdom can show you things that I cannot. Engage in conversations beyond yourself, seek knowledge in the library, find solace at the church. Let faith and righteousness guide your heart; the Queen of Heaven awaits as your guiding light. Time is pressing, young traveler. The fate of realms and souls rests upon your righteous deeds. You must hurry.","",""},
       
    };
    
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
    shop market("Local Market", "market", noNpc, woodenSword, woodenAxe, chainmailArmor, smallHealPotion, ruby);
    shop smithy("Local Smithy", "smithy", noNpc, noWeapon, noWeapon, noArmor, noPotion, noItem);
    shop farm("Farm", "farm", noNpc, noWeapon, noWeapon, noArmor, noPotion, noItem);
    shop armory("Town Armory", "armory", noNpc, noWeapon, noWeapon, noArmor, noPotion, noItem);
    shop apothecary("Apprentice Wizard's Apothecary", "apothecary", apprenticeWizard, noWeapon, noWeapon, noArmor, noPotion, noItem);
    shop SHOPS[5] = {};

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
    wilderness WILDERNESS_REALM1[5] = {forest, desert, valley, iceland, jungle};
    wilderness WILDERNESS_REALM2 = {};

    //villages
    village village1;
    village village2;
    village village3;
    village village4;
    village village5;
    village VILLAGES_REALM1[5] = {village1, village2, village3, village4, village5};

    //MAIN GAME: GENERATE MENUS
    startMenu startScreen;
    playerMenu playerMenu;

    //MAIN GAME: GENERATE MISC. VARIABLES
    int sentinel = 0;

    //MAIN GAME: START MENU LOOP
    
    //loop to prevent erroneous choice
    while (sentinel != 1) {
        //start menu music
        PlaySound(MAKEINTRESOURCE(START_MENU_MUSIC), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);
        //clear console
        system("CLS");
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
            playerInventory testInventory(noWeapon, noArmor, noPotion, 0, noItem, noItem, noItem, 10000);
            player testPlayer("Dev", testInventory);
            map testMap(8);
            testMap.generateMap(WILDERNESS_REALM1, VILLAGES_REALM1, testPlayer);
            test.testLoop(userChoice, testPlayer, testMap, playerMenu, shadowyManDialogue);
        }
        //EXIT GAME FROM START MENU: 
        else if (userChoice == 4) {
            system("CLS");
            std::cout << "GOODBYE." << std::endl;
            exit(3);
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
    playerInventory playerInventory(strongTestWeapon, noArmor, noPotion, 0, noItem, noItem, noItem, 100); //!FIXME: REMOVE STRONG TEST WEAPON FOR FINAL PRODUCT
    player player(playerName, playerInventory);

    //MAIN GAME: GENERATE MAP
    map gameMap(5);
    gameMap.generateMap(WILDERNESS_REALM1, VILLAGES_REALM1, player);

    //MAIN GAME: INITIATE INTRO SEQUENCE AND MONOLOGUE

    //MAIN GAME: MAIN GAME LOOP
    sentinel = 0;
    while (sentinel != 1) {
        //!FIXME: QUIT GAME FEATURE, ARE YOU SURE? RETURNS SENTINEL VALUE OF 1.
        //!FIXME: IF CHARACTER FALLS THEY CAN EITHER GO BACK TO THE LAST CHURCH OR QUIT GAME
        gameMap.execLocation(player);
    }
    
    return 0;
}

/*
* !FIXME LIST:
* -------------------------------------------------------------------------------------------------------------------------------------------
* POTIONS FUNCTIONALITY/TRANSFER POTIONCOUNT TO POTION CLASS RATHER THAN INVENTORY
* ASK TYLER IF IT WOULD BE BETTER TO MAKE EVERYTHING PASSED BY REFERENCE AND POINTERS INSTEAD OF EQUALITIES
* CHECK DEFAULT CONSTRUCTORS, MAY NOT HAVE TO INITALIZE WEAPONS IN INVENTORY... THEY DEFUALT TO EMPTY!
* GRAPHICS DISPLAY FOR ENTERING A NEW VILLAGE OR WILDERNESS
* REVAMP BATTLE SEQUENCE TO LOOK MORE APPEALING, SEE IF YOU CAN ADD SOUND EFFECTS
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