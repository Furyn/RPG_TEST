#pragma once
#include<SFML/Graphics.hpp>
#include <map>
#include "UIStats.h"
#include "UICombat.h"
#include "UIInventaire.h"

class GameManager;

class UI
{
public:

	//UI Affichage stats player
	sf::RectangleShape rectDisplayArea;
	sf::Text nameClasse;
	sf::Text textLife;
	sf::Text textMana;

	UIStats* statsEnemi;
	bool afficherStatsPlayer = false;

	//UI Affichage du text en combats
	UICombat* combat;

	//UI Affichage de l'inventaire
	UIInventaire* inventaire;
	bool afficherInventairePlayer = false;
	bool waitKeyReleasedInventaire = false;

public:
	UI(sf::Font* fontForText);
	void UpdateUI(GameManager* game);
	void CheckHoverButton(sf::Vector2f positionMouse, GameManager* game);
	void AddTextOnCombatScreen(std::string textToAdd);
	void ClearTextOnCombatScreen();
	void UpdatePosUi(sf::RenderWindow* window);
	void DisplayUi(sf::RenderWindow* window, bool fightInProgress);
};

