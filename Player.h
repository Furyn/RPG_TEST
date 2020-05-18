#pragma once
#include "Character.h"

class Inventaire;

class Player : public Character
{
public :
	Inventaire* inventaire;

public:
	Player(std::string name,ClassCharacter _classCharacter);
};

