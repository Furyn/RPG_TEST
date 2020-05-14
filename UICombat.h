#pragma once
#include <SFML/Graphics.hpp>
#include <list>

class Button;

class UICombat
{
public:
	sf::RectangleShape rectOfAllText;
	std::list<sf::Text*> listAllTextToDisplay;
	sf::Font* fontForText;

	bool afficherOptionsCombats = false;
	std::map<std::string, Button*> listAllButton;

public:
	UICombat(sf::Font* fontForText);
	void AddText(std::string textToAdd);
	void RemoveFirstText();
	void RemoveAllText();

	void UpdatePosUi(sf::RenderWindow* window, float posX, float posY);
	void DisplayUi(sf::RenderWindow* window);
};

