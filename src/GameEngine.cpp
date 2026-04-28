#include "GameEngine.h"
#include "BattleSystem.h"
#include <iostream>

gameEngine::gameEngine() {
    initializePlayers();
    initializeWeapons();
}

void gameEngine::initializePlayers() {
    players[0] = Player(1, "Игрок 1");
    players[1] = Player(2, "Игрок 2");
}

void gameEngine::initializeWeapons() {
    Weapons[0] = Weapon(1, "Меч");
    Weapons[1] = Weapon(2, "Топор");
    Weapons[2] = Weapon(3, "Посох");
    Weapons[3] = Weapon(4, "Лук");

    for (int i = 0; i < 4; i++) {
        Weapons[i].generateRandomStats(10, 50, 50, 200);
    }
}

void gameEngine::clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void gameEngine::waitForEnter() {
    cout << "Нажмите Enter для продолжения...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void gameEngine::showWeaponMenu(int PlayerIndex) {
    Player &player = players[PlayerIndex];

    while(true) {
        clearScreen();
        cout << "\n=== ИНВЕНТАРЬ ОРУЖИЯ ===\n";
        cout << "ID\tDMG\tHP\tНазвание\n";
        for (int i = 0; i < 4; i++) {
            cout << i << ". ";
            Weapons[i].printInfo();
        }

        cout << "\n4. Снять оружие\n"
                  << "5. Назад\n"
                  << "Выбери действие (0-5): ";
        
        int choice;
        cin >> choice;

        if (choice >= 0 && choice < 4) {
            player.equipWeapon(Weapons[choice]);
            cout << "\nОружие экипировано!\n";
            waitForEnter();
        } else if (choice == 4) {
            player.unequipWeapon();
            cout << "\nОружие снято!\n";
            waitForEnter();
        } else if (choice == 5) {
            break;
        } else {
            cout << "\nОшибка! Попробуй снова!\n";
            waitForEnter();
        }
    }
}

void gameEngine::showPlayerMenu(int playerIndex) {
    Player &player = players[playerIndex];

    while (true) {
        cout << "\n=== МЕНЮ ИГРОКА " << player.getName() << " ===\n"
            << "0. Информация об игроке\n"
            << "1. Полная статистика\n"
            << "2. Переименовать\n"
            << "3. Оружие\n"
            << "4. Сбросить характеристики\n"
            << "5. Назад\n"
            << "Выбери действие (0-5): ";

        int choice;
        cin >> choice;
        
        string newName;

        switch(choice) {
            case 0:
            clearScreen();
            player.printDetailedInfo();
            waitForEnter();
            break;

            case 1:
            clearScreen();
            player.printStats();
            waitForEnter();
            break;

            case 2:
            clearScreen();
            cout << "Введите новое имя: ";
            cin >> newName;
            player.setName(newName);
            cout << "Имя изменено на: " << player.getName() << "\n";
            waitForEnter();
            break;

            case 3:
            showWeaponMenu(playerIndex);
            break;

            case 4:
            clearScreen();
            player.resetToDefault();
            cout << "Характеристики сброшены до стандартных!\n";
            waitForEnter();
            break;

            case 5:
            return;

            default:
            cout << "\nОшибка! Попробуй снова!\n";
            waitForEnter();
        }
    }
}

void gameEngine::startBattle() {
    clearScreen();
    BattleSystem battle;
    battle.startFight(players[0], players[1]);
}

void gameEngine::getWinner() {
    clearScreen();
    if (players[0].isAlive() && !players[1].isAlive()) {
        std::cout << "\n============================================\n";
        std::cout << "          ПОБЕДИТЕЛЬ: " << players[0].getName() << "!\n";
        std::cout << "============================================\n";
    } else if (!players[0].isAlive() && players[1].isAlive()) {
        std::cout << "\n============================================\n";
        std::cout << "          ПОБЕДИТЕЛЬ: " << players[1].getName() << "!\n";
        std::cout << "============================================\n";
    }
}

bool gameEngine::gameIsOver() {
    return !players[0].isAlive() || !players[1].isAlive();
}

Player& gameEngine::getPlayer(int index) {
    return players[index];
}

void gameEngine::runMainMenu() {
    while (true) {
        clearScreen();
        cout << "\n========== ГЛАВНОЕ МЕНЮ ==========\n"
                  << "0. Начать битву (PvP)\n"
                  << "1. Настроить ИГРОКА 1\n"
                  << "2. Настроить ИГРОКА 2\n"
                  << "3. Посмотреть статистику игроков\n"
                  << "4. Выйти из игры\n"
                  << "===================================\n"
                  << "Выбери действие (0-4): ";
        
        int choice;
        cin >> choice;

        switch(choice) {
            case 0:
            startBattle();
            if (gameIsOver()) {
                getWinner();
                cout << "\nИгра окончена!\n";
                waitForEnter();
                return;
            }
            break;

            case 1:
            showPlayerMenu(0);
            break;

            case 2:
            showPlayerMenu(1);
            break;

            case 3:
            clearScreen();
            cout << "\n=== ТЕКУЩАЯ СТАТИСТИКА ИГРОКОВ ===\n";
            cout << "\n" << players[0].getName() << ":\n";
            players[0].printStats();
            cout << "\n" << players[1].getName() << ":\n";
            players[1].printStats();
            waitForEnter();
            break;

            case 4:
            cout << "\nВыход...\n";
            waitForEnter();
            return;

            default:
            cout << "\nОшибка! Попробуй снова!\n";
            waitForEnter();
        }
    }
}

