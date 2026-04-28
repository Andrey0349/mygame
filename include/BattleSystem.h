#ifndef BATTLESYSTEM_H
#define BATTLESYSTEM_H

#include "Player.h"
#include <random>

class BattleSystem {
private:
    Player *players[2];
    int CurrentTurn;

    int getRandomFirstTurn();
    void switchTurn();
    int calculateDamage(int baseDamage, float critChance, float critDamage);
    void displayBattleStatus();
    int getPlayerAction(int playerIndex);
    int Attack(int actionType, Player& attacker, Player& defender);

public:
    BattleSystem();

    void startFight(Player& player1, Player& player2);
    bool isFightOver();
    Player* getWinner();
};

#endif