#ifndef ICOMBAT_H
#define ICOMBAT_H

#include "Weapon.h"
#include <string>

using namespace std;

class ICombat {
    protected:
    int id;
    string name;
    Weapon *equippedWeapon;

    public:
    ICombat() : equippedWeapon(nullptr), id(0), name("Unknown") {}
    virtual ~ICombat() {}
    
    virtual int getTotalDamage() = 0;
    virtual int getTotalHealth() = 0;
    virtual float getTotalCritChance() = 0;
    virtual float getTotalCritDamage() = 0;
    virtual void takeDamage(int damage) = 0;
    virtual void printStats() = 0;
    virtual void printDetailedInfo() = 0;

    void equipWeapon(Weapon& weapon) {
        equippedWeapon = &weapon;
    }

    void unequipWeapon() {
        equippedWeapon = nullptr;
    }

    int getId() { return id; }
    string getName() { return name; }
    Weapon *getEquippedWeapon() { return equippedWeapon; }
    
    void setName(string newName) { name = newName; }
    void setId(int newId) { id = newId; }

    bool isAlive() { return getTotalHealth() > 0; }
};

#endif