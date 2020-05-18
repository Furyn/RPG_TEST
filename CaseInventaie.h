#pragma once
#include <SFML/Graphics.hpp>

class Objet;
class GameManager;

class CaseInventaire
{
public:
	sf::RectangleShape contoureCase;
	Objet* objetInCase;
	bool (*pFunctionToExecuteOnClick)(GameManager*,Objet*);

	bool onHover = false;
	bool isVisible = false;

public:
	CaseInventaire();
	void UpdatePose(float posX, float posY);
	void CheckOnHover(sf::Vector2f positionMouse);
	void OnClick(GameManager* game, Objet* objetToEquipe);
	void Display(sf::RenderWindow* window);
};

