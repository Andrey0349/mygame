#include "Player.h"
#include <iostream>
#include <algorithm>

Player::Player(int id, const std::string& name) 
    : baseDamage(0), baseHealth(0), baseCritChance(0), baseCritDamage(0) {
    this->id = id;
    this->name = name;
    equippedWeapon = nullptr;
    setDefaultStats();
}

void Player::setDefaultStats() {
    baseDamage = 100;
    baseHealth = 1000;
    baseCritChance = 40;
    baseCritDamage = 150;
}

int Player::getTotalDamage() {
    int total = baseDamage;
    if (equippedWeapon != nullptr) {
        total += equippedWeapon->getDamage();
    }
    return total;
}

int Player::getTotalHealth() {
    return baseHealth;
}

float Player::getTotalCritChance() {
    return baseCritChance;
}

float Player::getTotalCritDamage() {
    return baseCritDamage;
}

void Player::takeDamage(int damage) {
    baseHealth -= damage;
    if (baseHealth <= 0) baseHealth = 0;
}

void Player::setBaseDamage(int dmg) {
    baseDamage = dmg;
}

void Player::setBaseHealth(int hp) {
    baseHealth = (hp < 0) ? 0 : hp;
}

void Player::setBaseCrit(float ch, float cd) {
    baseCritChance = ch;
    baseCritDamage = cd;
}

void Player::printStats() {
    std::cout << "HP: " << getTotalHealth() << "\t"
              << "DMG: " << getTotalDamage() << "\t"
              << "CRIT CH: " << getTotalCritChance() << "%\t"
              << "CRIT DMG: " << getTotalCritDamage() << "%\n";
}

void Player::printDetailedInfo() {
    std::cout << "\n=== ИГРОК " << name << " ===\n"
              << "ID: " << id << "\n"
              << "Базовые характеристики:\n";
    std::cout << "  HP: " << baseHealth << "\n"
              << "  DMG: " << baseDamage << "\n"
              << "  Crit Chance: " << baseCritChance << "%\n"
              << "  Crit DMG: " << baseCritDamage << "%\n";
    
    if (equippedWeapon != nullptr) {
        std::cout << "\nЭкипировано оружие: " << equippedWeapon->getName() << "\n"
                  << "  Бонус HP: +" << equippedWeapon->getHealth() << "\n"
                  << "  Бонус DMG: +" << equippedWeapon->getDamage() << "\n";
    }
    
    std::cout << "\nИТОГОВЫЕ ХАРАКТЕРИСТИКИ:\n";
    printStats();
}

void Player::resetToDefault() {
    baseDamage = 100;
    baseHealth = 1000;
    baseCritChance = 40;
    baseCritDamage = 150;
    equippedWeapon = nullptr;
}