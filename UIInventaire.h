#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "CaseInventaie.h"

class UIStats;
class GameManager;
class Inventaire;

class UIInventaire
{
public:
	sf::RectangleShape bordureInventaire;
	std::list<CaseInventaire*> listeCaseInventaire;
	UIStats* statsPlayer;

	CaseInventaire* casqueEquiper;
	CaseInventaire* plastronEquiper;
	CaseInventaire* gantEquiper;
	CaseInventaire* pantalonEquiper;
	CaseInventaire* botteEquiper;
	CaseInventaire* ArmeEquiper;

private:
	int nombreCaseInLigne = 5;

public:
	UIInventaire(sf::Font* fontForText);
	void UpdatePosAllCase(float posX, float posY);
	void UpdateUI(GameManager* game);
	void UpdatePos(float posX, float posY);
	void DisplayUi(sf::RenderWindow* window);
};

