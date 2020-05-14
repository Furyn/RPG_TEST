#include "Combat.h"
#include <iostream>
#include "UI.h"
#include "Character.h"
#include "Player.h"

Combat::Combat(Player* _player) : player(_player), enemie(nullptr){}

void Combat::StartCombatWith(Character* _enemie)
{
	this->fightInProgress = true;
	this->fightIsEnd = false;
	this->turnPlayer = true;
	this->enemie = _enemie;
	this->timerScreenEnd = 2.0f;
	this->timerForNextAction = this->timerBeetweenTwoActions;
}

void Combat::UpdateTimeCombat(float deltaTime)
{
	this->timerForNextAction -= deltaTime;
	if (this->fightIsEnd) {
		this->timerScreenEnd -= deltaTime;
	}
}

void Combat::UpdateCombat(UI* ui)
{
	if (this->fightInProgress) {
		if (checkForWin()) {
			ui->AddTextOnCombatScreen("YOU WIN !");
		}
		else if (checkForLose()) {
			ui->AddTextOnCombatScreen("YOU LOSE !");
		}
		
		if (!this->turnPlayer && timerForNextAction <= 0.0f && !this->fightIsEnd ) {
			timerForNextAction = timerBeetweenTwoActions;
			this->EnemiAttaque(ui);
		}

		if (this->timerScreenEnd <= 0) {
			this->fightInProgress = false;
			delete this->enemie;
		}
	}
}

bool Combat::checkForWin()
{
	if (this->enemie != nullptr && this->enemie->life <= 0 && !this->fightIsEnd) {
		this->turnPlayer = false;
		this->fightIsEnd = true;
		return true;
	}
	return false;
}

bool Combat::checkForLose()
{
	if (this->player->life <= 0 && this->fightInProgress && !this->fightIsEnd) {
		this->turnPlayer = false;
		this->fightIsEnd = true;
		return true;
	}
	return false;
}

void Combat::EnemiAttaque(UI* ui)
{
	this->turnPlayer = true;
	int dommageEnemy = this->enemie->DommageOfNormaleAttaque();
	std::string textToDraw = "THE ENEMY USES NORMAL ATTACK !\n";
	if (dommageEnemy > 0) {
		if (this->enemie->coupCritique) {
			textToDraw += "CRITICAL STRIKE !\n";
		}
		textToDraw += "THE ENEMY HAS DAMAGED "+ std::to_string(this->player->TakeDommage(dommageEnemy)) +" POINTS.";
	}
	else {
		textToDraw += "MISSED ATTACK !";
	}
	ui->AddTextOnCombatScreen(textToDraw + "\n");
}
