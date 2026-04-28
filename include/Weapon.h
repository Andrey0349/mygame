#ifndef WEAPON_H
#define WEAPON_H

#include "IStats.h"
#include <string>

using namespace std;

class Weapon : public IStats {
protected:
    int id;
    string name;

public:
    Weapon(int id = 0, const string& name = "unknown");

    int getId() { return id; }
    string getName() { return name; }

    void setId(int newId) { id = newId; }
    void setName(string& newName) { name = newName; }

    void generateRandomStats(int minDmg, int maxDmg, int minHp, int maxHp);
    void printInfo();
};

#endif