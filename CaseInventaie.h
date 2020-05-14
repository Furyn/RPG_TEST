#pragma once
#include <SFML/Graphics.hpp>

class Objet;

class CaseInventaire
{
public:
	sf::RectangleShape contoureCase;
	Objet* objetInCase;

public:
	CaseInventaire();
	void UpdatePose(float posX, float posY);
	void Display(sf::RenderWindow* window);
};

