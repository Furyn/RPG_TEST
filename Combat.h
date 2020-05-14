#pragma once

class Player;
class Character;
class UI;

class Combat
{
public:
	Player* player;
	Character* enemie;
	bool fightInProgress = false;
	bool fightIsEnd = false;
	bool turnPlayer = false;

	float timerBeetweenTwoActions = 1.0f;
	float timerForNextAction = 1.0f;
	float timerScreenEnd = 2.0f;

public:
	Combat(Player* _player);
	void StartCombatWith(Character* _enemie);
	void UpdateTimeCombat(float deltaTime);
	void UpdateCombat(UI* ui);
	bool checkForWin();
	bool checkForLose();
	void EnemiAttaque(UI* ui);
};