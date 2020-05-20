#pragma once
#include "Character.h"
#include "SFML/Graphics.hpp"

class Inventaire;

class Player : public Character
{
public :
	Inventaire* inventaire;
	sf::CircleShape circlePlayer;
	bool canMoveUp = true;
	bool canMoveDown = true;
	bool canMoveLeft = true;
	bool canMoveRight = true;

public:
	Player(std::string name,ClassCharacter _classCharacter);
	void UpdatePosPlayer(int posX, int posY);
	void Display(sf::RenderWindow* window);
};

