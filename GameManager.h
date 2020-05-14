#pragma once
#include "UI.h"
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Combat.h"

class GameManager
{
public:
	UI* ui;
	Player* player;
	Combat* combat;
	sf::RenderWindow* window;
	sf::Font* fontOftext;

	float totalTime = 0;
	float deltaTime = 0;

public :
	GameManager(Player* player, sf::RenderWindow* _window, std::string fontForText);
	void TurnoOnAffichageStatsPlayer();
	void TurnoOffAffichageStatsPlayer();
	void CheckFotTurnPlayer();
	void CheckOnClickButton();

	void UpdateTime(float _deltaTime);
	void UpdateGame(sf::Vector2f mousePos);
	void DisplayGame();
	void DestroyGame();
};

