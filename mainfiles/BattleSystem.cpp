#include "BattleSystem.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>

BattleSystem::BattleSystem() : CurrentTurn(0) {
    static bool seeded = false;
    if (!seeded) {
        srand(time(nullptr));
        seeded = true;
    }
}

int BattleSystem::getRandomFirstTurn() {
    return rand() % 2;
}

void BattleSystem::switchTurn() {
    CurrentTurn = (CurrentTurn == 0) ? 1 : 0;
}

int BattleSystem::calculateDamage(int baseDamage, float critChance, float critDamage) {
    int minDamage = baseDamage * 0.7;
    int maxDamage = baseDamage;
    int damage = minDamage + (rand() % (maxDamage - minDamage + 1));

    int critRoll = rand() % 100 + 1;
    if (critRoll <= critChance) {
        damage = damage * (critDamage / 100);
        cout << "КРИТИЧЕСКИЙ УРОН! ";
    }

    return damage;
}

void BattleSystem::displayBattleStatus() {
    cout << "\n===============================================\n";
    cout << players[0]->getName() << " [" << players[0]->getTotalHealth() << " HP]";
    cout << "  VS  ";
    cout << players[1]->getName() << " [" << players[1]->getTotalHealth() << " HP]";
    cout << "\n===============================================\n";
}

int BattleSystem::getPlayerAction(int playerIndex) {
    int choice;
    cout << "\n" << players[playerIndex]->getName() << ", твой ход!\n"
              << "1. Обычный удар (" << players[playerIndex]->getTotalDamage() << " урона)\n"
              << "2. Сильный удар (" << players[playerIndex]->getTotalDamage() * 2 << " урона)\n"
              << "Выбери действие: ";
    cin >> choice;
    return choice;
}

int BattleSystem::Attack(int actionType, Player& attacker, Player& defender) {
    int baseDamage = attacker.getTotalDamage();
    float critChance = attacker.getTotalCritChance();
    float critDamage = attacker.getTotalCritDamage();

    int damageMultiplier = (actionType == 1) ? 1 : 2;
    int calculatedDamage = calculateDamage(baseDamage * damageMultiplier, critChance, critDamage);

    defender.takeDamage(calculatedDamage);
    return calculatedDamage;
}

void BattleSystem::startFight(Player& player1, Player& player2) {
    players[0] = &player1;
    players[1] = &player2;

    CurrentTurn = getRandomFirstTurn();

    cout << "\n=== НАЧАЛО БИТВЫ === \n";
    cout << "Первый ход достаётся: " << players[CurrentTurn]->getName() << "!\n\n";

    while (!isFightOver()) {
        displayBattleStatus();

        Player *attacker = players[CurrentTurn];
        Player *defender = players[(CurrentTurn + 1) % 2];

        int action = getPlayerAction(CurrentTurn);

        if (action == 1 || action == 2) {
            int damage = Attack(action, *attacker, *defender);
            cout << "\n" << attacker->getName() << " наносит " << damage << " урона\n";
            cout << "у " << defender->getName() << " осталось " << defender->getTotalHealth() << " HP\n";

            if (defender->getTotalHealth() <= 0) {
                cout << "\n" << defender->getName() << " повержен!\n";
                break;
            }

        switchTurn();
        } else {
            cout << "\nОШИБКА! ВВЕДИ 1 ИЛИ 2!\n";
        }

        cout << "\nНажмите Enter для продолжения...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
   }
}

bool BattleSystem::isFightOver() {
    return (!players[0]->isAlive() || !players[1]->isAlive());
}

Player *BattleSystem::getWinner() {
    if (!players[0]->isAlive()) return players[1];
    if (!players[1]->isAlive()) return players[0];
    return nullptr;
}