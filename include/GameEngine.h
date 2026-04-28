#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Player.h"
#include "Weapon.h"

class gameEngine {
private:
    Player players[2];
    Weapon Weapons[4];

    void initializePlayers();
    void initializeWeapons();
    void clearScreen();
    void waitForEnter();

public:
    gameEngine();

    void runMainMenu();
    void showPlayerMenu(int playerIndex);
    void showWeaponMenu(int weaponIndex);
    void startBattle();
    void getWinner();

    Player& getPlayer(int index);
    bool gameIsOver();
};

#endif