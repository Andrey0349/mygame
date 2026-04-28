#ifndef ISTATS_H
#define ISTATS_H

class IStats {
protected:
    int damage;
    int health;
    float critChance;
    float critDamage;

public:
    IStats() : damage(0), health(0), critChance(0), critDamage(0) {}

    int getDamage() { return damage; }
    int getHealth() { return health; }
    float getCritChance() { return critChance; }
    float getCritDamage() { return critDamage; }

    void setDamage(int dmg) { damage = dmg; }
    void setHealth(int hp) { health = hp; }
    void setCritChance(float ch) { critChance = ch; }
    void setCritDamage(float cd) { critDamage = cd; }
};

#endif