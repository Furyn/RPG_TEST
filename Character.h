#pragma once
#include <iostream>
#include <stdlib.h>

enum class ClassCharacter
{
	Warrior, Mage, Priest, Assassin, Ranger, Knight
};

class Character
{
public:
	std::string name;
	ClassCharacter classCharacter;
	int maxMana; //le niveau max de mana que peut avoir le character
	int maxLife; //le niveau max de point de vie que peut avoir le character
	int life; //le personnage meurt quand négatif ou nul
	int force; //pour calculer les dégâts
	int critical; //pour déterminer si le coup est critique (dégâts x2)
	int armor; //réduit les dégâts reçus
	int intelligence; //pour calculer les dégâts magiques
	int mana; //nécessaire pour faire des dégâts magique
	int luck; //chance de gagner des items plus puissant en pourcentage

	bool coupCritique = false;



public:
	Character(std::string _name, ClassCharacter _classCharacter);
	int DommageOfNormaleAttaque();
	int DommageOfDesperateAttaque();
	int DommageOfMagiqueAttaque();
	int TakeDommage(int dommage);
};