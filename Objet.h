#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

enum class CATEGORIE_OBJET
{
	POTION_VIE,
	POTION_MANA,
	EQUIPEMENT_PLASTRON,
	EQUIPEMENT_CASQUE,
	EQUIPEMENT_GANT,
	EQUIPEMENT_PANTALON,
	EQUIPEMENT_BOTTE,
	EQUIPEMENT_ARME
};

class EffetEquipement;

class Objet
{
public:
	std::string name;
	CATEGORIE_OBJET category;
	EffetEquipement* effets;

	int maxQuantityInInventory;
	int quantityInInventory;

	sf::CircleShape circle;

public:
	Objet(std::string name, CATEGORIE_OBJET category, int maxManaBonus, int maxLifeBonus, int forceBonus, int criticalBonus, int armorBonus, int intelligenceBonus, int luckBonus);
	void Display(sf::RenderWindow* window);
	void UpdatePosToDisplay(float posX, float posY);
};

