#include "Weapon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Weapon::Weapon(int id, const string& name) : id(id), name(name) {
    setDamage(0);
    setHealth(0);
}

void Weapon::generateRandomStats(int minDmg, int maxDmg, int minHp, int maxHp) {
    static bool seeded = false;
        if (!seeded) {
        srand(time(nullptr));
        seeded = true;
    }
    
    int dmg = minDmg + (rand() % (maxDmg - minDmg + 1));
    int hp = minHp + (rand() % (maxHp - minHp + 1));
    
    setDamage(dmg);
    setHealth(hp);
}

void Weapon::printInfo() {
    cout << id << "\t"
        << getDamage() << "\t"
        << getHealth() << "\t"
        << name << "\n";
}