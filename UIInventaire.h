#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "CaseInventaie.h"

class UIStats;
class GameManager;

class UIInventaire
{
public:
	sf::RectangleShape bordureInventaire;
	std::list<CaseInventaire*> listeCaseInventaire;
	UIStats* statsPlayer;

private:
	int nombreCaseInventaire = 48;
	int nombreCaseInLigne = 8;

public:
	UIInventaire(sf::Font* fontForText);
	void UpdatePosAllCase(float posX, float posY);
	void UpdateUI(GameManager* game);
	void UpdatePos(float posX, float posY);
	void DisplayUi(sf::RenderWindow* window);
};

