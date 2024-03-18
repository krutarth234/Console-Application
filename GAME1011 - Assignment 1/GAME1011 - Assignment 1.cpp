#include <iostream>
#include <vector>
#include <array>
#include <thread>

#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"


// Initialization of static variable must be done outside of class, because memory allocation needs to occur separately from the class definition.

class Wizard : public Player 
{
private:
    static std::string specialAttackName;
    int specialAttackAmount = 75;

public:
    int SpecialAttack() override 
    {
        std::cout << getPlayerName() << " performs " << specialAttackName << std::endl;
        return specialAttackAmount;
    }
};

std::string Wizard::specialAttackName = "SYMBIOTE"; // static member initialized

class Knight : public Player
{
private:
    static std::string specialAttackName;
    int specialAttackAmount = 75;

public:
    int SpecialAttack() override
    {
        std::cout << getPlayerName() << " performs " << specialAttackName << std::endl;
        return specialAttackAmount;
    }
};

std::string Knight::specialAttackName = "Hoffmann"; // static member initialized

class Orc : public Enemy
{
private:
    static std::string speciesName;
    std::array<std::string, 4> taunts{ "See ya chump!", "Gonna cry?", "You want forgiveness? Get religion!", "I am gonna put some dirt in your eye!" };
        
public:
    void TauntPlayer() override
    {
        std::cout << speciesName << ": ";
        std::cout << taunts[rand() % 4] << std::endl;
    }
};

std::string Orc::speciesName = "Bully Maguire";

class Undead : public Enemy
{
private:
    static std::string speciesName;
    std::array<std::string, 4> taunts{ "You don't wanna be famous? I'll make you Infamous!", "Looking for a raise? Get out!", "Crap, Crap, Crap, MEGA Crap!" , "Awww.. are you shy?"};
   
public:
    void TauntPlayer() override
    {
        std::cout << speciesName << ": ";
        std::cout << taunts[rand() % 4] << std::endl;
    }
};

std::string Undead::speciesName = "J. Jonah Jameson";



int main()
{
    Player* player = nullptr;
    Enemy* enemy = nullptr;
    std::string playerName;
    char playerType;
    char enemyType;

    // Welcome message for player
    std::cout << "                                   Welcome to Game of Choice                       " << std::endl;
    std::cout << std::endl;

    // Prompt player to enter name
    std::cout << "Enter your player name: ";
    std::cin >> playerName;
    std::cout << std::endl;
    
    // Prompt player to choose a character
    std::cout << "Press 1: If you want to play as Wizard!" << std::endl;
    std::cout << "Press 2: If you want to play as Knight!" << std::endl;
    std::cin >> playerType;
    std::cout << std::endl;

    // Create player based on player type
    if (playerType == '1') 
    {
        player = new Wizard;
    }
    else if(playerType == '2') 
    {
        player = new Knight;
    }

    // Set player's name
    player->setPlayerName(playerName);
    
    // Set player's health
    player->setPlayerHealth(100);
   

    // Provide a summary of the player information
    std::cout << "Name of the character: " << player->getPlayerName() << std::endl;
    if (playerType == '1')
    {
        std::cout << "Character type: Wizard" << std::endl;
    }
    else if (playerType == '2')
    {
        std::cout << "Character type: Knight" << std::endl;
    }
    std::cout << "Initial Health: " << player->getPlayerHealth() << std::endl;
    std::cout << std::endl;

    //                                              ENEMY                                   

    // Prompt player to choose an enemy
    std::cout << "Press 3: To fight with an Orc!" << std::endl;
    std::cout << "Press 4: To fight with an Undead!" << std::endl;
    std::cin >> enemyType;
    std::cout << std::endl;

    // Create an enemy based on player's preference
    if (enemyType == '3')
    {
        enemy = new Orc;
    }
    else if (enemyType == '4')
    {
        enemy = new Undead;
    }
    
    // Set enemy's health
    enemy->setEnemyHealth(200);

    // Provide a summary of the enemy information
    if (enemyType == '3')
    {
        std::cout << "Name of your enemy: " << "Bully Maguire" << std::endl;
        std::cout << "Enemy type: Orc Species" << std::endl;
    }
    else if (enemyType == '4')
    {
        std::cout << "Name of your enemy: " << "J. Jonah Jameson" << std::endl;
        std::cout << "Enemy type: Undead Species!" << std::endl;
    }
    std::cout << "Initial Health: " << enemy->getEnemyHealth() << std::endl;
    std::cout << std::endl;

    // Ask the user if they are ready to witness a battle
    
    char response;
    std::cout << "Press Y: To witness battle! ";
    std::cin >> response;
    response = toupper(response);
    std::cout << std::endl;
    std::cout << "                          Battle starts!                      " << std::endl;
    std::cout << std::endl;
    
    //                                                  BATTLE                              
    std::cout << " ---------------------------ROUND 1------------------------" << std::endl;
    // Enemy will taunt the player
    enemy->TauntPlayer();

    // Player performs a normal attack
    enemy->setEnemyHealth(enemy->getEnemyHealth() - player->NormalAttack());

    // Enemy will taunt the player
    enemy->TauntPlayer();

    // Player performs a special attack
    enemy->setEnemyHealth(enemy->getEnemyHealth() - player->SpecialAttack());

    // Enemy performs normal attack
    player->setPlayerHealth(player->getPlayerHealth() - enemy->NormalAttack());

    std::cout << std::endl;
    std::cout << "                        HEALTH after Round 1                " << std::endl;
    std::cout << std::endl;

    // Display health
    std::cout << player->getPlayerName() << "'s health: " << player->getPlayerHealth() << std::endl;
    std::cout << "Enemy's health: " << enemy->getEnemyHealth() << std::endl;
    std::cout << std::endl;


    //                                              ROUND 2     
    std::cout << " ---------------------------ROUND 2------------------------" << std::endl;
    // Enemy performs normal attack
    player->setPlayerHealth(player->getPlayerHealth() - enemy->NormalAttack());

    // Player performs special attack
    enemy->setEnemyHealth(enemy->getEnemyHealth() - player->NormalAttack());

    // Enemy taunts the player
    enemy->TauntPlayer();

    // Player performs special attack
    enemy->setEnemyHealth(enemy->getEnemyHealth() - player->SpecialAttack());

    // Enemy dies
    std::cout << "Enemy dies!" << std::endl;

    std::cout << std::endl;
    std::cout << "                       HEALTH after Round 2                " << std::endl;
    std::cout << std::endl;

    // Display health
    std::cout << player->getPlayerName() << "'s health: " << player->getPlayerHealth() << std::endl;
    std::cout << "Enemy's health: " << enemy->getEnemyHealth() << std::endl;

    // Win message
    std::cout << "--------------------------WIN MESSAGE-------------------------------" << std::endl;
    std::cout << "Are kaun bhaukh rha tha wo batameeez!" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

 
    // The build exception problem was that when user entered the response, the build was terminated and there were no
    // Additional commands or processes to keep the WINDOW OPEN!!
    // The error was not in the code.

    // Solution: let's introduce something that prevents window from closing before printing out the whole message
   

    // Wait for user input before exiting
    std::cout << "Press any key to exit...";
    std::cin.ignore();
    std::cin.get(); 


    // Delete dynamically allocated memory
    delete player;
    delete enemy;

    return 0;
}
