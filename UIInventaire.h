#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "CaseInventaie.h"

class UIInventaire
{
public:
	sf::RectangleShape bordureInventaire;
	std::list<CaseInventaire*> listeCaseInventaire;

private:
	int nombreCaseInventaire = 48;
	int nombreCaseInLigne = 8;

public:
	UIInventaire(sf::Font* fontForText);
	void UpdatePosAllCase(float posX, float posY);
	void DisplayUi(sf::RenderWindow* window);
};

