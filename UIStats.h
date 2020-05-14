#pragma once
#include <SFML/Graphics.hpp>

class Character;

class UIStats
{
public:
	sf::RectangleShape rectDisplayArea;
	sf::Text nameClasse;
	sf::Text textLife;
	sf::Text textForce;
	sf::Text textDexterity;
	sf::Text textArmor;
	sf::Text textIntelligence;
	sf::Text textMana;
	sf::Text textLuck;

public:
	UIStats(sf::Font* fontForText);
	void UpdateTextUI(Character* character);
	void UpdatePosUi(float posX, float posY);
	void DisplayUi(sf::RenderWindow* window, bool afficherAllStats);
};

