#pragma once
#include <SFML/Graphics.hpp>

class GameManager;

class Button
{

public:
	sf::RectangleShape rectButton;
	sf::Text textButton;
	bool onHover = false;
	bool isVisible = false;

private:
	bool (*pFunctionToExecuteOnClick)(GameManager*); //pFunctionToExecute = POINTEUR D'UNE FUNCTION QUI A UN POINTEUR DE GAMEMANAGER EN PARAMETRE
	bool (*pFunctionToExecuteOnHover)(GameManager*);

private:
	sf::Color colorOutline;
	sf::Color colorFill;

public:
	Button(float widthButton, float heightButton, float posX, float posY, std::string textButton, float sizeCharacter, sf::Color colorOutline, sf::Color colorFill, sf::Font* fontForText, bool (*_pFunctionToExecuteOnCLick)(GameManager*), bool (*_pFunctionToExecuteOnHover)(GameManager*));
	void CheckOnHover(sf::Vector2f positionMouse);
	void OnHover(sf::Color colorOutline, sf::Color colorFill, GameManager* game);
	void UpdatePos(float posX, float posY);
	void DisplayButton(sf::RenderWindow* window);
	void OnClick(GameManager* game);
};

