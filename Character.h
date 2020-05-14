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
	int life; //le personnage meurt quand n�gatif ou nul
	int force; //pour calculer les d�g�ts
	int critical; //pour d�terminer si le coup est critique (d�g�ts x2)
	int armor; //r�duit les d�g�ts re�us
	int intelligence; //pour calculer les d�g�ts magiques
	int mana; //n�cessaire pour faire des d�g�ts magique
	int luck; //chance de gagner des items plus puissant en pourcentage

	bool coupCritique = false;



public:
	Character(std::string _name, ClassCharacter _classCharacter);
	int DommageOfNormaleAttaque();
	int DommageOfDesperateAttaque();
	int DommageOfMagiqueAttaque();
	int TakeDommage(int dommage);
};