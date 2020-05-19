#pragma once
#include <iostream>
#include <map>

using namespace std;

class Character;

class EffetEquipement
{
public:
	map<string, int>* listeEffet;

public:
	EffetEquipement(int maxManaBonus, int maxLifeBonus, int forceBonus, int criticalBonus, int armorBonus, int intelligenceBonus, int luckBonus);
	void ApplyEffet(Character* character);
	void RemoveEffet(Character* character);
};