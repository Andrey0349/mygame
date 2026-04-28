#ifndef PLAYER_H
#define PLAYER_H

#include "ICombat.h"

class Player : public ICombat {
private:
    int baseDamage;
    int baseHealth;
    float baseCritChance;
    float baseCritDamage;

public:
    Player(int id = 0, const std::string& name = "Player");
    
    void setBaseDamage(int dmg);
    void setBaseHealth(int hp);
    void setBaseCrit(float ch, float cd);
    void setDefaultStats();
    
    int getBaseDamage() const { return baseDamage; }
    int getBaseHealth() const { return baseHealth; }
    
    int getTotalDamage() override;
    int getTotalHealth() override;
    float getTotalCritChance() override;
    float getTotalCritDamage() override;
    void takeDamage(int damage) override;
    void printStats() override;
    void printDetailedInfo() override;
    
    void resetToDefault();
};

#endif